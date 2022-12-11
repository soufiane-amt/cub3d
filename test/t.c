#include <stdio.h>



#define x func()

void	func()
{
	printf("--->\n");
}

int	main(void)
{
	x;
}