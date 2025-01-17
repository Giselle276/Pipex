/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-28 10:42:52 by gmaccha-          #+#    #+#             */
/*   Updated: 2024-12-28 10:42:52 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	unsigned const char	*tmp_src;

	tmp_dest = (unsigned char *) dest;
	tmp_src = (unsigned const char *) src;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (n > 0)
	{
		*(tmp_dest++) = *(tmp_src++);
		n--;
	}
	return (dest);
}
