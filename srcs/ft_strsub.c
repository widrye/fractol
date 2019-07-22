/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 19:48:04 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 09:15:07 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		buf[i] = (char)s[start];
		start++;
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
