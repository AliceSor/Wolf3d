/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:01:08 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/22 19:48:37 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		init(t_data *d)
{
	if (d)
	{
		d->mlx = create_win();
		d->h  = 1;
		create_image(d->mlx);
        d->posX = 22;
        d->posY = 12;
        d->dirX = -1;
        d->dirY = 0;
        d->planeX = 0;
        d->planeY = 0.66;
        d->moveSpeed = 1;
        d->rotSpeed = 5 * RAD;
        createMap(d);
	}
}

int				main(void)
{
//	int			isParse;
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data) + 10);
	init(data);
	//
	//isParse = parseMap(data);
	//
	//if (isParse == -1)
	//{
	//	errorMessage();
	//	return (0);
	//}
	//
	rayCasting(data); //finished
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->im, -1, -1);
	//
	mlx_hook(data->mlx->win, 2, 5, buttons, data);
	mlx_hook(data->mlx->win, 17, 0, destroy, 0);
	mlx_loop(data->mlx->mlx);
	return (0);
}


//int main()
//{
//    t_data		*data;
//
//	data = (t_data *)malloc(sizeof(t_data) + 10);
//	init(data);
//
//    double posX = 22, posY = 12;  //x and y start position
//    double dirX = -1, dirY = 0; //initial direction vector
//    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
//
//
//    for(int x = 0; x < WIDTH; x++)
//    {
//        //calculate ray position and direction
//        double cameraX = 2 * x / (WIDTH) - 1; //x-coordinate in camera space
//        double rayPosX = posX;
//        double rayPosY = posY;
//        double rayDirX = dirX + planeX * cameraX;
//        double rayDirY = dirY + planeY * cameraX;
//
//        //which box of the map we're in
//        int mapX = (int)rayPosX;
//        int mapY = (int)rayPosY;
//
//        //length of ray from current position to next x or y-side
//        double sideDistX;
//        double sideDistY;
//
//        //length of ray from one x or y-side to next x or y-side
//        double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
//        double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
//        double perpWallDist;
//
//        //what direction to step in x or y-direction (either +1 or -1)
//        int stepX;
//        int stepY;
//
//        int hit = 0; //was there a wall hit?
//        int side; //was a NS or a EW wall hit?
//
//        //calculate step and initial sideDist
//        if (rayDirX < 0)
//        {
//            stepX = -1;
//            sideDistX = (rayPosX - mapX) * deltaDistX;
//        }
//        else
//        {
//            stepX = 1;
//            sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
//        }
//        if (rayDirY < 0)
//        {
//            stepY = -1;
//            sideDistY = (rayPosY - mapY) * deltaDistY;
//        }
//        else
//        {
//            stepY = 1;
//            sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
//        }
//
//        //perform DDA
//        while (hit == 0)
//        {
//            //jump to next map square, OR in x-direction, OR in y-direction
//            if (sideDistX < sideDistY)
//            {
//                sideDistX += deltaDistX;
//                mapX += stepX;
//                side = 0;
//            }
//            else
//            {
//                sideDistY += deltaDistY;
//                mapY += stepY;
//                side = 1;
//            }
//            //Check if ray has hit a wall
//            if (worldMap[mapX][mapY] > 0) hit = 1;
//        }
//
//        //Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
//        if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
//        else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
//
//        int h = 64;
//        //Calculate height of line to draw on screen
//        int lineHeight = (int)(h / perpWallDist);
//
//        //calculate lowest and highest pixel to fill in current stripe
//        int drawStart = -lineHeight / 2 + h / 2;
//        if(drawStart < 0)drawStart = 0;
//        int drawEnd = lineHeight / 2 + h / 2;
//        if(drawEnd >= h)drawEnd = h - 1;
//
//        //choose wall color
////        ColorRGB color;
////        int color;
////        switch(worldMap[mapX][mapY])
////        {
////            case 1:  color = 0xFF0000;  break; //red
////            case 2:  color = 0x00FF00;  break; //green
////            case 3:  color = 0x0000FF;   break; //blue
////            case 4:  color = 0xFFFFFF;  break; //white
////            default: color = 0xFF00FF; break; //yellow
////        }
////
////        //give x and y sides different brightness
////        if (side == 1) {color = color / 2;}
////
////        //draw the pixels of the stripe as a vertical line
//////        verLine(x, drawStart, drawEnd, color);
////        for (int i = drawStart; i <= drawEnd; i++)
////        {
////            putPixel(x, i, color, data->mlx);
////        }
//        putImage(data);
//    }
//    putImage(data);
//    mlx_loop(data->mlx->mlx);
//}