/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:02:31 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/10 09:08:59 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "ft_printf.h"

/*
** Main int fork, deciding which function to send data for processing
**
** Главная развилка целых чисел, решающая, в какую функцию отправить для
** обработки
*/

t_type	pf_put_n(t_type data, va_list arg, t_llong i, t_ullong n)
{
	if (data.type == 'L')
		n = ft_strchr(USIGN, data.spec) ? va_arg(arg, t_ullong)
				: ft_abs(i = va_arg(arg, t_llong));
	else if (data.type == 'l' || data.type == 'z')
		n = ft_strchr(USIGN, data.spec) ? va_arg(arg, t_ullong) :
				ft_abs(i = va_arg(arg, long long));
	else if (data.type == 'H')
		n = ft_strchr(USIGN, data.spec) ? (t_uchar)va_arg(arg, int) :
			ft_abs(i = (char)va_arg(arg, int));
	else if (data.type == 'h')
		n = ft_strchr(USIGN, data.spec) ? (t_ushort)va_arg(arg, int) :
				ft_abs(i = (short)va_arg(arg, int));
	else
		n = ft_strchr(USIGN, data.spec) ? va_arg(arg, t_uint) :
			ft_abs(i = va_arg(arg, int));
	if (ft_strchr("oxXp", data.spec))
		data.base = (data.spec == 'o') ? 8 : 16;
	data.line = (!n && !data.accur) ? ft_strnew(0) :
			ft_itoa_base(n, data.base, data.spec);
	return (pf_pre_put(data, ft_strchr(USIGN, data.spec) ? 0 : (i < 0)));
}

// TODO: nubmbers lower than 1 don't works ("%f", 0.0894255)

/*
t_type	pf_put_f(t_type data, va_list arg, size_t i, size_t j)
{
	int			accur;
	t_lmath		math;
	t_double	db;

	accur = (data.accur == -1) ? 6 : data.accur;
	db.main = (data.type == 'L') ? va_arg(arg, long double) :
		va_arg(arg, double);
	data.line = ft_strnew(ft_nsize(ft_abs((t_llong)db.main)) + accur + 1);
	data = pf_long_math(&math, db, data, &i);
	if (!data.accur)
		return (pf_pre_put(data, db.memory.sign));
	while (accur-- >= 0)
	{
		if (ft_nsize(math.dividend) < 20)
			math.dividend *= 10;
		else
			math.divider /= 10;
		j = 1;
		while ((t_ullong)math.dividend > math.divider * j)
			j++;
		math.dividend -= (j - 1) ? math.divider * (j - 1) : 0;
		data.line[i++] = (j - 1) + '0';
	}
	i--;
	if (!(data.line[i] && ft_isdigit(data.line[i]) &&
				data.line[i] > '5') && !(data.line[i] = '\0'))
		return (pf_pre_put(data, db.memory.sign));
	data.line[i] = '\0';
	return (pf_rounding(data, i, db));
}
*/

t_type pf_put_f(t_type data, va_list arg)
{
	int 		accur;
	t_lmath		math;
	t_double	db;
	char 		*buff;

	accur = (data.accur == -1) ? 6 : data.accur;
	db.main = (data.type == 'L') ? va_arg(arg, t_ldouble) : va_arg(arg, double);
	data.line = ft_strnew(ft_nsize(ft_abs((t_llong)db.main)) + accur + 1);
//	data = pf_double_line(math, db, data, accur);
	if (!data.accur)
		return (pf_pre_put(data, db.memory.sign));
	if (data.line[data.len - 1] < '5')
	{
		data.line[data.len--] = '\0';
		return (pf_pre_put(data, db.memory.sign));
	}
	buff = ft_strnew(data.len - ft_dot(data.line));
	ft_memset(buff, '0', data.len - ft_dot(data.line));
	buff[ft_strlen(buff) - 1] = '1';
	buff = ft_strjoinfree("0.", buff, -1, 3);
	data.line = ft_long(data.line, buff, '+', 3);
	data.line[data.len--] = '\0';
	return (pf_pre_put(data, db.memory.sign));
}

t_type	pf_put_s(t_type data, va_list arg)
{
	size_t	size;

	data.line = va_arg(arg, char*);
	if (!data.line)
		data.line = ft_strdup("(null)");
	else
		data.line = ft_strdup(data.line);
	if (data.accur >= 0 && data.accur < (int)ft_strlen(data.line))
		data.line = ft_strsub(data.line, 0, data.accur);
	size = ft_strlen(data.line);
	if (data.size > (int)size && data.flag[0] != '-')
		pf_write(' ', data.size - size);
	ft_putstr(data.line);
	data.printed += ft_strlen(data.line);
	free(data.line);
	if (data.size > (int)size && data.flag[0] == '-')
		pf_write(' ', data.size - size);
	if (data.size > (int)size)
		data.printed += data.size - size;
	return (data);
}

t_type	pf_put_c(t_type data, va_list arg)
{
	char	chr;
	size_t	size;

	chr = (data.spec == 'c') ? va_arg(arg, int) : '%';
	size = (data.size > 1) ? data.size : 1;
	data.line = ft_strnew(size);
	if (data.flag[0] == '0')
		ft_memset(data.line, '0', size);
	else
		ft_memset(data.line, ' ', size);
	if ((size > 1 && data.flag[0] == '-') || size == 1)
		data.line[0] = chr;
	else
		data.line[data.size - 1] = chr;
	write(1, data.line, size);
	data.printed += size;
	free(data.line);
	return (data);
}

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
