/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randonTests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:53:25 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 12:45:07 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #define  $USER
#include <stdio.h>
#define lol "lolddd"

typedef struct x
{
    int         a;
}x;

void    func(void *ptr)
{
    
    printf("haa l value : %d\n", ((x*)ptr)->a);
}

int main ()
{
    // x   l;

    // l.a = 1337;
    func((void *)(&x){45});
}