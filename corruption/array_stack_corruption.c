#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[6];
	char	str2[6];
	int		i;

	memcpy(str, "salut", 6);
	memcpy(str2, "hello", 6);

	printf("addresses          str : [%p]\n"
		   "                   str2: [%p]\n", str, str2);

	printf("before overflow -> str : [%s]\n"
		   "                   str2: [%s]\n", str, str2);

	//overflow
	i = 0;
	while (i < 9)
	{
		str2[i] = 'C';
		i++;
	}

	printf("after overflow  -> str : [%s]\n"
		   "                   str2: [%s]\n", str, str2);

}
