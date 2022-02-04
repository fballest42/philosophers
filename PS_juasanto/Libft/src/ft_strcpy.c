/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:15:53 by juasanto          #+#    #+#             */
/*   Updated: 2022/01/10 11:08:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *string_dest, const char *string_src)
{
	int	counter;

	counter = 0;
	while (string_src[counter])
	{
		string_dest[counter] = string_src[counter];
		counter++;
	}
	string_dest[counter] = '\0';
	return (string_dest);
}
