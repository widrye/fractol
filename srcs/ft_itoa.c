/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 17:50:06 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 05:20:51 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		itoasize(int nb, int size)
{
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int value)
{
	char			*it;
	const char		buff[10] = "0123456789";
	long			nb;
	int				neg;
	size_t			size;

	neg = value < 0 ? 1 : 0;
	nb = value < 0 ? (long)value * -1 : (long)value;
	size = value != 0 ? 0 : 1;
	size = itoasize(nb, size);
	size += neg;
	if (!(it = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	it[0] = '0';
	it[size] = 0;
	nb = value < 0 ? (long)value * -1 : (long)value;
	while (nb)
	{
		it[--size] = buff[nb % 10];
		nb /= 10;
	}
	it[0] = value < 0 ? '-' : it[0];
	return (it);
}
