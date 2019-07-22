/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 09:32:09 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/30 15:52:19 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"


int		deal_key(int key, t_window *win)
{
	if (key == 53)
		return (0);
	if (key == 15)
	{
		win->cursor->x = WIN_WIDTH/2;
		win->cursor->y = WIN_HEIGHT/2;
		win->o_x = WIN_WIDTH/2;
		win->o_y = WIN_HEIGHT/2;
		win->zoom = SCALE;
		win->lzoom = SCALE;
		win->offsety = 0;
		win->offsetx = 0;
	}
	return (1);
}

int		key_event(int key, t_window *win)
{
	if (!deal_key(key, win))
		clean_exit(win);
	draw_mandelbrot(win);
	return (1);
}

void	display_pos(int x, int y, int zoom)
{
	double y2;
	double x2;

	printf("You clicked:\ny = %d\nx = %d\n", y, x);
	y2 = y;
	x2 = x;
	yx_to_graph(&y2, &x2);
	y2 /= zoom;
	x2 /= zoom;
	printf("On graph :\ny = %f\nx = %f\n--------------\n", y2, x2);
}

int		mouse_event(int button, int x, int y, t_window *win)
{
	(void)win;
	if (button == 1)
		display_pos(x, y, win->zoom);
	if (button == 4)
	{
		win->lzoom = win->zoom;
		win->zoom *= 1.2;
		win->o_x = x;
		win->o_y = y;
		win->offsety += y - (WIN_HEIGHT/2);
		win->offsetx += (WIN_WIDTH/2) - x;
		printf("button = %d, zoom = %f\n", button, win->zoom);
		printf("mouse o_y = %f, mouse o_x = %f\n--------------\n", win->o_y, win->o_x);
	}
	else if (button == 5 && win->zoom > SCALE)
	{
		win->lzoom = win->zoom;
		win->zoom *= 0.9;
		win->o_x = x;
		win->o_y = y;
		// win->offsety += y - (WIN_HEIGHT/2);
		// win->offsetx += (WIN_WIDTH/2) - x;
		printf("button = %d, zoom = %f\n", button, win->zoom);
	}
	draw_mandelbrot(win);
	return (1);
}