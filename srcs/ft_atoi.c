/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:55:42 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 05:20:51 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_atoi(const char *str)
{
	int	ret;
	int	neg;

	ret = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		neg = (*str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - 48);
		str++;
	}
	return (neg * ret);
}
