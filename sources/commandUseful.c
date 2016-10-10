/*
** command.c for PSU_2015_myftp in /mnt/data/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_myftp/sources
**
** Made by Hed
** Login   <hed@epitech.net>
**
** Started on  Sun May 15 14:12:21 2016 Hed
** Last update Jan May 15 20:05:29 2016
*/

#include "./includes/myftp.h"

void	help(t_data *d)
{
  if (d->passOk != 1)
    {
      putAccept("USER authentification required.", d->acc, "530");
      return;
    }
  putAccept("214-here is all the recognized command:", d->acc, NULL);
  putAccept("\r\n", d->acc, NULL);
  putAccept(" USER PASS CWD CDUP QUIT DELE PWD HELP NOOP", d->acc, NULL);
  putAccept("\r\n", d->acc, NULL);
  putAccept("Help OK.", d->acc, "214");
}
