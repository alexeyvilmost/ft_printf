/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:20:26 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/01 16:10:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ullong	ft_nmult_base(t_ullong to_count, short base)
{
	size_t	mult;

	mult = 1;
	while (to_count /= base)
		mult *= base;
	return (mult);
}

t_ullong	ft_nmult(t_ullong to_count)
{
	size_t	mult;

	mult = 1;
	while (to_count /= 10)
		mult *= 10;
	return (mult);
}
