/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:08:40 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:08:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *cpy;

	cpy = NULL;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy != NULL)
		ft_strcpy(cpy, src);
	return (cpy);
}
