#include <stdio.h>

typedef struct t
{
  int a;
} t;

typedef struct data
{
    t *arr;
} D;

void  func(D *ptr)
{
  printf("-->after : %p\n", ptr->arr);
}

#include <stdio.h>
#include <stdlib.h>  
int main()   
{ 
  t *test = malloc(4);
  D d;
  d.arr = test;
  printf("-->before : %p\n", d.arr);
  func(&d);
}  