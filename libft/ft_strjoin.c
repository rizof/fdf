/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:09:21 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:09:22 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	str = NULL;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	str[i + 1] = 0;
	return (str);
}
