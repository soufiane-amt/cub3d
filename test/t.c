#include <stdio.h>
#include <math.h>


double convert_degree_to_radian(double dgreeValue)
{
    return (dgreeValue * (M_PI/180.0));
}
int	main(void)
{
	printf("--->resultValue: %f, reel value: \n", tan(convert_degree_to_radian(300)));
}