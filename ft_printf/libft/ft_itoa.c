/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:07:14 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/01 16:10:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(t_llong num)
{
	size_t		i;
	t_ullong	nb;
	t_ullong	mult;
	char 		*ret;

	i = 0;
	ret = ft_strnew(ft_nsize(num));
	if (!num)
	{
		ret[0] = '0';
		return (ret);
	}
	nb = (num > 0) ? num : -num;
	ret[i] = (num > 0) ? '\0' : '-' * (++i);
	mult = ft_nmult(num);
	while (mult)
	{
		ret[i++] = ft_abs(nb / mult) + '0';
		nb = ft_abs(nb) - ft_abs(nb / mult) * mult;
		mult /= 10;
	}
	ret[i] = '\0';
	return (ret);
}
