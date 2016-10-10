/*
** myftp.h for PSU_2015_philo in /mnt/62401A64401A3F6B/Dropbox/HED/ALL/epitech/rendu/PSU/PSU_2015_philo/include
**
** Made by Hed
** Login   <ugo@epitech.net>
**
** Started on  Fri Mar 04 16:07:16 2016 Hed
** Last update Mar May 17 10:22:09 2016
*/

#ifndef MYFTP_H_
#define MYFTP_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct		s_data
{
  int			port;
  char			*path;
  char			tmpPath[4096];
  int			sock;
  int			acc;
  int			bindd;
  struct sockaddr_in	_addr;
  char			*tmp;
  int			userOk;
  int			passOk;
  char			user[4096];
  char			**tab;
  char			pwd[4096];
  unsigned long		lenOfFirstPwd;
  socklen_t		s_in_size;
}			t_data;

typedef struct		s_acmd
{
  char			*cmd;
  void			(*ptr)(void);
}			t_acmd;

void	init(t_data *d);
void	my_error(char *error, short int type);
char	**my_str_to_wordtab(char *str);
char	*del_space(char *str);
void	make_word(t_data *s);
void	my_show_wordtab(t_data *d, int fd);
void	make_cmd(t_data *d, char *cmd);
char	*add_to_str(char *str);
void	putAccept(char *str, int fd, char *code);
void	forking(t_data *d);
int	comp(char *s1, char *s2);
void	user(t_data *d);
void	passwd(t_data *d);
void	cwd(t_data *d);
void	cdup(t_data *d);
void	pwd(t_data *d);
void	quit(t_data *d);
void	dele(t_data *d);
void	noop(t_data *d);
void	badSyntax(t_data *d);
void	help(t_data *d);

#endif
