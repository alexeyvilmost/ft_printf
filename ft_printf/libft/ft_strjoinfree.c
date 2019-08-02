/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:53:21 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/01 16:10:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, t_cchar s2, t_llong amount)
{
	char	*new;

	if (!amount || (!*s1 && !*s2))
	{
		new = ft_strdup(s1);
		free(s1);
		return (new);
	}
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (amount != -1)
		ft_strncat(ft_strcat(new, s1), s2, amount);
	else
		ft_strcat(ft_strcat(new, s1), s2);
	free(s1);
	return (new);
}
