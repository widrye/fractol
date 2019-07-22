/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 23:34:07 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/30 00:59:42 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"


void    display_usage(void)
{
	write(2, "usage: ./fractol [-set]\n\t\t \
	[-j] Julia set\n\t\t [-m] Mandelbrot set\n", 65);
	exit(0);
}

char    check_arg(int ac, char **av)
{
	char    set[3];
	int     i;

	i = 0;
	set[0] = 'j';
	set[1] = 'm';
	set[2] = 'x';
	if (ac != 2)
		display_usage();
	while (set[i])
	{
		if (set[i] == av[1][1])
			return (set[i]);
		i++;
	}
	display_usage();
	return ('\0');
}

static int		mouse_pos(int x, int y, t_cursor *mouse)
{
	mouse->x = x;
	mouse->y = y;
	return (0);
}

static int		loop(t_window *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
	return (0);
}

int     main(int ac, char **av)
{
	t_window  *win;

	char      set;
	// sleep(10);
	set = check_arg(ac, av);
	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (-1);
	if (!init_winstruct(win, set) || !init_imgstruct(win))
		clean_exit(win);
	draw_mandelbrot(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
	mlx_hook(win->win_ptr, 6, 1L<<6, &mouse_pos, win->cursor);
	mlx_hook(win->win_ptr, 2, 3, key_event, win);
	mlx_mouse_hook(win->win_ptr, mouse_event, win);
	mlx_loop_hook(win->mlx_ptr, &loop, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}