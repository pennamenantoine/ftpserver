/*
** server.c for server in /home/pennam_a/Systeme_unix/PSU_2015_myftp/tp
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Thu May 12 21:26:47 2016 antoine pennamen
** Last update Sun May 15 23:54:20 2016 antoine pennamen
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include "server.h"

#define SIZE 100

int	do_bind(int fd, struct sockaddr_in s_in, int port)
{
  if (fd == -1)
    return (1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  if (listen(fd, 42) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  return (0);
}

void		check_buffer(char *buff, int client_fd, int i, int j)
{
  char		**tab;
  t_built	built[8] = {
    {"USER", &user},
    {"PASS", &pass},
    {"CWD", &cwd},
    {"CDUP", &cdup},
    {"QUIT", &quit},
    {"NOOP", &noop},
    {"PWD", &pwd},
    {"\0", NULL}
  };

  tab = str_to_wordtab(buff, 0, 0, 0);
  while (built[i].fct != NULL)
    {
      j = 0;
      while (tab[j] != NULL)
	{
	  if (strcmp(tab[j], built[i].str) == 0)
	    built[i].fct(tab, client_fd);
	  j++;
	}
      i++;
    }
}

int		fork_it(int client_fd)
{
  int		nb_read;
  char		buff[SIZE];



  while ((nb_read = read(client_fd, buff, SIZE)) > 0)
    {
      buff[nb_read] = '\0';
      bzero(buff, 0);
      check_buffer(buff, client_fd, 0, 0);
    }
  if (close(client_fd) == -1)
    return (1);
  return (0);
}

int		loop(int fd, int client_fd)
{
  pid_t		c;

  if (client_fd == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  write(client_fd,\
	"Connection Etablishment\n220 Service ready for new user.\r\n"	\
	, strlen("Connection Etablishment\n220 Service ready for new user.\r\n"));
  c = fork();
  if (c == -1)
    write(1, "fork fail\r\n", strlen("fork fail\r\n"));
  if (c == 0)
    fork_it(client_fd);
  return (0);
}

int			main(int ac, char **av)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			client_fd;

  port = atoi(av[1]);
  s_in_size = sizeof(s_in_client);
  if(!(pe = getprotobyname("TCP")))
    return (1);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  do_bind(fd, s_in, port);
  while ((client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size))
	 != -1)
    loop(fd, client_fd);
  if (ac != 3 && chdir(av[2]) == -1)
    {
      write(client_fd, USAGE, strlen(USAGE));
      return (-1);
    }
  if (close(fd) == -1)
    return (1);
  return (0);
}
