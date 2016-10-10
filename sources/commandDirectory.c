/*
** command.c for PSU_2015_myftp in /mnt/data/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_myftp/sources
**
** Made by Hed
** Login   <hed@epitech.net>
**
** Started on  Sun May 15 14:12:21 2016 Hed
** Last update Jan May 15 21:27:42 2016
*/

#include "./includes/myftp.h"

void	pwd(t_data *d)
{
  if (d->passOk != 1)
    {
      putAccept("USER authentification required.", d->acc, "530");
      return;
    }
  putAccept("257 ", d->acc, NULL);
  putAccept("\"", d->acc, NULL);
  putAccept(d->pwd, d->acc, NULL);
  putAccept("\"", d->acc, NULL);
  putAccept("\r\n", d->acc, NULL);
}

void	quit(t_data *d)
{
  putAccept("It's hard to say goodbye !", d->acc, "221");
  shutdown(d->acc, SHUT_RDWR);
  close(d->acc);
  exit(EXIT_SUCCESS);
}

void	dele(t_data *d)
{
  if (d->passOk != 1)
    {
      putAccept("USER authentification required.", d->acc, "530");
      return;
    }
  if (!(d->tab && d->tab[0] && d->tab[1])
      || access(d->tab[1], F_OK & R_OK) == -1)
    {
      putAccept("Can't delete file or directory.", d->acc, "550");
      return;
    }
  if ((remove(d->tab[1]) == 0))
    {
      putAccept("File deleted !", d->acc, "250");
      return;
    }
  putAccept("Can't delete file or directory.", d->acc, "550");
}

void	noop(t_data *d)
{
  if (d->passOk != 1)
    {
      putAccept("USER authentification required.", d->acc, "530");
      return;
    }
  putAccept("It's hare to do nothing !", d->acc, "200");
}

void	badSyntax(t_data *d)
{
  if (d->passOk == 1)
    putAccept("Bad syntaxe.", d->acc, "404");
  else
    putAccept("Veuillez vous connecter.", d->acc, "530");
}
