/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:14:25 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/01 16:10:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "ft_printf.h"

t_type	pf_put_f(t_type data, va_list arg)
{
	size_t 		i;
	size_t 		j;
	long double	l;
	t_double	he;

	if (data.accur == -1)
		data.accur = 6;
	if (data.type == 'L')
		he.ad.main = va_arg(arg, long double);
	else
		he.ad.main = (!data.type) ? (float)va_arg(arg, double) : va_arg(arg, double);
	data.line = ft_strnew(ft_nsize(ft_abs((t_llong)he.ad.main)) + data.accur + 1);
	he.expo = he.ad.mem.expo - SHIFT;
	if (!he.expo)
		return (data); // Выход в обработчик мантиссы
	he.part = (he.expo > 0) ? ft_pow(2, he.expo) : 0;
	he.expo = (SECT / ft_pow(2, he.expo));
	he.mant = he.ad.mem.mant - (t_ullong)((t_dbl)he.ad.mem.mant / (t_dbl)he.expo / 10) * he.expo;
	he.part += (t_ullong)((t_dbl)he.ad.mem.mant / (t_dbl)he.expo / 10);
	data.line = ft_strcat(data.line, ft_itoa_base(he.part, 10, 'a'));
	i = ft_strlen(data.line);
	if (data.accur)
		data.line[i++] = '.';
	else
		return (pf_put(data, data.line, i, he.ad.mem.sign));
	he.mant = he.ad.mem.mant;
	while (data.accur--)
	{
		j = 1;
		while ((he.mant / 10) > he.expo * j)
			j++;
		he.mant = (he.mant / 10) - he.expo * --j;
		if (ft_nsize(he.mant) > ft_nsize(ULLONG_MAX))
			he.mant *= 10;
		else
			he.expo /= 10;
		data.line[i++] = j + '0';
	}
	data.line[i] = '\0';
	return (pf_put(data, data.line, ft_strlen(data.line), he.ad.mem.sign));
}