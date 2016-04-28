/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/28 19:54:05 by lbaudran         ###   ########.fr       */
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
	int					index;
	int					aff_null;
	int					aff_null_w;
	wchar_t				*unicode;
}						t_list;

void		check_type_3(int *tab, char c);
void		ft_wstrncpy(wchar_t *wstr, wchar_t *src, int i);
void		ft_wstrcpy(wchar_t *wstr, wchar_t *src);
int			ft_wstrlen(wchar_t *wstr);
void		ft_putprintf(int *tab, t_list *elem);
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
char		*stock_str(va_list *ap, int *i, t_list *elem, const char *fmt);
void		reset_tab(int *tab, int i);
char		*ft_dtoa(long double i, int size);
char		*ft_convertbase(unsigned long long i, int base);
char		*putline_nbr(char *line, t_list *elem, int *tab);
char		*putline_str(char *line, t_list *elem, int *tab, const char *fmt);
char		*print_arg(int *tab, va_list *arg, t_list *elem, const char *fmt);
void		init_pt_tab(char *(**types)
		(va_list *arg, char *buffer, int *tab, t_list *elem));
char		*check_percent(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_int(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_char(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_nothing(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_str(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_int_ns(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_octal(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_hexa_low(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_hexa_up(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_double(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_scient(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_scient_up(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_shorter(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_shorter_up(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*get_wstring(va_list *arg, char *buffer, int *tab, t_list *elem);
int			size_forscient(long double *i);
int			size_forscient_normal(double *i);
char		*arg_forscient(char *buffer, int n);
char		*arg_forscient_up(char *buffer, int n);
char		*get_point(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*fill_point(char *buffer);
char		*get_binary(va_list *arg, char *buffer, int *tab, t_list *elem);
char		*ft_apply_flag(int *tab, char *buffer, t_list *elem);
char		*ft_apply_flag_2(int *t, char *buf, char *tmp, t_list *elem);
void		init_diez_tab(char *(**diez)(char *tmp, char *buffer, int *tab));
void		init_signed_tab(char *(**modif_signed)
			(va_list *arg, char *buffer, int *tab));
void		init_unsigned_tab(char *(**modif_unsigned)
			(va_list *arg, char *buffer, int *tab, int base));
char		*ft_add_empty(char *tmp, int *tab, char *buffer, t_list *elem);
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
char		*get_long_long_unsigned(va_list *arg, char *buffer, int *tab,
		int base);
char		*get_long_unsigned(va_list *arg, char *buffer, int *tab, int base);
char		*get_short_unsigned(va_list *arg, char *buf, int *tab, int base);
char		*get_normal_unsigned(va_list *arg, char *buffer, int *tab,
		int base);
char		*get_short_short_unsigned(va_list *arg, char *buffer, int *tab,
		int base);
char		*get_size_unsigned(va_list *arg, char *buffer, int *tab, int base);
char		*get_unsigned_max(va_list *arg, char *buffer, int *tab, int base);


#endif
