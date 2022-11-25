/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randonTests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:53:25 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 11:39:25 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #define  $USER
#include <stdio.h>
#define lol "lolddd"

typedef struct x
{
    int         a;
}x;

void    func(char *ptr)
{
    printf("haa l value : %s\n", ptr);
}

int main ()
{
    int a = 45;
    float b = 4.4548745f;

    int sum = a + b;
    printf("%d\n", sum);
}