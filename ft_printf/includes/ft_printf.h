/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:50:22 by pallspic          #+#    #+#             */
/*   Updated: 2019/08/08 16:23:57 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF
#define FT_PRINTF

#include "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

# define B23 63
# define B127 16383
# define USIGN "uoxXp"
# define O '0'

/*
** ============================# Structures #===================================
*/

/*
** ----------------------+ t_type +--------------------------
** %[flag][size][.accur][type][spec]
** data.flag[0]: '-' or '0' (mutually exclusive)
** data.flag[1]: '+' or ' ' (mutually exclusive)
** data.flag[2]: '#'
** data.type - 'L' for ll; 'H' for hh; the same char for other
** data.line: string representation that will be displayed
** data.printed: number of displayed characters
** -----------------------------------------------------------
*/

typedef struct	s_type
{
	char 		flag[3];
	int			size;
	int			accur;
	char 		type;
	char 		spec;
	char		*line;
	short 		base;
	_Bool		sign;
	size_t		len;
	size_t 		printed;
}				t_type;

/*
** ---------------------+ t_lmath +--------------------------
*/

typedef struct		s_lmath
{
	t_llong			decimal;
	t_llong			divider;
	t_llong			dividend;
}					t_lmath;


/*
** ----------------------+ t_double +--------------------------
** main - the main container of ldouble value
** memory - represented here \/
** [sign : 1][expo : 15][mant : 64]
** -------------------------------------------------------------
*/

typedef	union
{
	long double		main;
	struct
	{
		t_ulong		mant : 63;
		t_ushort	expo : 15;
		_Bool		sign : 1;
	}				memory;
}					t_double;

/*
** ===============================# other.c #==================================
*/
t_type	pf_long_math(t_lmath *math, t_double db, t_type data, size_t *i);
t_type	pf_rounding(t_type data, size_t i, t_double db);
t_type	pf_pre_put(t_type data, _Bool neg);
t_type	pf_put(t_type data, t_llong size, short f);
size_t	pf_write(int symbol, size_t amount);

/*
** =============================# ft_printf.c #=================================
*/

int		ft_printf(const char *restrict format, ... );

/*
** =================================# put.c #====================================
*/

t_type	pf_put_c(t_type data, va_list arg);
t_type	pf_put_s(t_type data, va_list arg);
t_type	pf_put_f(t_type data, va_list arg, size_t i, size_t j);
t_type	pf_put_n(t_type data, va_list arg, t_llong i, t_ullong n);
void	pf_fill_n(t_type data, va_list arg, int printed);

#endif
