/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/22 19:12:46 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>

int				ft_printf(const char * format, ...);
int			check_start(int i, const char * s, va_list *ap, int *tab);
int			check_flag(int i, const char *s, va_list *ap, int *tab);
int			check_width(int i, const char *s, va_list *ap, int *tab);
int			check_acc(int i, const char *s, va_list *ap, int *tab);
int			check_modif(int i, const char *s, va_list *ap, int *tab);
int			check_type(int i, const char *s, va_list *ap, int *tab);

#endif
