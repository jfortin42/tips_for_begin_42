# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int		main(void)
{
	char	*str = strdup("salut ca va"); // length = 11 + 1
	char	*str2 = strdup("ouai nickel");

	printf("addresses          str:  [%p]\n"
		   "                   str2: [%p]\n", str, str2);

	printf("before overflow -> str:  [%s]\n"
		   "                   str2: [%s]\n", str, str2);

	//overflow
	memset(str, 'C', 18);

	printf("after overflow  -> str:  [%s]\n"
		   "                   str2: [%s]\n", str, str2);

	return (0);
}
