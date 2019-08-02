/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 20:51:28 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/01 16:10:24 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initializes and clears the contents, returning a fresh element of t_type.
**
** Инициализирует и подготавливает содержимое, возвращая 'свежий' элемент t_type
*/

t_type	pf_new_list(void)
{
	t_type		new;

	new.size = 0;
	new.accur = -1;
	new.type = '\0';
	new.spec = '\0';
	new.line = NULL;
	new.printed = 0;
	ft_memset(new.flag, '\0', 3);
	return (new);
}

/*
** Prints to a standart output (amount) number of (symbol)s.
**
** Печатает в стандартный вывод (amount) (symbol)ов
*/

void	pf_write(int symbol, size_t amount, size_t	*printed)
{
	char	*ret;

	*printed += amount;
	ret = ft_strnew(amount);
	ft_memset(ret, symbol, amount);
	write(1, ret, amount);
	free(ret);
}

/*
** Print necessary characters depending on data (flag; size; accur) options with
** a number, presented as NULL-terminated string;
**
** Печатает число, предстваленное в виде строки, оканчивающейся \0, а также
** необходимые символы, в зависимости от представленных в data опций
*/

t_type	pf_put(t_type data, char *n, short size, short neg)
{
	short	f;

	f = (size < data.accur) ? (size = data.accur) : 0;
	if ((size = data.size - size) > 0 && (!data.flag[0] ||
			(data.flag[0] == O && f)))
		pf_write(' ', size - 1, &data.printed);
	if (neg)
		write(1, "-", (data.printed++ * size-- * 0) + 1);
	else if (data.flag[1] && ft_strchr("+ ", data.flag[1]))
		write(1, &data.flag[1], (data.printed++ * size-- *  0) + 1);
	else if (size > 0 && (!data.flag[0]  || (data.flag[0] == O && f && data.size > f)))
		write(1, " ", (data.printed++ * size-- * 0) + 1);
	if (data.flag[2] == '#' && data.spec == 'o' && ft_strcmp(n, "0"))
		write(1, "0", (f == 0) + ((data.printed += (f == 0)) * 0));
	else if (data.spec == 'p')
		write(1, "0x", 2 + ((data.printed += 2) * 0));
	else if (data.flag[2] == '#' && ft_strcmp(n, "0") && n[0])
		write(1, data.spec == 'x' ? "0x" : "0X", 2 + ((data.printed += 2) * 0));
	if (size > 0 && data.flag[0] == O && (data.accur < 0 || data.spec == 'f'))
		pf_write(O, size, &data.printed);
	if (f)
		pf_write(O, f - ft_strlen(n), &data.printed);
	write(1, n, ft_strlen(n));
	data.printed += ft_strlen(n);
	free(n);
	if (size > 0 && data.flag[0] == '-')
		pf_write(' ', size, &data.printed);
	return (data);
}