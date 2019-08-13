/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 04:09:06 by pallspic          #+#    #+#             */
/*   Updated: 2019/07/06 15:03:50 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strrev - malloc and return revesed input string
*/

char	*ft_strrev(const char *str)
{
	size_t	end;
	size_t	i;
	char	c;
    char    *ret;

    ret = ft_strdup(str);
	if (!str || !*str)
		return ("");
	i = 0;
	end = ft_strlen(str) - 1;
	while (end > i)
	{
		c = str[end];
		ret[end--] = str[i];
		ret[i++] = c;
	}
	return (ret);
}
