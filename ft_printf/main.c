
#include "includes/ft_printf.h"

int		main(void)
{
	t_double d;

	d.main = 3.1448684648;
	ft_printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	ft_printf("\n");
	printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	printf("\n");
	return (0);
}