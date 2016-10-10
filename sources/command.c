/*
** command.c for PSU_2015_myftp in /mnt/data/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_myftp/sources
**
** Made by Hed
** Login   <hed@epitech.net>
**
** Started on  Sun May 15 14:12:21 2016 Hed
** Last update Jan May 15 20:32:54 2016
*/

#include "./includes/myftp.h"

void	user(t_data *d)
{
  if (!(d->tab && d->tab[0] && d->tab[1]))
    putAccept("No user name", d->acc, "530");
  else if (d->userOk == 1 && d->passOk == 1)
    putAccept("Can't change from guest user.", d->acc, "530");
  else
    {
      strcpy(d->user, d->tab[1]);
      putAccept("Please set the password.", d->acc, "331");
      if (comp(d->user, "Anonymous"))
	d->userOk = 1;
    }
}

void	passwd(t_data *d)
{
  if (d->passOk == 1)
    {
      putAccept("Already logged in.", d->acc, "230");
      return;
    }
  if (d->userOk == 1)
    {
      d->passOk = 1;
      putAccept("Login successful.", d->acc, "230");
    }
  else
    putAccept("Login incorrect.", d->acc, "530");
}

void changecwd(t_data *d, char *pathtmp)
{
  int	tmp1;
  int	tmp2;

  chdir(pathtmp);
  tmp1 = strlen(d->tmpPath);
  getcwd(d->pwd, sizeof(d->pwd));
  tmp2 = strlen(d->pwd);
  if (tmp1 > tmp2)
    {
      chdir(d->tmpPath);
      getcwd(d->pwd, sizeof(d->pwd));
    }
  putAccept("Directory successfully changed.", d->acc, "250");
}

void	cwd(t_data *d)
{
  if (d->passOk != 1)
    {
      putAccept("USER authentification required.", d->acc, "530");
      return;
    }
  if (!(d->tab && d->tab[0] && d->tab[1])
      || access(d->tab[1], F_OK & R_OK) == -1)
    putAccept("Failer to change directory.", d->acc, "550");
  else
    changecwd(d, d->tab[1]);
}

void	cdup(t_data *d)
{
  if (d->passOk != 1)
    {
      putAccept("USER authentification required.", d->acc, "530");
      return;
    }
  changecwd(d, "../");
}
