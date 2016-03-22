/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:36:37 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/22 18:18:05 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			check_start(int i, const char * s, va_list *ap)
{
	i++;
		if (s[i] == '-' || s[i] == '+' || s[i] == ' ' || s[i] == '#')
			check_flag(i, s, ap);
		else if (s[i] == 'n' || (s[i] == 0 && s[i + 1] == 'n') || s[i] == '*')
			check_length(i, s, ap);
		else if ((s[i] == '.' && s[i + 1] == 0) ||
				(s[i] == '.' && s[i + 1] == 'n'))
			check_acc(i, s, ap);
		else if (s[i] == 'h')
}
