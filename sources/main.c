/*
** main.c for PSU_2015_philo in /mnt/62401A64401A3F6B/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_philo
**
** Made by Hed
** Login   <ugo@epitech.net>
**
** Started on  Fri Mar 04 12:24:32 2016 Hed
** Last update Jan May 15 18:29:16 2016
*/

#include "./includes/myftp.h"

void	test_arg(t_data *d)
{
  DIR	*pDir;

  if (!(d->port >= 0 && d->port < 65537))
    my_error("bad port", -1);
  pDir = opendir(d->path);
  if (pDir == NULL)
    my_error("bad path", -1);
  else
    {
      chdir(d->path);
      getcwd(d->tmpPath, sizeof(d->tmpPath));
      d->lenOfFirstPwd = strlen(d->tmpPath);
    }
}

int main(int ac, char **av)
{
  if (ac != 3)
    my_error("Usage : ./server port path", -1);
  else
  {
    t_data d;
    d.port = atoi(av[1]);
    d.path = av[2];
    test_arg(&d);
    init(&d);
  }
  return (0);
}
