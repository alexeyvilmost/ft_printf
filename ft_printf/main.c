
#include "includes/ft_printf.h"

int		main(void)
{
	int n[2];

	n[0] = ft_printf("%#.3o", 1);
	ft_printf("\n");
	n[1] = printf("%#.3o", 1);
	printf("\n");
	printf("%d - %d", n[0], n[1]);
	return (0);
}