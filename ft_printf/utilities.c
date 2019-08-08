/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:51:28 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/08 15:04:06 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints to a standart output (amount) number of (symbol)s.
**
** Печатает в стандартный вывод (amount) (symbol)ов
*/

size_t	pf_write(int symbol, size_t amount)
{
	char	*ret;

	ret = ft_strnew(amount);
	ft_memset(ret, symbol, amount);
	write(1, ret, amount);
	free(ret);
	return (amount);
}

t_type	pf_pre_put(t_type data, _Bool neg)
{
	data.sign = neg;
	data.len = ft_strlen(data.line);
	if (data.base == 8 && data.flag[2])
		data.len += data.base / 8;
	if (data.base != 8 && data.flag[2])
		return (pf_put(data, data.len + data.base / 8, 0));
	return (pf_put(data, data.len, 0));
}

/*
** Print necessary characters depending on data (flag; size; accur) options with
** a number, presented as NULL-terminated string;
**
** Печатает число, предстваленное в виде строки, оканчивающейся \0, а также
** необходимые символы, в зависимости от представленных в data опций
*/

t_type	pf_put(t_type data, t_llong size, short f)
{
	f = (size > data.accur || data.accur < 0) ? 0 :
			(size = data.accur);
	if ((size = data.size - size) > 0 &&
			(!data.flag[0] || (data.flag[0] == O && f)))
		data.printed += pf_write(' ', size - (data.flag[1] || data.sign));
	if (data.sign)
		data.printed += write(1, "-", 1);
	else if (data.flag[1] && ft_strchr("+ ", data.flag[1]))
		data.printed += write(1, &data.flag[1], 1 + (size-- * 0));
	if (data.flag[2] == '#' && data.spec == 'o' && ft_strcmp(data.line, "0"))
		data.printed += write(1, "0", 1);
	else if (data.spec == 'p')
		data.printed += write(1, "0x", 2);
	else if (data.flag[2] == '#' && ft_strcmp(data.line, "0") && data.line[0])
		data.printed += write(1, data.spec == 'x' ? "0x" : "0X", 2);
	if (size > 0 && data.flag[0] == O && (data.accur < 0 || data.spec == 'f'))
		data.printed += pf_write(O, size - data.sign);
	data.printed += (f) ? pf_write(O, f - data.len) : 0;
	data.printed += write(1, data.line, ft_strlen(data.line));
	free(data.line);
	data.printed += (size > 0 && data.flag[0] == '-') ?
			pf_write(' ', size - data.sign) : 0;
	return (data);
}
