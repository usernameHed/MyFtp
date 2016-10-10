/*
** philo.c for PSU_2015_philo in /mnt/62401A64401A3F6B/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_philo/src
**
** Made by Hed
** Login   <ugo@epitech.net>
**
** Started on  Mon Mar 07 19:10:34 2016 Hed
** Last update Sun May 15 20:08:02 2016 Hed
*/

#include "./includes/myftp.h"

void	createSocket(t_data *d)
{
  d->sock = socket(AF_INET, SOCK_STREAM, 6);
  if (d->sock == -1)
    my_error("bad socket", -1);
}

void	fillAddr(t_data *d)
{
  d->s_in_size = sizeof(d->_addr);
  d->_addr.sin_family = AF_INET;
  d->_addr.sin_port = htons(d->port);
  d->_addr.sin_addr.s_addr = INADDR_ANY;
}

void	binding(t_data *d)
{
  d->bindd = bind(d->sock,
		  (const struct sockaddr *)&d->_addr, sizeof(struct sockaddr));
  if (d->bindd == -1)
    my_error("bad bind", -1);
}

void	accepting(t_data *d)
{
  listen(d->sock, 21);
  while (42)
    {
      d->acc = accept(d->sock, (struct sockaddr *)&d->_addr, &d->s_in_size);
      if (d->acc != -1)
	forking(d);
      usleep(10);
    }
}

void	init(t_data *d)
{
  createSocket(d);
  fillAddr(d);
  binding(d);
  accepting(d);
}
