/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_set.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 05:52:00 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 16:24:05 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void    pixelit(t_image *img, int64_t y, int64_t x, int rgba)
{
	x += WIN_WIDTH / 2;
	y = WIN_HEIGHT / 2 - y;
	if (y < 0 || x < 0 || y >= WIN_HEIGHT || x >= WIN_WIDTH)
		return ;
	img->px[(y * WIN_WIDTH) + x] = rgba;
}

void    draw_axis(t_window *win)
{
	int64_t x;
	int64_t y;
	int notch;

	x = 0;
	y = -(WIN_HEIGHT / 2);
	while (++y < WIN_HEIGHT * 2)
	{
		notch = 5;
		pixelit(win->img, y, x, 0x00FF0000);
		if (!(y % (int)win->zoom))
		{
			while (notch-- > -5)
				pixelit(win->img, y, x+notch, 0x00FF0000);
		}
	}
	x = -(WIN_WIDTH / 2);
	y = 0;
	while (++x < WIN_WIDTH * 2 )
	{
		notch = 5;
		pixelit(win->img, y, x, 0x00FF0000);
		if (!(x % (int)win->zoom))
		{
			while (notch-- > -5)
				pixelit(win->img, y+notch, x, 0x00FF0000);
		}
	}
}

float	get_z_modulus(float x, float y)
{
	x *= x;
	y *= y;
	return (sqrt(x+y));
}

int32_t		get_color(int r, int g, int b, int a)
{
	int color;

	color = 0;
	color += a << 24;;
	color += r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void	color_deriv(int *r, int *g, int *b, int *a, int count)
{
	int i;

	i = 0;
	(void)*a;
	(void)*r;
	(void)count;

	if (count > 66)
	 	*r += count;
	if (count > 33 && count < 66)
	{
		while (i++ < count)
		*r += 1;
	}
	else if (count > 50)
	{
		while (i++ < count)
		*b += 2;
		*g -= 1;
	}
	if (count < 66)
		*b += count;
	i = count;
	while (i--)
	{
		if (count < 66)
		{
			*b += 1;
			*g -= 1;
		}
		*g += 4;
	}
}


void	yx_to_graph(double *y, double *x)
{
	*y = WIN_HEIGHT / 2 - *y;
	*x -= WIN_WIDTH / 2;
}

void    draw_mandelbrot(t_window *win)
{
	t_complex c;
	
	double reals;
	double magis;
	double tmp_ca;
	double tmp_cbi;
	int count;
	int r;
	int g;
	int b;
	int a;
	double halfwin_y = (WIN_HEIGHT/2);
	double halfwin_x = (WIN_WIDTH/2);

	mlx_destroy_image(win->mlx_ptr, win->img->img);
	if (!(init_imgstruct(win)))
		return ;
	c.bi = -halfwin_y - win->offsety/2;
	c.a = -halfwin_x - win->offsetx/2;
	while (c.bi <= halfwin_y - win->offsety/2)
	{
		c.a = -halfwin_x - win->offsetx/2;
		while (c.a <= halfwin_x - win->offsetx/2)
		{
			r = 0;
			g = 30;
			b = 15;
			a = 0;
			tmp_ca = c.a / win->lzoom;
			tmp_cbi = c.bi / win->lzoom;
			count = 0;
			while (count < 100)
			{
				reals = (tmp_ca * tmp_ca) - (tmp_cbi * tmp_cbi);
				magis = 2 * tmp_ca * tmp_cbi;
				tmp_ca = reals + c.a / win->lzoom;
				tmp_cbi = magis + c.bi / win->lzoom;
				if (fabs(reals + magis) > 1600)
				{
					color_deriv(&r, &g, &b, &a, count);
					pixelit(win->img, c.bi + win->offsety/2, c.a + win->offsetx/2, get_color(r, g, b, a));
					break;
				}
				count++;
			}
			if (count >= 100)
				pixelit(win->img, c.bi + win->offsety/2, c.a + win->offsetx/2, 0);
			c.a++;
		}
		c.bi++;
	}
	draw_axis(win);
}