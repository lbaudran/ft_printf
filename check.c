/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:36:37 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/22 19:34:05 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			check_start(int i, const char * s, va_list *ap, int *tab)
{
	int n;

	n = 0 ;
	i++;
		if (s[i] == '-' || s[i] == '+' || s[i] == ' ' || s[i] == '#')
			n = check_flag(i, s, ap, tab);
		else if ((s[i] >= '0' &&s[i] <= '9') || 
			(s[i] == '0' && s[i + 1] >= '1' && s[i + 1] <= '9') || s[i] == '*')
			n = check_width(i, s, ap, tab);
		else if (s[i] == '.' && s[i + 1] >= '0' && s[i + 1] <= '9')
			n = check_acc(i, s, ap, tab);
		else if (s[i] == 'h' || s[i] == 'l' || s[i] == 'L')
			n = check_modif(i, s, ap, tab);
		else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
				s[i] == 'x' || s[i] == 'X' || s[i] == 'f' || s[i] == 'e' ||
				s[i] == 'E' || s[i] == 'g' || s[i] == 'G' || s[i] == 'c' ||
				s[i] == 's' || s[i] == 'p')
			n = check_type(i, s, ap, tab);
		return (n);
}

int			check_flag(int i, const char *s, va_list *ap, int *tab)
{
	if (s[i] == '-')
		tab[0] = 1;
	else if (s[i] == '+')
		tab [0] = 2;
	else if (s[i] == ' ')
		tab[0] = 3;
	else if (s[i] == '#')
		tab[0] = 4;
	return (check_width(i, s, ap, tab));
}


int			check_width(int i, const char *s, va_list *ap, int *tab)
{
	char	tmp[12];
	int		n;

	n = 0;
	if (tab[0] != 0)
		i++;
	if (s[i] >= '1' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
				tmp[n++] = s[i++];
		tab[1] = ft_atoi(tmp);
	}
	else if (s[i] == '0')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
				tmp[n++] = s[i++];
		tab[1] = ft_atoi(tmp);
	}
	else if (s[i] == '*')
	{
		tab[1] = va_arg(ap, int)
	}
}

int			check_acc(int i, const char *s, va_list *ap, int *tab)
{

}

int			check_modif(int i, const char *s, va_list *ap, int *tab)
{

}

int			check_type(int i, const char *s, va_list *ap, int *tab)
{

}
