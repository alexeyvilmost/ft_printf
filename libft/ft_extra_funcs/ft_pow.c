/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:47:06 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/01 16:10:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llong		ft_pow(t_llong to_raise, short power)
{
	if (power == 0)
		return (1);
	if (power > 0)
		return (to_raise * ft_pow(to_raise, power - 1));
	else
		return (ft_pow(to_raise, power + 1) / to_raise);
}

long double	ft_pow_dbl(long double to_raise, short power)
{
	if (power == 0)
		return (1L);
	else if (power > 0)
		return (to_raise * ft_pow_dbl(to_raise, power - 1));
	else
		return (ft_pow_dbl(to_raise, power + 1) / to_raise);
}
