/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:36:37 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/23 17:47:23 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			check_start(int i, const char *s, t_list *begin)
{
	int			n;

	n = 0;
	i++;
		if (s[i] == '-' || s[i] == '+' || s[i] == ' ' || s[i] == '#')
			check_flag(i, s, begin);
		if ((s[i] >= '0' && s[i] <= '9') || 
			(s[i] == '0' && s[i + 1] >= '1' && s[i + 1] <= '9') || s[i] == '*')
			check_width(i, s, begin);
		if (s[i] == '.' && s[i + 1] >= '0' && s[i + 1] <= '9')
			check_acc(i, s, begin);
		if (s[i] == 'h' || s[i] == 'l' || s[i] == 'L')
			check_modif(i, s, begin);
		if (s[i] == 'd' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
			s[i] == 'x' || s[i] == 'X' || s[i] == 'f' || s[i] == 'e' ||
			s[i] == 'E' || s[i] == 'g' || s[i] == 'G' || s[i] == 'c' ||
			s[i] == 's' || s[i] == 'p')
			check_type(i, s, begin);
}

void			check_flag(int i, const char *s, t_list *begin)
{
	if (s[i] == '-')
		begin->tab[0] = 1;
	else if (s[i] == '+')
		begin->tab[0] = 2;
	else if (s[i] == ' ')
		begin->tab[0] = 3;
	else if (s[i] == '#')
		begin->tab[0] = 4;
	while (s[i] == '-' || s[i] == '+' || s[i] == ' ' || s[i] == '#')
		i++;
}


void			check_width(int i, const char *s, t_list *begin)
{
	char	tmp[12];
	int		n;

	n = 0;
	if (s[i] >= '1' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
				tmp[n++] = s[i++];
		begin->tab[1] = ft_atoi(tmp);
	}
	else if (s[i] == '0')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
				tmp[n++] = s[i++];
		begin->tab[1] = ft_atoi(tmp);
	}
	else if (s[i] == '*')
	{
	}
}

void			check_acc(int i, const char *s, t_list *begin)
{

}

void			check_modif(int i, const char *s, t_list *begin)
{

}

void			check_type(int i, const char *s, t_list *begin)
{

}
