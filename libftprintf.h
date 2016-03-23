/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/23 18:30:22 by lbaudran         ###   ########.fr       */
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
	char				*str;
	int					nbr;
	int					*tab;
	struct s_list		*next;
}						t_list;

int				ft_printf(const char * format, ...);
int				is_noargforprintf(char c);
int				is_intforprintf(char c);
void			start_write(const char* format, t_list *begin);
void			check_start(int i, const char * s, t_list *begin);
void			check_flag(int i, const char *s, t_list *begin);
void			check_width(int i, const char *s, t_list *begin);
void			check_acc(int i, const char *s, t_list *begin);
void			check_modif(int i, const char *s, t_list *begin);
void			check_type(int i, const char *s, t_list *begin, int *tab);

#endif
