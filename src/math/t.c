#include <stdio.h>


typedef struct data
{
    int i;
    const int a ;
}D;

void    func(D d)
{
    printf("%d    %d\n", d.a, d.i);
}

int main()
{
    // const D a = {.a=45, .i=444};
    func((D){1, 1337});

    // printf("%d   %d\n", a.a, a.i);
    return 0;
}
