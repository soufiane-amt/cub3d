#include <stdio.h>


typedef struct data
{
    int i;
}D;
typedef struct element
{
  D *Dptr;
}element;

// void    func(D d)
// {
//     printf("%d    %d\n", d.a, d.i);
// }

// int func()
// {
//     return 2 > 1 ? 100 : 200;
// }
// int main()
// {
//     printf ("%d\n", func());
//     return 0;
// }
//     // const D a = {.a=45, .i=444};
//     // func((D){1, 1337});
//     // printf("%d   %d\n", a.a, a.i);

void  func(void *ptr)
{
  element *p;

  p = (element *)ptr;
  printf("%d\n", p->Dptr->i);
}

#include <stdio.h>  
int main()   
{  
  element *e;
  element l;
  D d;
  e = &l;
  d.i = 1337;
  // e->Dptr = &d;
  // func(e);
}  