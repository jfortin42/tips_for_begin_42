# include <stdio.h>
# include <string.h>

int		main(void)
{
	struct
	{
		char	buffer[8];
		int		after;
	}			data;

	memcpy(data.buffer, "~hello~", 8);
	data.after = 42;

	printf("addresses          [%p]\n"
		   "                   [%p]\n", data.buffer, &data.after);

	printf("before overflow -> [%s]\n"
		   "                   [%d]\n", data.buffer, data.after);

	//overflow
	memcpy(data.buffer, "abcdefghijklmno", 12);

	printf("after overflow  -> [%s]\n"
		   "                   [%d]\n", data.buffer, data.after);

	return (0);
}
