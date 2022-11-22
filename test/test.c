/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:42:02 by samajat           #+#    #+#             */
/*   Updated: 2022/11/22 22:42:22 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

#define RED 0xff0000
#define BLUE 255
#define GREEN 0x0000FF00

#define MAP_RAW 7
#define VECT_LEN 50
#define MAP_COL 8
#define ENTITY_SIZE 50

char map[MAP_COL][MAP_RAW] = {{'1', '1', '1', '1', '1', '1', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '1', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', 'N', '0', '1'},
                {'1', '1', '1', '1', '1', '1', '1'}};
                
// void draw_rectangle(void *mlx, void *win, int x, int y)
// {
//     int i = 0;
//     int j;

//     j = 0;
//     while (i < ENTITY_SIZE)
//     {
//         j = 0;
//         while (j < ENTITY_SIZE)
//         {
//             mlx_pixel_put(mlx, win, x + j, y + i, BLUE);
//             j++;
//         }
//         i++;
//     }
// }

// int abs(float n) { return ((n > 0) ? n : (n * (-1))); }
 
// DDA Function for line generation
void draw_line(void *mlx, void *win, int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(mlx, win, X, Y, RED); // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}
 
// void draw_triangle(void *mlx, void *win, int x, int y)
// {
//     int i = 0;

//     while (i <= 100)
//     {
//         if (i % 2)
//         {
//             draw_line(mlx, win , x - i, y - i,  i * 2);
//         }
//         i++;
//     }
    
// }

// void draw_circle(void *mlx, void *win, int x, int y)
// {
//     int i = 0;
//     int j = 0;

//     while (j <= 100)
//     {
//         x+=j;
//         while (i <= 100)
//         {
//             draw_line(mlx, win , x , y + i,  1);
//             i++;
//         }
//         j++;
//     }
// }


// void draw_all(void *mlx, void *win)
// {
//     int i = 0;

//     while (i <= 400)
//     {
//         if (i % 2)
//         {
//             draw_line(mlx, win , 500 - i, 500 - i,  i * 2);
//         }
//         i++;
//     }
// }

// void    rendering_map(void *mlx, void *win)
// {
//     int i = 0;
//     while (i < MAP_COL)
//     {
//             int j = 0;
//             while (j < MAP_RAW)
//             {
//                 if (map[i][j] == '1')
//                     draw_rectangle(mlx, win, i * ENTITY_SIZE, j * ENTITY_SIZE);
//                 j++;
//             }
//             i++;
//         }
//         draw_triangle(mlx, win, 6 * ENTITY_SIZE, 5 * ENTITY_SIZE);
// }

float convert_degree_to_radian(float dgreeValue)
{
    return (dgreeValue * M_PI/180.0);
}

void rotate(void *mlx, void *win, int a, int b, int x, int y , float angle)
{
    // int x , y;
    angle = convert_degree_to_radian(angle);
    // x = a * (cos(angle)) - b * (sin(angle));
    // y = a * (sin(angle)) + b * (cos(angle));
    // x = 
    // y = 
    // draw_line(mlx, win, a, b, x, y);
    draw_line(mlx, win, a, b, a + cos(angle) * 100, b + sin(angle) * 100);
}

int main ()
{
    // {
    // void *mlx;
    // void *win;
    // double angleD = 0;
    // double angleR = convert_degree_to_radian(angleD);
    // // double angle = 90;
    // // double angle = 3*M_PI/2 - ((((3*M_PI/2) - M_PI)) / 2);

    // mlx = mlx_init();
    // win = mlx_new_window(mlx, 1000, 1000, "TEST");
    // // draw_triangle(mlx, win, 6 * ENTITY_SIZE, 5 * ENTITY_SIZE);
    
    // draw_line(mlx, win, 500, 500, 500 + cos(angleD) * 100 , 500 + sin(angleD) * 100 );    
    // // rotate(mlx, win , 500, 500, 500, 500 + sin(angle) * 200,  90);
    // // rotate(mlx, win , 500, 500, 500 + cos(angle), 500 + sin(angle),  30 - 90 );
    // rotate(mlx, win , 500, 500, 0 , 0 , angleD  - 30  );
    // rotate(mlx, win , 500, 500, 0 , 0 , angleD  + 30  );
    // // int i = angleD - 30;
    // // while (i <= angleD + 30)
    // // {
    // //     rotate(mlx, win , 500, 500, 0 , 0 , angleD + i);
    // //     i++;
    // // }
    // mlx_loop(mlx);
    // }

    
    // {
    // void *mlx;
    // void *win;
    // double angleD = 90;
    // double angleR = convert_degree_to_radian(angleD);
    // // double angle = 90;
    // // double angle = 3*M_PI/2 - ((((3*M_PI/2) - M_PI)) / 2);

    // mlx = mlx_init();
    // win = mlx_new_window(mlx, 1000, 1000, "TEST");
    // // draw_triangle(mlx, win, 6 * ENTITY_SIZE, 5 * ENTITY_SIZE);
    
    // draw_line(mlx, win, 500, 600, 500 + cos(angleR) * 100 , 600 + sin(angleR) * 100 );    
    // rotate(mlx, win , 500, 600, 0 , 0 , angleD    - 30  );
    // rotate(mlx, win , 500, 600, 0 , 0 , angleD   + 30  );
    // // int i = angleD - 30;
    // // while (i <= angleD + 30)
    // // {
    // //     rotate(mlx, win , 500, 600, 0 , 0 , angleD + i);
    // //     i++;
    // // }
    // mlx_loop(mlx);
    // }

    
    // {
    // void *mlx;
    // void *win;
    // double angleD = 180;
    // double angleR = convert_degree_to_radian(angleD);
    // // double angle = 90;
    // // double angle = 3*M_PI/2 - ((((3*M_PI/2) - M_PI)) / 2);

    // mlx = mlx_init();
    // win = mlx_new_window(mlx, 1000, 1000, "TEST");
    // // draw_triangle(mlx, win, 6 * ENTITY_SIZE, 5 * ENTITY_SIZE);
    
    // draw_line(mlx, win, 500, 600, 500 + cos(angleR) * 100 , 600 + sin(angleR) * 100 );    
    // rotate(mlx, win , 500, 600, 0 , 0 , angleD    - 30  );
    // rotate(mlx, win , 500, 600, 0 , 0 , angleD   + 30  );
    // // int i = angleD - 30;
    // // while (i <= angleD + 30)
    // // {
    // //     rotate(mlx, win , 500, 600, 0 , 0 , angleD + i);
    // //     i++;
    // // }
    // mlx_loop(mlx);
    // }
    
    {
    void *mlx;
    void *win;
    double angleD = 90;
    double angleR = convert_degree_to_radian(angleD);
    // double angle = 90;
    // double angle = 3*M_PI/2 - ((((3*M_PI/2) - M_PI)) / 2);

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "TEST");
    // draw_triangle(mlx, win, 6 * ENTITY_SIZE, 5 * ENTITY_SIZE);
    
    draw_line(mlx, win, 500, 600, 500 + cos(angleR) * 100 , 600 + sin(angleR) * 100 );    
    rotate(mlx, win , 500, 600, 0 , 0 , angleD    - 30  );
    rotate(mlx, win , 500, 600, 0 , 0 , angleD   + 30  );
    // int i = angleD - 30;
    // while (i <= angleD + 30)
    // {
    //     rotate(mlx, win , 500, 600, 0 , 0 , angleD + i);
    //     i++;
    // }
    mlx_loop(mlx);
    }
    
}