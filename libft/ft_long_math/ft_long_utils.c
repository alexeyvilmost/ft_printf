/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 00:11:05 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/10 11:25:42 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dot(const char *str)
{
	int	i;

	i = ft_strfchr(str, '.');
	if (i == -1)
		return (0);
	return (i);
}

size_t	ft_after_dot(const char *str)
{
	if (!ft_dot(str))
		return (0);
	return (ft_strlen(str) - ft_dot(str) - 1);
}

int 	ft_longcmp(t_cchar n1, t_cchar n2)
{
	const size_t	dot1 = ft_dot(n1);
	const size_t	dot2 = ft_dot(n2);
	size_t 			len1;
	size_t 			len2;

	len1 = (dot1) ? dot1 : ft_strlen(n1);
	len2 = (dot2) ? dot2 : ft_strlen(n2);
	if (len1 == len2)
		return (ft_strcmp(n1, n2));
	return (len1 > len2 ? 1 : -1);
}

char	*ft_rm_dot(char	*str, _Bool to_free)
{
	size_t	dot;
	char 	*ret;

	dot = ft_dot(str);
	ret = ft_strjoinfree(ft_strsub(str, 0, dot),
			ft_strsub(str, dot + 1, ft_strlen(str) - dot - 1), -1, 2);
	if (to_free)
		free(str);
	return (ret);
}

char 	*ft_put_dot(char *str, size_t where, _Bool to_free)
{
	char 	*ret = NULL;
	char 	*buff = NULL;
	const size_t len = ft_strlen(str);
	size_t	a;

	if (len)
	{
		buff = (len > where) ? ft_strdup(str) :
				ft_strjoinfree(ft_get(where - len, '0'), str, -1, 1);
		a = ft_abs(len - where);
		ret = ft_strjoinfree(ft_strsub(buff, 0, a),
				ft_strjoinfree(".",
				ft_strsub(buff, a, len), -1, 3), -1, 2);
	}
	if (to_free)
		free(str);
	return (ret);
}