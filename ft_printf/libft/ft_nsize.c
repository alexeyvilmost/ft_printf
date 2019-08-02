/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:48:33 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/01 16:10:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_nsize_base(t_ullong n, short base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

short	ft_nsize(t_ullong n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
