/*
** my_error.c for PSU_2015_philo in /mnt/62401A64401A3F6B/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_philo/src
**
** Made by Hed
** Login   <ugo@epitech.net>
**
** Started on  Mon Mar 07 18:53:23 2016 Hed
** Last update Jul May 14 19:16:00 2016
*/

#include "./includes/myftp.h"

void	my_error(char *error, short int type)
{
  if (type == 0)
    printf("%s\n", error);
  else if (type == -1)
    printf("%s\n", error);
  exit(0);
}
