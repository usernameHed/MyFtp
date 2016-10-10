/*
** handleClient.c for PSU_2015_myftp in /mnt/data/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_myftp/sources
**
** Made by Hed
** Login   <hed@epitech.net>
**
** Started on  Sun May 15 13:32:57 2016 Hed
** Last update Jan May 15 21:26:44 2016
*/

#include "./includes/myftp.h"

t_acmd	acmd[] =
  {
    {"USER", &user },
    {"PASS", &passwd },
    {"CWD", &cwd },
    {"CDUP", &cdup },
    {"PWD", &pwd },
    {"QUIT", &quit },
    {"DELE", &dele },
    {"NOOP", &noop },
    {"HELP", &help },
    {"\0", NULL }
  };

void	make_word(t_data *d)
{
  if (comp(d->tmp, "\r\n"))
    return;
  d->tab = my_str_to_wordtab(d->tmp);
  if (d->tab && d->tab[0])
    make_cmd(d, d->tab[0]);
}

void	make_cmd(t_data *d, char *cmd)
{
  int	i;
  int	ok;

  i = 0;
  ok = 0;
  while (!comp(acmd[i].cmd, "\0"))
  {
    if (comp(acmd[i].cmd, cmd))
    {
      acmd[i].ptr(d);
      ok = 1;
    }
    ++i;
  }
  if (ok == 0)
    badSyntax(d);
}

void	forking(t_data *d)
{
  char	str[4096];
  pid_t	client = fork();

  if (client == 0)
    {
      putAccept("Welcome to hell.", d->acc, "220");
      getcwd(d->pwd, sizeof(d->pwd));
      d->userOk = 0;
      d->passOk = 0;
      while (42)
	{
	  memset(str, 0, sizeof(str));
	  read(d->acc, &str, sizeof(str));
	  d->tmp = strdup(str);
	  d->tmp = del_space(d->tmp);
	  make_word(d);
	  usleep(10);
	}
    }
    else
      close(d->acc);

}
