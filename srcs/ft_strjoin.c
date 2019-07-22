/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 21:09:16 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 05:20:51 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buf;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	if (!(buf = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(buf, (char *)s1);
	ft_strcat(buf, (char *)s2);
	return (buf);
}
