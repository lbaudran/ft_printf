/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 19:11:10 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct			s_list
{
	char				*line;
	int		testint;
}			t_list;

char		*ft_addzero(char *buffer, int *tab);
void		ft_add_nul(char *buffer, int a);
int			is_check(char c);
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
char		*ft_convertbase(unsigned long long i, int base);
char		*putline_nbr(char *line, t_list *elem, int *tab);
char		*putline_str(char *line, t_list *elem, int *tab, const char *fmt);
char		*print_arg(int *tab, va_list *arg, char *line, const char *format);
void		init_pt_tab(char *(**types)(va_list *arg, char *buffer, int *tab));
char		*check_percent(va_list *arg, char *buffer, int *tab);
char		*get_int(va_list *arg, char *buffer, int *tab);
char		*get_char(va_list *arg, char *buffer, int *tab);
char		*get_nothing(va_list *arg, char *buffer, int *tab);
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
char		*ft_apply_flag(int *tab, char *buffer);
void		init_diez_tab(char *(**diez)(char *tmp, char *buffer, int *tab));
void		init_signed_tab(char *(**modif_signed)
			(va_list *arg, char *buffer, int *tab));
void		init_unsigned_tab(char *(**modif_unsigned)
			(va_list *arg, char *buffer, int *tab, int base));
char		*ft_add_empty(char *tmp, int *tab, char *buffer);
char		*ft_utoa(unsigned int n);
char		*apply_diez_octal(char *tmp, char *buffer, int *tab);
char		*apply_diez_hexa_low(char *tmp, char *buffer, int *tab);
char		*apply_diez_binary(char *tmp, char *buffer, int *tab);
char		*apply_diez_hexa_up(char *tmp, char *buffer, int *tab);
char		*apply_diez_double(char *tmp, char *buffer, int *tab);
char		*apply_diez_scient_low(char *tmp, char *buffer, int *tab);
char		*apply_diez_shorter_low(char *tmp, char *buffer, int *tab);
char		*apply_diez_shorter_low2(char *tmp, char *buffer, int *tab);
int			ft_atoi(const char *s);
void		*ft_bzero(void *str, size_t n);
int			ft_isdigit(int c);
char		*ft_itoa(long n);
void		*ft_memmove(void *dst, const void *src, size_t len);
long double	ft_power(long a, int b);
char		*ft_round(char *str, int size);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *str, int c);
size_t		ft_strlen(const char *str);
int			ft_toupper(int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*get_long_long_int(va_list *arg, char *buffer, int *tab);
char		*get_long_int(va_list *arg, char *buffer, int *tab);
char		*get_short_int(va_list *arg, char *buffer, int *tab);
char		*get_short_short_int(va_list *arg, char *buffer, int *tab);
char		*get_normal_int(va_list *arg, char *buffer, int *tab);
char		*get_int_max(va_list *arg, char* buffer, int *tab);
char		*get_size_int(va_list *arg, char *buffer, int *tab);
char	*get_long_long_unsigned(va_list *arg, char *buffer, int *tab, int base);
char	*get_long_unsigned(va_list *arg, char *buffer, int *tab, int base);
char	*get_short_unsigned(va_list *arg, char *buffer, int *tab, int base);
char	*get_normal_unsigned(va_list *arg, char *buffer, int *tab, int base);
char	*get_short_short_unsigned(va_list *arg, char *buffer, int *tab,
		int base);
char		*get_size_unsigned(va_list *arg, char *buffer, int *tab, int base);
char		*get_unsigned_max(va_list *arg, char *buffer, int *tab, int base);
char		*get_nothing(va_list *arg, char *buffer, int *tab);


#endif
