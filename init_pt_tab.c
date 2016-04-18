/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pt_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 16:08:04 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/18 16:49:51 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_pt_tab(char *(**types)(va_list *arg, char *buffer, int *tab))
{
	types[1] = &get_int;
	types[2] = &get_octal;
	types[3] = &get_int_ns;
	types[4] = &get_hexa_low;
	types[5] = &get_hexa_up;
	types[6] = &get_double;
	types[7] = &get_scient;
	types[8] = &get_scient_up;
	types[9] = &get_shorter;
	types[10] = &get_shorter_up;
	types[11] = &get_char;
	types[12] = &get_str;
	types[13] = &get_point;
	types[14] = &get_binary;
	types[15] = &check_percent;
}

void	init_diez_tab(char *(**diez)(char *tmp, char *buffer, int *tab))
{
	diez[2] = &get_octal;
	diez[4] = &get_hexa_low;
	diez[5] = &get_hexa_up;
	diez[6] = &get_double;
	diez[7] = &get_scient;
	diez[8] = &get_scient_up;
	diez[9] = &get_shorter;
	diez[10] = &get_shorter_up;
}
