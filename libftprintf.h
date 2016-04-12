/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/12 17:05:28 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#define NOARG is_noargforprintf
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>

typedef struct			s_list
{
	char				*tmpstr;
	long double			tmpint;
	int					i;
	int					y;
	int					n;
}						t_list;

int				ft_printf(const char * format, ...);
int				is_noargforprintf(char c);
int				is_intforprintf(char c);
void			start_write(const char* format, va_list *ap, int *tab);
int				check_start(int *i, const char * s, va_list *ap, int *tab);
void			check_flag(int *i, const char *s, int *tab);
void			check_width(int *i, const char *s, va_list *ap, int *tab);
void			check_acc(int *i, const char *s, va_list *ap, int *tab);
int				check_type(int *i, const char *s, va_list *ap, int *tab);
int				is_typeforprintf(char c);
char			*stock_str(va_list *ap, int *i, char *line, const char *fmt);
void			reset_tab(int *tab, int i);
char			*putline_nbr(char *line, t_list *elem, int *tab);
char			*putline_str(char *line, t_list *elem, int *tab, const char *fmt);
#endif
