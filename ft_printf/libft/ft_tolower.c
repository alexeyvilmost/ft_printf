/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:11:05 by pallspic          #+#    #+#             */
/*   Updated: 2019/07/06 15:03:50 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
		return (ch + 32);
	return (ch);
}
