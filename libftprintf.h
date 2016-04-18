/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/18 18:40:59 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>

typedef struct			s_list
{
	char				*tmpstr;
	int		i;
	int		y;
	int		n;
}			t_list;

int			ft_printf(const char * format, ...);
int			is_noargforprintf(char c);
int			is_intforprintf(char c);
void		start_write(const char* format, va_list *ap, int *tab);
int			check_start(int *i, const char * s, va_list *ap, int *tab);
void		check_flag(int *i, const char *s, int *tab);
void		check_width(int *i, const char *s, va_list *ap, int *tab);
void		check_acc(int *i, const char *s, va_list *ap, int *tab);
void		check_modif(int *i, const char *s, int *tab);
int			check_type(int *tab , char c);
int			is_typeforprintf(char c);
char		*stock_str(va_list *ap, int *i, char *line, const char *fmt);
void		reset_tab(int *tab, int i);
char		*ft_dtoa(long double i, int size);
char		*ft_convertbase(int i, int base);
char		*putline_nbr(char *line, t_list *elem, int *tab);
char		*putline_str(char *line, t_list *elem, int *tab, const char *fmt);
char		*print_arg(int *tab, va_list *arg, char *str, const char *format);
void		init_pt_tab(char *(**types)(va_list *arg, char *buffer, int *tab));
char		*get_int(va_list *arg, char *buffer, int *tab);
char		*get_char(va_list *arg, char *buffer, int *tab);
char		*get_str(va_list *arg, char *buffer, int *tab);
char		*get_int_ns(va_list *arg, char *buffer, int *tab);
char		*get_octal(va_list *arg, char *buffer, int *tab);
char		*get_hexa_low(va_list *arg, char *buffer, int *tab);
char		*get_hexa_up(va_list *arg, char *buffer, int *tab);
char		*get_double(va_list *arg, char *buffer, int *tab);
char		*get_scient(va_list *arg, char *buffer, int *tab);
char		*get_scient_up(va_list *arg, char *buffer, int *tab);
char		*get_shorter(va_list *arg, char *buffer, int *tab);
char		*get_shorter_up(va_list *arg, char *buffer, int *tab);
int			size_forscient(double *i);
char		*arg_forscient(char *buffer, int n);
char		*arg_forscient_up(char *buffer, int n);
char		*get_point(va_list *arg, char *buffer, int *tab);
char		*fill_point(char *buffer);
char		*get_binary(va_list *arg, char *buffer, int *tab);
char		*check_percent(const char *fmt, int *i, char *line);
char		*ft_apply_flag(int *tab, char *buffer);
void		init_diez_tab(char *(**diez)(char *tmp, char *buffer, int *tab));
char		*ft_add_empty(char *tmp, int *tab, char *buffer);
char		*ft_utoa(unsigned int n);

#endif
