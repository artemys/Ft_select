/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:43:40 by aliandie          #+#    #+#             */
/*   Updated: 2015/06/13 19:56:29 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <term.h>
# include <stdio.h>
# include <curses.h>
# include <termios.h>
# include <ncurses.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_tools
{
	int			p_max;
	int			line;
	int			col;
	int			col_s;
	int			*selct;
	char		**list;
}				t_tools;
int		g_fd;
void			term();
void			getkey(char *b, int *p, t_tools **tls);
void			print_list(t_tools *tls, int p);
t_tools			*tools_init(char **av, int ac);
void			term_rest();
void			exit_select(t_tools *tls, char *b);
void			delete_list(t_tools **tls, int *p);
void			getwinsize(t_tools *tls, int p);
void			interupt(int sig);
void			handle_cont(int sig);
void			stop(int sig);
char			**ft_tabdeline(char **t, int p);
int				cnt_tabline(char **t);
void			check_error(int ac, char **av, char **env);
# define UP(b) ((b[0] == 27 && b[1] == 91 && b[2] == 65) ? 1 : 0)
# define DOWN(b) ((b[0] == 27 && b[1] == 91 && b[2] == 66) ? 1 : 0)
# define RIGHT(b) ((b[0] == 27 && b[1] == 91 && b[2] == 67) ? 1 : 0)
# define LEFT(b) ((b[0] == 27 && b[1] == 91 && b[2] == 68) ? 1 : 0)
# define SPACE(b) ((b[0] == 32 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define ESC(b) ((b[0] == 27 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define RETURN(b) ((b[0] == 10 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define DELETE(b) ((b[0] == 126 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define BACKSPACE(b) ((b[0] == 127 && b[1] == 0 && b[2] == 0) ? 1 : 0)
#endif
