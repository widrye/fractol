/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 18:27:57 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 05:20:51 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strnew(size_t size)
{
	uint8_t		*buf;
	size_t		i;

	i = 0;
	if (!(buf = (uint8_t *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		buf[i] = 0;
		i++;
	}
	buf[i] = '\0';
	return ((void *)buf);
}
