/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:53:56 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/07 18:53:56 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_fill_n(t_type data, va_list arg, int printed)
{
	if (data.spec != 'n')
		return ;
	if (!data.type)
		*va_arg(arg, int *) = printed;
	else if (data.type == 'l')
		*va_arg(arg, long *) = printed;
	else if (data.type == 'L')
		*va_arg(arg, t_llong*) = printed;
	else if (data.type == 'h')
		*va_arg(arg, short *) = printed;
	else if (data.spec == 'H')
		*va_arg(arg, char *) = printed;
	else if (data.spec == 'z')
		*va_arg(arg, size_t *) = printed;
}
