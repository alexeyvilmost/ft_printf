/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:50:22 by pallspic          #+#    #+#             */
/*   Updated: 2019/07/14 18:44:38 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF
#define FT_PRINTF

#include "libft/libft.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

typedef struct	s_type
{
	char 		*flag;
	int			accur;
	int			size;
	char 		type;
	char 		spec;
}				t_type;

void	pf_putint(t_type data, va_list arg);
void	pf_putflt(t_type data, va_list arg);
void	pf_putstr(t_type data, va_list arg);
void	pf_putlong(t_type data, va_list arg);
void	pf_int_fork(t_type data, va_list arg);
void 	pf_putllong(t_type data, va_list arg);
void	pf_putshort(t_type data, va_list arg);
void	pf_putcchar(t_type data, va_list arg);
void	pf_putptr(t_type data, va_list arg);
void	pf_putoct(t_type data, t_llong n, short i, short neg);
void	pf_putsix(t_type data, t_llong n, short i, short neg);

#endif
