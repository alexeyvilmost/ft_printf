/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:37:37 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/10 13:02:23 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: puts '/' sometimes

static char	*l_base_diff(char *main, char *diff, t_llong i, t_llong j)
{
	short 	rest;
	char 	*ret;

	rest = 0;
	if (ft_longcmp(main, diff) < 0)
		return (l_base_diff(diff, main, j, i));
	ret = ft_strdup(main);
	while (i >= 0 && j >= 0)
	{
		(diff[j] == '.') ? i -= (j-- * 0) + 1 : 0;
		rest = ret[i] - diff[j] - rest;
		if (ret[i] < diff[j] || (ret[i] == diff[i] && rest < 0))
			rest += 20;
		ret[i--] = (rest % 10) + '0';
		j--;
		rest /= 10;
	}
	if (rest && i >= 0)
	{
		rest /= 10;
		ret[i]--;
	}
	return (ret);
}

char		*ft_long_diff(char *main, char *add)
{
	char 	*main_ = NULL;
	char 	*add_ = NULL;
	char 	*ret_ = NULL;

	if (ft_after_dot(main) == ft_after_dot(add))
		return (l_base_diff(main, add, ft_strlen(main) - 1, ft_strlen(add) - 1));
	if (!ft_dot(main))
		main_ = ft_strjoinfree(main, ".0", -1, 0);
	else if (!ft_dot(add))
		add_ = ft_strjoinfree(add, ".0", -1, 0);
	(!main_) ? main_ = ft_strdup(main) : 0;
	(!add_) ? add_ = ft_strdup(add) : 0;
	if (ft_after_dot(main_) < ft_after_dot(add_))
		main_ = ft_strjoinfree(main_, ft_get(ft_after_dot(add_) -
		ft_after_dot(main_), '0'), -1, 3);
	else
		add_ = ft_strjoinfree(add_, ft_get(ft_after_dot(main_) -
		ft_after_dot(add_), '0'), -1, 3);
	ret_ = l_base_diff(main_, add_, ft_strlen(main_) - 1, ft_strlen(add_) - 1);
	free(main_);
	free(add_);
	return (ret_);
}