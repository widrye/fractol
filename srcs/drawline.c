/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   drawline.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/16 03:56:47 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 13:37:34 by widrye      ###    #+. /#+    ###.fr     */
// /*                                                         /                  */
// /*                                                        /                   */
// /* ************************************************************************** */

#include "../includes/fractol.h"

t_sline		*init_sline(t_sline *sl, int x1, int x2, int y1, int y2)
{
	sl->x = x1;
	sl->y = y1;
	sl->sx = (x1 < x2) ? 1 : -1;
	sl->sy = (y1 < y2) ? 1 : -1;
	sl->dx = abs(x2 - x1);
	sl->dy = abs(y2 - y1);
	return (sl);
}

void	draw_sline(t_image *img, t_sline *sl)
{
	int	d;
	int	e;
	int	e2;

	d = (sl->dx > sl->dy) ? sl->dx : sl->dy;
	e = (sl->dx > sl->dy) ? sl->dx : -(sl->dy) / 2;
	while (d--)
	{
		pixelit(img, sl->y, sl->x, 0x0000FF00);
		e2 = e;
		if (e2 > -(sl->dx))
		{
			e -= sl->dy;
			sl->x += sl->sx;
		}
		if (e2 < sl->dy)
		{
			e += sl->dx;
			sl->y += sl->sy;
		}
	}
}
