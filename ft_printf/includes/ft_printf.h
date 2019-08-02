/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:50:22 by pallspic          #+#    #+#             */
/*   Updated: 2019/07/31 15:23:20 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF
#define FT_PRINTF

#include "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

# define SECT 1844674407370955200
# define SHIFT	16383
# define USIGN "uoxXp"
# define O '0'

/*
** ============================# Structures #===================================
*/

/*
** ----------------------+ t_type +--------------------------
** %[flag][size][.accur][type][spec]
** data.flag[0]: '-' or '0'
** data.flag[1]: '+' or ' '
** data.flag[2]: '#'
** data.type - 'L' for ll; 'H' for hh;
** data.line: string that will be displayed
** data.printed: for each spec - number of displayed characters
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
	size_t 		printed;
}				t_type;

/*
** ----------------------+ t_double +--------------------------
** struct.part - integer value of double presicion number
** struct.expo - dynamic divider to handle long math
** struct.mant - dynamic dividend to handle long math
** struct.ad - union for working with memory
** ad.main - the main container of ldouble value
** ad.mem - represented here \/
** [sign : 1][expo : 15][mant : 64]
** -------------------------------------------------------------
*/

typedef	struct			s_double
{
	t_ullong			part;
	t_ullong			expo;
	t_ullong			mant;
	union
	{
		long double		main;
		struct
		{
			t_ulong		mant : 64;
			t_ushort	expo : 15;
			_Bool		sign : 1;
		}				mem;
	}					ad;
}						t_double;

/*
** =============================# utilities.c #=================================
*/

t_type	pf_new_list(void);
t_type	pf_put(t_type data, char *n, short i, short neg);
void	pf_write(int symbol, size_t amount, size_t *printed);

/*
** =============================# ft_printf.c #=================================
*/

int		ft_printf(const char *restrict format, ... );

/*
** ============================# put_number.c #=================================
*/

t_type	pf_put_c(t_type data, va_list arg);
t_type	pf_put_f(t_type data, va_list arg);
t_type	pf_put_s(t_type data, va_list arg);
t_type	pf_put_num(t_type data, va_list arg);
void	pf_put_n(t_type data, va_list arg, int printed);

#endif
