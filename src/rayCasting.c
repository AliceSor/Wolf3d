/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:58:28 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/22 19:38:57 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

//static double	castRay(t_data *data, double angle)
//{
//	double		dist, distHor, distVer;
//
//	distHor = rayHorizontal(data, angle);
//	distVer = rayVertical(data, angle);
//
//	dist = (distVer < distHor) ? distVer : distVer;
//	return (dist);
//}

void			rayCasting(t_data *data)
{
//	int		x;
//	double		dist;
//	double		angleCurrent;
//
//	x = 0;
//
////	angleCurrent = PLAYER->dir - PLAYER->fov / 2;
////	printf("angleCurrent[%f]" , angleCurrent);
//	while (x < WIDTH)
//	{
//		dist = castRay(data, angleCurrent);
//		printf("[%f]\n", dist);
//		dist *= cos(angleCurrent * RAD);
//		putColumn(data, x, dist);
//		x++;
//		angleCurrent += PLAYER->anglIncrement;
//		// printf("angleCurrent[%f]" , angleCurrent);
//	}
    int		x;
    x = 0;
    while (++x < WIDTH)
    {
        double cameraX = 2 * x / (double)(WIDTH) - 1; //x-coordinate in camera space
        double rayPosX = data->posX;
        double rayPosY = data->posY;
        double rayDirX = data->dirX + data->planeX * cameraX;
        double rayDirY = data->dirY + data->planeY * cameraX;
        int mapX = (int)rayPosX;
        int mapY = (int)rayPosY;
        double sideDistX;
        double sideDistY;
        double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
        double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
        double perpWallDist;
        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;
        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit?

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (rayPosX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (rayPosY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
        }

        side = 0;
        while (hit == 0)
        {
            //jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            //Check if ray has hit a wall
            if (data->map[mapX][mapY] > 0)
            {
                // printf("[%d]", data->map[mapX][mapY]);
                hit = 1;
            }
            // printf("%d", mapX);
        }
        if (side == 0)
            perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
        //Calculate height of line to draw on screen
        int lineHeight = (int)(HEIGHT / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = (int)(-lineHeight / 2 + HEIGHT / 2);
        // printf("[%f]", perpWallDist);
        if(drawStart < 0)
            drawStart = 0;
        int drawEnd = (int)(lineHeight / 2 + HEIGHT / 2);
        if(drawEnd >= HEIGHT)
            drawEnd = (int)(HEIGHT - 1);

        int color;
        switch(data->map[mapX][mapY])
        {
            case 1:  color = 0xFF0000;  break; //red
            case 2:  color = 0x00FF00;  break; //green
            case 3:  color = 0x0000FF;   break; //blue
            case 4:  color = 0xFFFFFF;  break; //white
            default: color = 0xFF00FF; break; //yellow
        }

        //give x and y sides different brightness
        if (side == 1)
        {
            color = color / 2;
        }

//        color -= 0.9 * perpWallDist;

        //draw the pixels of the stripe as a vertical line
        for (int i = drawStart; i <= drawEnd; i++)
        {
            putPixel(x, i, color, data->mlx);
        }
    }
}