/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clean_exit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 06:06:54 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 03:47:16 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void	ft_free_list(t_list *lst)
// {
// 	t_list	*tmp;

// 	if (lst)
// 	{
// 		while (lst)
// 		{
// 			tmp = lst;
// 			if (lst->line)
// 				free(lst->line);
// 			lst = lst->next;
// 			free(tmp);
// 		}
// 	}
// }

int		clean_exit(t_window *win)
{
	if (win)
	{
		if (win->img)
		{
			if (win->img->img)
				mlx_destroy_image(win->mlx_ptr, win->img->img);
			free(win->img);
		}
		if (win->win_ptr)
			mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		free(win);
	}
	exit(0);
}
