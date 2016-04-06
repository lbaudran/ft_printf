/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:36:37 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/30 18:55:00 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			check_start(int *i, const char *s, va_list *ap, int *tab)
{
	int			n;

	n = 0;
	i++;
		if (s[*i] == '-' || s[*i] == '+' || s[*i] == ' ' || s[*i] == '#')
			check_flag(i, s, tab);
		if ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '*')
			check_width(i, s, ap, tab);
		if (s[*i] == '.' && ((s[(*i) + 1] >= '0' && s[(*i) + 1] <= '9') ||
				s[(*i) + 1] == '*'))
			check_acc(i, s, ap, tab);
		if (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'L')
			tab[5] = s[*i];
		if (is_typeforprintf(s[*i]))
		{
			tab[6] = s[*i];
			return(check_type(i, s, ap, tab));
		}
		return (-1);
}

void			check_flag(int *i, const char *s, int *tab)
{
	char tmp[4];

	ft_bzero(tmp, 4);
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == ' ' || s[*i] == '#')
	{
		if (s[*i] == '-'  && tab[1] != '-')
			tab[0] = '-';
		if (s[*i] == '+' && tab[2] != '+')
			tab[1] = '+';
		if (s[*i] == ' ' && tab[2] != ' ' && tab[2] != '+')
			tab[1] = '+';
		if (s[*i] == '#'  && tab[3] != '#')
			tab[2] = '#';
		(*i)++;
	}
}


void			check_width(int *i, const char *s, va_list *ap, int *tab)
{
	char	tmp[19];
	int		n;

	n = 0;
	ft_bzero(tmp, 19);
	if (s[*i] >= '1' && s[*i] <= '9')
	{
		while (s[*i] >= '0' && s[*i] <= '9')
				tmp[n++] = s[(*i)++];
		if (n < 19)
		tmp[n] = 'i';
		tab[3] = ft_atoi(tmp);
	}
	else if (s[*i] == '0')
	{
		(*i)++;
		while (s[*i] >= '0' && s[*i] <= '9')
				tmp[n++] = s[*i++];
		if (n < 19)
			tmp[n] = 'i';
		tab[3] = ft_atoi(tmp);
	}
	else if (s[*i] == '*')
	{
		tab[3] = va_arg(*ap, int);
		(*i)++;
	}
}

void			check_acc(int *i, const char *s,va_list *ap, int *tab)
{
	char	tmp[19];
	int		n;

	(*i)++;
	n = 0;
	ft_bzero(tmp, 19);
	if ((s[*i] == '0' && !ft_isdigit(s[(*i) + 1])) || !ft_isdigit(s[*i]))
	{
		tab[4] = -1;
		i++;
	}
	else if (s[*i] >= '0' && s[*i] <= '9')
	{
		while (s[*i] >= '0' && s[*i] <= '9')
			tmp[n++] = s[(*i)++];
		tab[4] = ft_atoi(tmp);
	}
	else if (s[*i] == '*')
	{
		tab[4] = va_arg(*ap, int);
		(*i)++;
	}
}
