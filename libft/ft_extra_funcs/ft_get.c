/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:16:24 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/10 11:16:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_get - return NULL-terminated string of amount number of symbols
*/

char 	*ft_get(size_t amount, int symbol)
{
	char *nulles;

	nulles = ft_memsetloc(amount + 1, symbol);
	return (ft_strsub(nulles, 0, amount));
}