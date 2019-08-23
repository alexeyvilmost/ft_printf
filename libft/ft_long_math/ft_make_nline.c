/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_nline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:32:22 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/23 20:26:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_nline(int pos, char *num)
{
	char *nulles;

	nulles = ft_get(ft_abs(pos) - 1, '0');
	if (pos > 0)
	{
		if (nulles[0])
			return (ft_strjoinfree(num, nulles, -1, 3));
		else
			return (ft_strdup(num));
	}
	else if (pos < 0)
	{
		if (nulles[0])
			return (ft_strjoinfree("0.", ft_strjoinfree(nulles, num, -1, 1), -1, 3));
		else
			return (ft_strjoinfree("0.", num, -1, 0));
	}
	else
		return (ft_strdup(num));
}