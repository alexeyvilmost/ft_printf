#include "ft_printf.h"
#include <ft_printf.h>

int 	main(void)
{
	t_double db;
	db.main = 2353463.13575316943816401487;
	printf("%.0Lf\n", db.main);
	printf("%s\n", pf_double_line(db, 0));
//	printf("%s", ft_long("274", "178", '-', 0));
	return (0);
}