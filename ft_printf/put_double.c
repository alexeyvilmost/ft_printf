/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:14:25 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/07 18:56:20 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "ft_printf.h"

t_type	pf_put_f(t_type data, va_list arg, size_t i, size_t j) {
	int			accur;
	t_lmath		math;
	t_double	db;

	accur = (data.accur == -1) ? 6 : data.accur;
	db.main = (data.type == 'L') ? va_arg(arg, long double) : va_arg(arg, double);
	data.sign = db.memory.sign;
	data.line = ft_strnew(ft_nsize(ft_abs((t_llong) db.main)) + accur + 1);
	math.divider = db.memory.expo - B127;
	math.decimal = (math.divider >= 0) ? ft_pow(2, math.divider) : 0;
	math.divider = B23 - (db.memory.expo - B127);
	if (db.memory.expo > 0) {
		math.dividend = db.memory.mant;
		while (math.divider > 60 && --math.divider)
			math.dividend /= 2;
		math.divider = ft_pow(2, math.divider);
		if (math.divider && math.dividend > math.divider)
		{
			math.decimal += math.dividend / math.divider;
			math.dividend -= ((t_ullong) ((t_dbl) math.dividend / (t_dbl) math.divider) * math.divider);
		}
		data.line = ft_strcat(data.line, ft_itoa_base(math.decimal, 10, 'a'));
		i = ft_strlen(data.line);
		data.len = ft_strlen(data.line);
		if (!accur)
			return (pf_pre_put(data, db.memory.sign));
		data.line[i++] = '.';
		while (accur-- >= 0) {
			if (ft_nsize(math.dividend) < 20)
				math.dividend *= 10;
			else
				math.divider /= 10;
			j = 1;
			while ((t_ullong)math.dividend > math.divider * j)
				j++;
			if (--j)
				math.dividend -= math.divider * j;
			data.line[i++] = j + '0';
		}
		i--;
		if (data.line[i] && ft_isdigit(data.line[i]) && data.line[i] > '5') {
			data.line[i] = '\0';
			if (!ft_strchr(".9", data.line[i - 1]))
			{
				data.line[--i]++;
			} else {
				while (ft_strchr(".9", data.line[--i]) && i != 0)
				{
					data.line[i] == '.' ? --i : 0;
					if (data.line[i] == '9')
					{
						if (i != 0)
						{
							data.line[i] = '0';
							if (ft_isdigit(data.line[i - 1]) && data.line[i - 1] != '9')
							{
								data.line[i - 1]++;
								return (pf_pre_put(data, db.memory.sign));
							}
						}
						else
							{
							data.line[i] = '0';
							data.line = ft_strjoinfrees("1", data.line, -1);
							return (pf_pre_put(data, db.memory.sign));
						}
					}
				}
			}
		}
		data.line[i] = '\0';
	}
	return (pf_pre_put(data, db.memory.sign));
}
