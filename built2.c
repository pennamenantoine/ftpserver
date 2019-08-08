/*
** built2.c for built in /home/pennam_a/Systeme_unix/PSU_2015_myftp/tp
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Sun May 15 20:29:41 2016 antoine pennamen
** Last update Sun May 15 23:39:19 2016 antoine pennamen
*/

#include "server.h"

void	noop(char **tab, int client_fd)
{
  if (tab[1] == NULL)
    write(client_fd, "200 Command okay.\r\n",\
	  strlen("200 Command okay.\n"));
  else
    write(client_fd, "xxx Error (RFC compliant)\r\n"      \
	  , strlen("xxx Error (RFC compliant)\r\n"));
}

void	pwd(char **tab, int client_fd)
{
  char	*dir;

  if (tab[1] == NULL)
    {
      dir = getcwd(NULL, 0);
      write(client_fd, "257 ", strlen("257 "));
      write(client_fd, dir, strlen(dir));
      write(client_fd, " created.\r\n", strlen(" created.\r\n"));
    }
  else if (tab[1] != NULL)
    write(client_fd, "xxx Error (RFC compliant)\r\n"      \
	  , strlen("xxx Error (RFC compliant)\r\n"));
}
