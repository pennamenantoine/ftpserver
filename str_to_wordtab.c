/*
** str_to_wordtab.c for str in /home/pennam_a/Systeme_unix/PSU_2015_myftp/tp
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Sun May 15 13:26:47 2016 antoine pennamen
** Last update Sun May 15 23:42:03 2016 antoine pennamen
*/

#include "server.h"
#include <stdlib.h>

int	count_words_in_str(char *str)
{
  int	i;
  int	words;

  i = 0;
  words = 0;
  while (str && str[i] != '\0')
    {
      while (str[i] == ' ' || str[i] == '\t' || \
	     str[i] == '\r' || str[i] == '\n')
	i = i + 1;
      if (str[i] != '\0')
	words = words + 1;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' \
	     && str[i] != '\r' && str[i] != '\0')
	i = i + 1;
    }
  return (words);
}

char	**str_to_wordtab(char *str, int i, int j, int m)
{
  char	**tab;
  int	k;

  if ((tab = malloc(sizeof(char *) * (count_words_in_str(str) + 1))) == NULL)
    return (NULL);
  while (str && str[i] != '\0')
    {
      while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||	\
	     str[i] == '\r')
	i = i + 1;
      k = i;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && \
	     str[i] != '\r' && str[i] != '\0')
	i = i + 1;
      if ((tab[j] = malloc(sizeof(char) * ((i - k)) + 3)) == NULL)
	return (NULL);
      if (k < i)
	{
	  while (k < i)
	    tab[j][m++] = str[k++];
	  tab[j++][m] = '\0';
	}
    }
  tab[j] = NULL;
  return (tab);
}
