/*
** server.h for serveur in /home/pennam_a/Systeme_unix/PSU_2015_myftp/tp
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Fri May 13 21:20:00 2016 antoine pennamen
** Last update Sun May 15 23:38:51 2016 antoine pennamen
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

# include <netinet/in.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define USAGE "Usage : ./server port path"

typedef struct	s_status
{
  int		user_status;
}		t_status;

typedef struct	s_built
{
  char		*str;
  void		(*fct)(char **tab, int client_fd);
}		t_built;

int		fork_it(int);
char		**str_to_wordtab(char *, int, int, int);
int		do_bind(int, struct sockaddr_in, int);
void		check_buffer(char *, int, int, int);
int		loop(int, int);
void		user(char **, int);
void		pass(char **, int);
void		cwd(char **, int);
void		cdup(char **, int);
void		quit(char **, int);
void		noop(char **, int);
void		pwd(char **, int);

#endif /* !SERVEUR_H_ */
