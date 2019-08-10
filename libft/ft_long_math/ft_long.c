/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:43:39 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/10 11:30:07 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char 	*ft_long(char *first_num, char *second_num, char option, short free_or_acc)
{
	t_llong		i;
	char 		*ret;
	char 		*result;

	if (option == '+')
		ret = ft_long_sum(first_num, second_num);
	else if (option == '-')
		ret = ft_long_diff(first_num, second_num);
	else
		ret = ft_long_div(first_num, second_num, free_or_acc < 0 ? ft_abs(free_or_acc) : 0);
	i = 0;
	while (ret[i] == '0')
		i++;
	result = ret[i] ? ft_strsub(ret, i, ft_strlen(ret) - i) : ft_strdup("0");
	free(ret);
	if (result[0] == '.')
		result = ft_strjoinfree("0", result, -1, 3);
	if (free_or_acc > 1)
		free(first_num);
	if (free_or_acc > 0 && free_or_acc < 3)
		free(second_num);
	return (result);
}

/*
** !!!<ATTENTION>!!!
** to_free param works that way:
** -0: ft_abs(to_free) - is accur
** 0: do nothing
** 1: free only first_num
** 2: free both
** 3: free only second_num
** 4+: do nothing
 * "0.00000000000009999341886080801486968994140625"
 * "0.000000000000000001"
*/