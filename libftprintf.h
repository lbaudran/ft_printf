/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/23 16:09:44 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>

typedef struct			s_list
{
	char				*str;
	int					nbr;
	int					use;
	int					*tab;
	struct s_list		*next;
}						t_list;

int			ft_printf(const char * format, ...);
int			is_noargforprintf(char c);
int			is_intforprintf(char c);
int			check_start(int i, const char * s, va_list *ap, int *tab);
int			check_flag(int i, const char *s, va_list *ap, int *tab);
int			check_width(int i, const char *s, va_list *ap, int *tab);
int			check_acc(int i, const char *s, va_list *ap, int *tab);
int			check_modif(int i, const char *s, va_list *ap, int *tab);
int			check_type(int i, const char *s, va_list *ap, int *tab);

#endif
