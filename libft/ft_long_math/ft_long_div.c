/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:55:52 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/23 20:26:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** l_base_div - divide one nline to the other by column division algo
*/

static char *l_base_div(char *divider, char *dividend, short accur)
{
	char	*ret;
	char 	*num[12];
	t_llong	s = 0;
	size_t	i = 0;
	t_llong	j = 1;

	num[1] = ft_strdup(dividend);
	s = accur;
	while (++j < 10)
		num[j] = ft_long(dividend, num[j - 1], '+', 0);
	ret = ft_strnew(ft_strlen(divider) + accur + 1);
	num[11] = ft_strdup(divider);
	num[0] = ft_memsetloc(ft_strlen(divider) + accur + 1, '0');
	num[10] = ft_strjoinfree(dividend, ft_strsub(num[0], 0, s++), -1, 3);
	if (ft_longcmp(num[11], num[10]) > 0)
		while (ft_longcmp(num[11], num[10]) > 0)
		{
			free(num[10]);
			num[10] = ft_strjoinfree(dividend, ft_strsub(num[0], 0, s++), -1, 3);
		}
	while (--s >= 0)
	{
		j = 10;
		num[10] = ft_strjoinfree(num[--j], ft_strsub(num[0], 0, s), -1, 3);
		while (ft_longcmp(num[11], num[10]) < 0 && j > 0)
		{
			free(num[10]);
			num[10] = ft_strjoinfree(num[--j], ft_strsub(num[0], 0, s), -1, 3);
		}
		(j > 0) ? num[11] = ft_long(num[11], num[10], '-', 2) : 0;
		ret[i++] = j + '0';
	}
	return (ret);
}

/*
** ft_long_div - prepare nline before division
*/

char    *ft_long_div(char *first, char *second, short accur)
{
    char *fst = NULL;

	fst = (accur) ? ft_strjoinfree(first, ft_get(accur, '0'), -1, 3) : ft_strdup(first);
    if (!ft_dot(first) && !ft_dot(second))
	{
    	if (!accur)
			return (l_base_div(fst, second, accur));
    	else
    		return (ft_put_dot(l_base_div(fst, second, accur), accur, 1));
	}
  	return (ft_strdup(first));
}