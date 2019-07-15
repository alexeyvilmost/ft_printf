/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:50:08 by pallspic          #+#    #+#             */
/*   Updated: 2019/07/15 15:55:44 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	pf_newlist(void)
{
	t_type		new;

	new.size = 0;
	new.accur = 0;
	new.flag = ft_strnew(1);
	new.type = '\0';
	new.spec = '\0';
	return (new);
}

_Bool	in(const char *who, const char *what)
{
	size_t	i;

	i = 0;
	while (what[i])
	{
		if (ft_strchr(who, what[i++]))
			return (TRUE);
	}
	return (FALSE);
}

void	pf_write(int symbol, size_t amount)
{
	char *ret;

	ret = ft_strnew(amount);
	ft_memset(ret, symbol, amount);
	write(1, ret, amount);
	free(ret);
}

void	pf_putflags(t_type data, char *n, short i, short neg)
{
	short	f;

	f = (i < data.accur) ? (i = data.accur) : 0;
	if ((i = data.size - i) > 0 && !data.flag[0])
		pf_write(' ', i - 1);
	if (neg == -1)
		write(1, "-", 1);
	else if (ft_strchr("+ ", data.flag[1]))
		write(1, &data.flag[1], 1);
	else if (i > 0 && !data.flag[0])
		write(1, " ", 1);
	if (i > 0 && data.flag[0] == '0' && !data.accur)
		pf_write('0', i);
	if (f)
		pf_write('0', f - ft_strlen(n));
	write(1, n, ft_strlen(n));
	free(n);
	if (i > 0 && data.flag[0] == '-')
		pf_write(' ', i);
}

void	pf_putbase(t_type data, t_llong n, short i, short neg)
{
	char	*ret;
	char 	*buff;

	if (data.spec == 'o')
		ret = ft_itoa_base(n, 8, 0);
	else
		ret = ft_itoa_base(n, 16, (data.spec == 'x') ? 0 : 1);
	if (data.flag[1] ==  '#')
	{
		if (data.spec == 'o')
			buff = ft_strjoin("0", ret);
		else
			buff = ft_strjoin((data.spec == 'x') ? "0x" : "0X", ret);
		free(ret);
		pf_putflags(data, buff, ft_strlen(buff), 1);
		return ;
	}
	pf_putflags(data, ret, ft_strlen(ret), neg);
}

void	pf_putint(t_type data, va_list arg)
{
	int i;
	t_uint n;
	short neg;

	i = (data.spec == 'u') ? 0 : va_arg(arg, int);
	neg = (i < 0) ? -1 : 1;
	n = (data.spec == 'u') ? va_arg(arg, t_uint) : ft_abs(i);
	if (in(&data.spec, "diu"))
		pf_putflags(data, ft_itoa(n), ft_nsize(n, 10), neg);
	else if (in(&data.spec, "oxX"))
		pf_putbase(data, n, ft_nsize(n, 10), neg);
}

void	pf_putlong(t_type data, va_list arg)
{
	long i;
	t_ulong n;
	short neg;

	i = (data.spec == 'u') ? 0 : va_arg(arg, long);
	neg = (i < 0) ? -1 : 1;
	n = (data.spec == 'u') ? va_arg(arg, t_ulong) : ft_labs(i);
	if (in(&data.spec, "diu"))
		pf_putflags(data, ft_itoa(n), ft_nsize(n, 10), neg);
	else if (in(&data.spec, "oxX"))
		pf_putbase(data, n, ft_nsize(n, 10), neg);
}

void	pf_putllong(t_type data, va_list arg)
{
	t_llong i;
	t_ullong n;
	short neg;

	i = (data.spec == 'u') ? 0 : va_arg(arg, t_llong);
	neg = (i < 0) ? -1 : 1;
	n = (data.spec == 'u') ? va_arg(arg, t_ullong) : ft_llabs(i);
	if (in(&data.spec, "diu"))
		pf_putflags(data, ft_itoa(n), ft_nsize(n, 10), neg);
	else if (in(&data.spec, "oxX"))
		pf_putbase(data, n, ft_nsize(n, 10), neg);
}

void	pf_putshort(t_type data, va_list arg)
{
	short i;
	t_ushort n;
	short neg;

	i = (data.spec == 'u') ? 0 : va_arg(arg, int);
	neg = (i < 0) ? -1 : 1;
	n = (data.spec == 'u') ? va_arg(arg, t_uint) : ft_abs(i);
	if (in(&data.spec, "diu"))
		pf_putflags(data, ft_itoa(n), ft_nsize(n, 10), neg);
	else if (in(&data.spec, "oxX"))
		pf_putbase(data, n, ft_nsize(n, 10), neg);
}

void	pf_putcchar(t_type data, va_list arg)
{
	char i;
	t_uchar n;
	short neg;

	i = (data.spec == 'u') ? 0 : va_arg(arg, int);
	neg = (i < 0) ? -1 : 1;
	n = (data.spec == 'u') ? va_arg(arg, t_uint) : ft_abs(i);
	if (in(&data.spec, "diu"))
		pf_putflags(data, ft_itoa(n), ft_nsize(n, 10), neg);
	else if (in(&data.spec, "oxX"))
		pf_putbase(data, n, ft_nsize(n, 10), neg);
}

t_type		prepare_data(t_type data)
{
	char *buff;

	buff = ft_strdup(data.flag);
	if (!buff)
		return (data);
	free(data.flag);
	data.flag = ft_strnew(2);
	if (in(buff, "-0"))
		data.flag[0] = in(buff, "-") ? '-' : '0';
	if (in(&data.spec, "diu") && in(buff, "+ "))
		data.flag[1] = in(buff, "+") ? '+' : ' ';
	if (in(&data.spec, "oxX"))
		data.flag[1] = (in(buff, "#")) ? '#' : '\0';
	return (data);
}

void	pf_int_fork(t_type data, va_list arg)
{
	data = prepare_data(data);
	if (!data.type)
		pf_putint(data, arg);
	else if (data.type == 'h')
		pf_putlong(data, arg);
	else if (data.type == 'H')
		pf_putllong(data, arg);
	else if (data.type == 'l')
		pf_putshort(data, arg);
	else if (data.type == 'L')
		pf_putcchar(data, arg);
}

void	pf_putstr(t_type data, va_list arg)
{
	char	*ret;
	size_t	size;

	ret = va_arg(arg, char*);
	if (data.accur && data.accur < ft_strlen(ret))
		ret = ft_strsub(ret, 0, data.accur);
	size = ft_strlen(ret);
	if (data.size > size && !in(data.flag, "-"))
		pf_write(' ', data.size - size);
	ft_putstr(ret);
	if (data.size > size && in(data.flag, "-"))
		pf_write(' ', data.size - size);
}

void	pf_putchr(t_type data, va_list arg)
{
	char*	ret;
	char	chr;
	size_t 	size;

	chr = va_arg(arg, int);
	size = (data.size > 1) ? data.size : 1;
	ret = ft_strnew(size);
	ft_memset(ret, ' ', size);
	if ((size > 1 && in(data.flag, "-")) || size == 1)
		ret[0] = chr;
	else
		ret[data.size - 1] = chr;
	write(1, ret, ft_strlen(ret));
	free(ret);
}

void	pf_putptr(t_type data, va_list arg)
{
	short i;

	i = in(data.flag, "-");
	free(data.flag);
	data.flag = ft_strnew(2);
	data.flag[0] = i ? '-' : '\0';
	data.flag[1] = '#';
	data.type = 'L';
	data.spec = 'x';
	pf_putllong(data, arg);
}

void	pf_type_fork(t_type data, va_list arg)
{
	if (ft_strchr("diuoxX", data.spec))
		pf_int_fork(data, arg);
//	else if (data.spec == 'f')
//		pf_putflt(data, arg);
	else if (data.spec == 'c')
		pf_putchr(data, arg);
	else if (data.spec == 's')
		pf_putstr(data, arg);
	else
		pf_putptr(data, arg);
}

int 	pf_get_flags(const char *restrict s, size_t *i, va_list buff)
{
	t_type		temp;

	if (s[++(*i)] == '%')
		return (write(1, "%", 1) * 0);
	temp = pf_newlist();
	while (s[*i] && ft_strchr("-+ 0#", s[*i]) && temp.flag)
		temp.flag = ft_strjoinfree(temp.flag, &s[(*i)++], 1);
	if (s[*i] && s[*i] == '*' && (*i)++)
		temp.size = va_arg(buff, int);
	else if (s[*i] && ft_isdigit(s[*i]))
	{
		temp.size = ft_atoi(&s[*i]);
		while (s[*i] && ft_isdigit(s[*i]))
			(*i)++;
	}
	if (s[*i] && s[*i] == '.' && s[++(*i)])
	{
		if (ft_isdigit(s[*i]))
		{
			temp.accur = ft_atoi(&s[*i]);
			while (s[*i] && ft_isdigit(s[*i]))
				++(*i);
		}
		else if (s[*i] && s[*i] == '*')
			temp.accur = va_arg(buff, int);
	}
	if (s[*i] && ft_strchr("hl", s[*i]))
		temp.type = (s[*i + 1] && ft_strchr("hl", s[*i]) && s[*i] == s[*i + 1] && (*i += 2)) ? s[*i - 2] - 32 : s[*i];
	if (s[*i] && ft_strchr("cspdiouxXf", s[*i]))
	{
		temp.spec = s[*i];
		pf_type_fork(temp, buff);
		(*i)++;
		va_end(buff);
		return (TRUE);
	}
	va_end(buff);
	return (FALSE);
}

int		ft_printf(const char *restrict format, ... )
{
	size_t 	i;
	int 	j;
	va_list buffer;

	i = 0;
	if (!format)
		return (0);
	va_start(buffer, format);
	while (1)
	{
		j = ft_strfchr(&format[i], '%');
		if (j == -1)
			break ;
		write(1, &format[i], j);
		i += j;
		pf_get_flags(format, &i, buffer);
	}
	write(1, &format[i], ft_strlen(format) - i);
	va_end(buffer);
	return (1);
}

int		main(void)
{
	int i;
	int *p;

	i = 1;
	p = &i;
	ft_printf("some_text %p\n", p);
	printf("some_text %p\n", p);
	return (0);
}