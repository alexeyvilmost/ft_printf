
#include <ft_printf.h>
#include "includes/ft_printf.h"

int		main(void) {
	char *s = "!%0 7.27zi!";
	char *sl = "This is |%s| a simple test.";
	char *s3 = "|%p";
	char *test1 = "111%s333";
	char *test2 = "222";
	char *s1 = "aa%%bb";
	char *s2 = "%c%c";
	int *p = 0x0;
	int n[2];
	int i = -3;

	t_double d;
	d.ad.main = 5.5;
if (0) {

	//================# LONG MATH ALGORITHM #===============================
		printf("\n%lu\n%llu\n", d.ad.mem.mant, SECT);
		printf("%Lf, %lu, %hu, %hhd\n", d.ad.main, d.ad.mem.mant, d.ad.mem.expo, d.ad.mem.sign);
		printf("Mantiss: %lf\n", (double) d.ad.mem.mant / (double) SECT / 10);
		printf("%c%lld * %lf\n", (d.ad.mem.sign) ? '-' : '+', ft_pow(2, d.ad.mem.expo - SHIFT), (double) d.ad.mem.mant / SECT / 10);
		printf("Number in {%lld:%lld}\n\n", ft_pow(2, d.ad.mem.expo - SHIFT), ft_pow(2, d.ad.mem.expo - SHIFT + 1));
	}
	//================# STANDART ALGORITHM #==================================
	if (1)
	{
		printf("\n%c1 * (2^%hu - 16383) * 1,%Lf == %Lf\n\n", (d.ad.mem.sign) ? '-' : '+', d.ad.mem.expo, (t_dbl)d.ad.mem.mant / 1844674407370955200, d.ad.main);
	}



	if (0) {
		n[0] = printf("%.25Lf\n", ft_pow_dbl(2, -i));
		printf("|\n");
		n[1] = ft_printf("%f", 'a');
		printf("|\n");
		printf("%d - %d\n", n[0], n[1]);
		return (0);
	}
}
 /*
int				main(void)
{
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	return (0);
} */