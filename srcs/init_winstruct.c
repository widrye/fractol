/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_winstruct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/27 00:27:53 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/30 06:35:23 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		init_imgstruct(t_window *win)
{
	if (!(win->img = malloc(sizeof(t_image))))
		return (0);
	if (!(win->img->img = mlx_new_image(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (0);
	if ((win->img->px = (uint32_t *)mlx_get_data_addr(win->img->img, &win->img->bpp,
					&win->img->bypl, &win->img->endian)) == NULL)
		return (0);
	return (1);
}

int		init_winstruct(t_window *win, char set)
{
	if ((win->mlx_ptr = mlx_init()) == NULL)
		return (0);
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (!(win->cursor = malloc(sizeof(t_cursor))))
		return (0);
	win->cursor->y = 0;
	win->cursor->x = 0;
	if (win->mlx_ptr == NULL)
		return (0);
	win->zoom = SCALE;
	win->lzoom = SCALE;
	win->speed = 1;
	win->offsety = 0;
	win->offsetx = 0;
	win->o_x = WIN_WIDTH/2;
	win->o_y = WIN_HEIGHT/2;
	win->set = set;
	win->img = NULL;
	return (1);
}

