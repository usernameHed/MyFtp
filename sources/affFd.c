/*
** affFd.c for PSU_2015_myftp in /mnt/data/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_myftp/sources
**
** Made by Hed
** Login   <hed@epitech.net>
**
** Started on  Sun May 15 13:35:11 2016 Hed
** Last update Jan May 15 15:58:04 2016
*/

#include "./includes/myftp.h"

int	comp(char *s1, char *s2)
{
  if (strcmp(s1, s2) == 0)
    return (1);
  else
    return (0);
}

void		putAccept(char *str, int fd, char *code)
{
  char		f;
  char		c;
  char		e;
  unsigned int	i;

  f = ' ';
  c = '\r';
  e = '\n';
  if (code)
    {
      i = -1;
      while (++i < strlen(code))
	write(fd, &code[i], 1);
      write(fd, &f, 1);
    }
  i = -1;
  if (str)
    while (++i < strlen(str))
      write(fd, &str[i], 1);
  if (code)
    {
      write(fd, &c, 1);
      write(fd, &e, 1);
    }
}
