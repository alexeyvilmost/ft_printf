/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:55:52 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/24 19:28:13 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** l_base_div - divide one nline to the other by column division algo
*/

static char *l_base_div(char *divider, char *dividend, short accur)
{
	char	*ret;
	char 	*num[10];
	char	*_div;
	char 	*temp;
	t_llong	s = 0;
	size_t	i = 0;
	t_llong	j = 1;

	num[1] = ft_strdup(dividend);
	s = accur;
	while (++j < 10)
		num[j] = ft_long(dividend, num[j - 1], '+', 0);
	ret = ft_strnew(ft_strlen(divider) + accur + 1);
	_div = ft_strdup(divider);
	temp = ft_nline(++s, dividend, 0);
	while (ft_longcmp(_div, temp) > 0)
	{
		free(temp);
		temp = ft_nline(++s, dividend, 0);
	}
	free(temp);
	while (--s >= 0)
	{
		j = 10;
		temp = ft_nline(s + 1, num[--j], 0);
		while (ft_longcmp(_div, temp) < 0 && j > 0)
		{
			free(temp);
			temp = ft_nline(s + 1, num[--j], 0);
		}
		(j > 0) ? _div = ft_long(_div, temp, '-', 1) : 0;
		free(temp);
		ret[i++] = j + '0';
	}
	j = 0;
	while (++j < 10)
		free(num[j]);
	free(_div);
	free(divider);
	return (ret);
}

/*
** ft_long_div - prepare nline before division
*/

char    *ft_long_div(char *first, char *second, short accur)
{
    char *fst = NULL;

	fst = (accur) ? ft_nline(accur + 1, first, 0) : ft_strdup(first);
    if (ft_strequ(first, "0") || ft_strequ(second, "0"))
    	return (ft_nline(-accur, "0", 0));
	if (!ft_dot(first) && !ft_dot(second))
	{
    	if (!accur)
			return (l_base_div(fst, second, accur));
    	else
    		return (ft_put_dot(l_base_div(fst, second, accur), accur, 1));
	}
  	return (ft_strdup(first));
}