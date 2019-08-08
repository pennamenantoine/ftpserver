/*
** built.c for built in /home/pennam_a/Systeme_unix/PSU_2015_myftp/tp
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Fri May 13 21:33:40 2016 antoine pennamen
** Last update Sun May 15 23:56:41 2016 antoine pennamen
*/

#include "server.h"

void		user(char **tab, int client_fd)
{
  t_status	status;

  status = status;
  if (tab[1] == NULL || (strcmp(tab[1], "Anonymous") != 0))
    {
      status.user_status = -1;
      write(client_fd, "xxx Error (RFC compliant)\r\n"	\
	    , strlen("xxx Error (RFC compliant)\r\n"));
    }
  else if (strcmp(tab[1], "Anonymous") == 0)
    {
      status.user_status = 0;
      write(client_fd, "331 User name okay, need password.\r\n" \
	    , strlen("331 User name okay, need password.\r\n"));
    }
}

void		pass(char **tab, int client_fd)
{
  t_status	status;

  if (tab[1] == NULL && status.user_status != 0)
    write (client_fd, "332 Need account for login.\r\n", \
	   strlen("332 Need account for login.\r\n"));
  else if (tab[1] == NULL && status.user_status == 0)
    write(client_fd, "230 User logged in, proceed.\r\n", \
	  strlen("230 User logged in, proceed.\r\n"));
  else if (tab[1] != NULL && status.user_status != 0)
    write(client_fd, "xxx Error (RFC compliant)\r\n"	\
	  , strlen("xxx Error (RFC compliant)\r\n"));
  else if (status.user_status == 0 && tab[1] != NULL)
    write(client_fd, "xxx Error (RFC compliant)\r\n"	\
	  , strlen("xxx Error (RFC compliant)\r\n"));
}

void	cwd(char **tab, int client_fd)
{
  if (tab[1] != NULL)
    {
      if ((chdir(tab[1])) == -1)
	write(client_fd, "xxx Error (RFC compliant)\r\n"	\
	      , strlen("xxx Error (RFC compliant)\r\n"));
      else
	write(client_fd, "250 Requested file action okay, completed.\r\n",\
	      strlen("250 Requested file action okay, completed.\r\n"));
    }
  else if (tab[1] == NULL)
    write(client_fd, "xxx Error (RFC compliant)\r\n"	\
	  , strlen("xxx Error (RFC compliant)\r\n"));
}

void	cdup(char **tab, int client_fd)
{
  if (tab[1] == NULL)
    {
      chdir("/home");
      write(client_fd, "200 Command okay.\r\n", \
	    strlen("200 Command okay.\r\n"));
    }
  else if (tab[1] != NULL)
    {
      write(client_fd, "xxx Error (RFC compliant)\r\n"	\
	    , strlen("xxx Error (RFC compliant)\r\n"));
    }
}

void	quit(char **tab, int client_fd)
{
  if (tab[1] == NULL)
    {
      write(client_fd, \
	    "221 Service closing control connection. \nLogged out if appropriate.\r\n"\
	    , strlen(							\
		     "221 Service closing control connection.\nLogged out if appropriate.\r\n"
									));
      exit(-1);
    }
  else if (tab[1] != NULL)
    write(client_fd, "xxx Error (RFC compliant)\r\n"\
	  , strlen("xxx Error (RFC compliant)\r\n"));
}
