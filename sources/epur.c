/*
** conv_nbr.c for  in /home/exam/rendu/ex_1
**
** Made by Exam User
** Login   <exam@epitech.net>
**
** Started on  Fri Apr  1 09:10:06 2016 Exam User
** Last update Jul May 14 23:18:05 2016
*/

#include "./includes/myftp.h"

char	*del_space(char str[4096])
{
  char	tmp[4096];
  int	i = 0;
  int	j = 0;

  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i])
    {
      if (!((str[i] == ' ' && str[i + 1] == ' ')
	    || (str[i] == ' ' && str[i + 1] == '\0')))
	{
	  tmp[j] = str[i];
	  j++;
	  i++;
	}
      else
	i++;
    }
  tmp[j] = '\0';
  str = tmp;
  return (str);
}
