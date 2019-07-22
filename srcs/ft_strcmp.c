/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 00:05:32 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 01:56:37 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	i = 0;
	s1_uc = (unsigned char*)s1;
	s2_uc = (unsigned char*)s2;
	while (s1_uc[i] && s2_uc[i] && s1_uc[i] == s2_uc[i])
		i++;
	return (s1_uc[i] - s2_uc[i]);
}