/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:51:28 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/10 13:14:02 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
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
	if (data.len != 1)
		data.len = ft_strlen(data.line);
	data.add += (data.flag[1] || data.sign);
	if (!ft_strchr("oxXp", data.spec))
		data.flag[2] = '\0';
	if (!data.flag[2])
		return (pf_put(data, data.len, 0));
	if (data.spec == 'o' && ft_strcmp(data.line, "0"))
		data.len++;
	else if (data.spec == 'p')
		data.add += 2;
	else if (ft_strcmp(data.line, "0") && data.line[0])
		data.add += 2;
	return (pf_put(data, data.len, 0));
}

/*
** Print necessary characters depending on data (flag; size; accur) options with
** a number, presented as NULL-terminated string;
**
** Печатает число, предстваленное в виде строки, оканчивающейся \0, а также
** необходимые символы, в зависимости от представленных в data опций
*/

// TODO: remove extra '0' for float numbers ("%.3f", 0.000039)

t_type	pf_put(t_type data, t_llong size, short f)
{
	f = ((int)data.len > data.accur || data.accur < 0) ? 0 :
		(size = data.accur);
	if ((size = data.size - size) > data.add &&
			(!data.flag[0] || (data.flag[0] == O && data.accur != -1)))
		data.printed += pf_write(' ', size - data.add);
	if (data.sign)
		data.printed += write(1, "-", 1);
	else if (data.flag[1] && ft_strchr("+ ", data.flag[1]))
		data.printed += write(1, &data.flag[1], 1);
	if (data.flag[2] == '#' && data.spec == 'o' && ft_strcmp(data.line, "0"))
		data.printed += write(1, "0", 1);
	else if (data.spec == 'p')
		data.printed += write(1, "0x", 2);
	else if (data.flag[2] == '#' && ft_strcmp(data.line, "0") && data.line[0])
		data.printed += write(1, data.spec == 'x' ? "0x" : "0X", 2);
	if (size > data.add && data.flag[0] == O && (data.accur < 0 || data.spec == 'f'))
		data.printed += pf_write(O, size - data.add);
	data.printed += (f) ? pf_write(O, f - data.len) : 0;
	data.printed += write(1, data.line, ft_strlen(data.line));
	free(data.line);
	data.printed += (size > data.add && data.flag[0] == '-') ?
			pf_write(' ', size - data.add) : 0;
	return (data);
}

char	*pf_double_line(t_double db, int accur)
{
	char	*ret;
	char	*buff;
	t_llong expo;
	t_llong mant;
	const short	power = db.memory.expo - B127;

	expo = B23 - power;
	mant = db.memory.mant;
	if (expo < 60)
		ret = ft_long(ft_itoa(mant), ft_itoa(ft_pow(2, expo)), '/', (accur + 1) * -1);
	else
	{
		buff = ft_long(ft_itoa(mant), ft_itoa(ft_pow(2, expo - 60)), '/', 0);
		ret = ft_long(buff, ft_itoa(ft_pow(2, 60)), '/', (accur + 1) * -1);
	}
	if (power > 0)
		ret = ft_long(ret, ft_itoa(ft_pow(2, power)), '+', 2);
	else
	{
		buff = ft_long("1", ft_itoa(ft_pow(2, -power)), '/', power);
		ret = ft_long(ret, buff, '+', 2);
	}
	return (ret);
}