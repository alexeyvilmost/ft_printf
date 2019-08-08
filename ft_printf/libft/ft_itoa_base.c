/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:43:10 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/08 14:15:08 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	overbase(t_ushort n, char letter)
{
	if (n < 10)
		return (n + '0');
	else
		return (ft_isupper(letter) ? n + 55 : n + 87);
}

char		*ft_itoa_base(t_ullong num, t_ushort base, char letter)
{
	size_t		i;
	t_ullong	mult;
	char		*ret;

	i = 0;
	if (!base)
		base = 10;
	ret = ft_strnew(ft_nsize_base(num, base));
	if (!num)
	{
		ret[0] = '0';
		return (ret);
	}
	mult = ft_nmult_base(num, base);
	while (mult)
	{
		ret[i++] = overbase(num / mult, letter);
		num -= (num / mult) * mult;
		mult /= base;
	}
	ret[i] = '\0';
	return (ret);
}

/*
t_type	pf_put(t_type data, char *n, short size, short neg)
{
	short	f;

	f = (size < data.accur) ? (size = data.accur) : 0;
	if ((size = data.size - size) > 0 && (!data.flag[0] ||
										  (data.flag[0] == O && f)))
		pf_write(' ', size - 1, &data.printed);
	if (neg)
		write(1, "-", (data.printed++ * size-- * 0) + 1);
	else if (data.flag[1] && ft_strchr("+ ", data.flag[1]))
		write(1, &data.flag[1], (data.printed++ * size-- *  0) + 1);
	else if (size > 0 && (!data.flag[0]  || (data.flag[0] == O && f && data.size > f)))
		write(1, " ", (data.printed++ * size-- * 0) + 1);
	if (data.flag[2] == '#' && data.spec == 'o' && ft_strcmp(n, "0"))
		write(1, "0", (f == 0) + ((data.printed += (f == 0)) * 0));
	else if (data.spec == 'p')
		write(1, "0x", 2 + ((data.printed += 2) * 0));
	else if (data.flag[2] == '#' && ft_strcmp(n, "0") && n[0])
		write(1, data.spec == 'x' ? "0x" : "0X", 2 + ((data.printed += 2) * 0));
	if (size > 0 && data.flag[0] == O && (data.accur < 0 || data.spec == 'f'))
		pf_write(O, size, &data.printed);
	if (f)
		pf_write(O, f - ft_strlen(n), &data.printed);
	write(1, n, ft_strlen(n));
	free(n);
	if (size > 0 && data.flag[0] == '-')
		pf_write(' ', size, &data.printed);
	return (data);
}
*/