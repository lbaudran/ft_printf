/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:36:37 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/20 16:54:46 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			check_start(int *i, const char *s, va_list *ap, int *tab)
{
	int			n;

	n = 0;
	(*i)++;
	while (is_check(s[*i]))
	{
		if (s[*i] == '-' || s[*i] == '+' || s[*i] == ' ' || s[*i] == '#'
				|| s[*i] == '0')
			check_flag(i, s, tab);
		if ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '*')
			check_width(i, s, ap, tab);
		if (s[*i] == '.')
			check_acc(i, s, ap, tab);
		if (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'L' || s[*i] == 'j' 
				|| s[*i] == 'z')
			check_modif(i, s, tab);
		if (is_typeforprintf(s[*i]))
		{
			check_type(tab, s[(*i)++]);
			return(1);
		}
	}
		return (1);
}

void			check_flag(int *i, const char *s, int *tab)
{
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == ' ' || s[*i] == '#'
			|| s[*i] == '0')
	{
		if (s[*i] == '-'  && tab[0] != '-')
			tab[0] = '-';
		if (s[*i] == '+' && tab[1] != '+')
			tab[1] = '+';
		if (s[*i] == ' ' && tab[1] != ' ' && tab[1] != '+')
			tab[1] = ' ';
		if (s[*i] == '#'  && tab[2] != '#')
			tab[2] = '#';
		if (s[*i] == '0' && tab[0] != '0' && tab[0] != '-')
		{
			tab[3] = '0';
			tab[0] = '0';
		}
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
		tab[4] = ft_atoi(tmp);
	}
	else if (s[*i] == '*')
	{
		tab[4] = va_arg(*ap, int);
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
		tab[5] = -1;
		if (s[*i] == '0')
			(*i)++;
	}
	else if (s[*i] >= '0' && s[*i] <= '9')
	{
		while (s[*i] >= '0' && s[*i] <= '9')
			tmp[n++] = s[(*i)++];
		tab[5] = ft_atoi(tmp);
	}
	else if (s[*i] == '*')
	{
		tab[5] = va_arg(*ap, int);
		(*i)++;
	}
}

void			check_modif(int *i, const char *s, int *tab)
{
	if (s[*i] == 'h')
	{
		tab[6] = 2;
		if (s[(*i + 1)] == 'h')
			tab[6] = 1;
	}
	else if (s[*i] == 'l')
	{
		tab[6] = 3;
		if (s[(*i + 1)] == 'l')
			tab[6] = 4;
	}
	else if (s[*i] == 'j')
		tab[6] = 5;
	else if (s[*i] == 'z')
		tab[6] = 6;
	else if (s[*i] == 'L')
		tab[6] = 7;
	if (tab[6] != 0)
		(*i)++;
	if (tab[6] == 1 || tab[6] == 4)
		(*i)++;
}
