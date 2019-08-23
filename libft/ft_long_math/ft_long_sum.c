/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 00:36:56 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/23 20:26:12 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** l_base_sum - add one nline to other with column addition algo
*/

static char	*l_base_sum(char *main, char *add, t_llong i, t_llong j)
{
	short 	rest;
	char 	*ret;

	rest = 0;
	if (ft_strlen(add) > ft_strlen(main))
		return (l_base_sum(add, main, j, i));
	ret = ft_strdup(main);
	while (i >= 0 && j >= 0)
	{
		if (main[i] == add[j] && add[j] == '.' && j-- && i--)
			continue;
		rest += ret[i] + add[j--] - 96;
		ret[i--] = (rest % 10) + '0';
		rest /= 10;
	}
	if (i >= 0 && rest)
		ret[i] += rest;
	else if (rest)
		ret = ft_strjoinfree("1", ret, -1, 3);
	return (ret);
}

/*
** ft_long_sum - prepares nlines before addition
*/

char		*ft_long_sum(char *main, char *add)
{
	char 	*main_ = NULL;
	char 	*add_ = NULL;
	char 	*nulles;

	if (ft_after_dot(main) == ft_after_dot(add))
		return (l_base_sum(main, add, ft_strlen(main) - 1, ft_strlen(add) - 1));
	if (!ft_dot(main))
		main_ = ft_strjoinfree(main, ".0", -1, 0);
	else if (!ft_dot(add))
		add_ = ft_strjoinfree(add, ".0", -1, 0);
	(!main_) ? main_ = ft_strdup(main) : 0;
	(!add_) ? add_ = ft_strdup(add) : 0;
	nulles = ft_memsetloc(ft_after_dot(main) > ft_after_dot(add) ?
			ft_after_dot(main) : ft_after_dot(add), '0');
	if (ft_after_dot(main_) < ft_after_dot(add_))
		main_ = ft_strjoinfree(main_,ft_strsub(nulles, 0, ft_after_dot(add_) -
			ft_after_dot(main_)), -1, 3);
	else
		add_ = ft_strjoinfree(add_, ft_strsub(nulles, 0, ft_after_dot(main_) -
			ft_after_dot(add_)), -1, 3);
	free(nulles);
	nulles = l_base_sum(main_, add_, ft_strlen(main_) - 1, ft_strlen(add_) - 1);
	free(main_);
	free(add_);
	return (nulles);
}