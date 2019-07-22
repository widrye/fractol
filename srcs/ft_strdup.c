/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:49:53 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 05:20:51 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
