/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 13:02:27 by jcsantos          #+#    #+#             */
/*   Updated: 2022/01/10 11:08:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *src, int chr)
{
	char	*temp_pnt;

	temp_pnt = 0;
	while (*src != 0)
	{
		if (*src == chr)
			temp_pnt = (char *)src;
		src++;
	}
	if (!chr)
		return ((char *)src);
	else if (temp_pnt)
		return (temp_pnt);
	return (NULL);
}
