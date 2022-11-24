/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randonTests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:53:25 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 23:41:08 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #define  $USER
#include <stdio.h>


typedef struct x
{
    int         a;
}x;

void    func(x ptr)
{
    printf("haa l value : %d", ptr.a);
}

int main ()
{
    func((x){45});
}