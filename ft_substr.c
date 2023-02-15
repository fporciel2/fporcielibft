/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:54:54 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/07 17:42:24 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_slen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_l(char *sstr, char const *s, unsigned int start, size_t len)
{
	size_t	j;

	j = 0;
	if (start >= ft_slen(s))
		return (0);
	sstr = (char *)&s[start];
	while (*(sstr++) && (j < len))
		j++;
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	slen;
	size_t	i;
	size_t	j;

	if ((s == NULL) || (*s == 0))
		return (s);
	slen = ft_slen(s);
	i = start;
	sstr = NULL;
	j = ft_l(sstr, s, start, len);
	sstr = (char *)malloc(sizeof(char) * (j + 1));
	if (sstr == NULL)
		return (NULL);
	j = 0;
	while ((start < slen) && (s[i]) && (j < len))
	{
		sstr[j] = s[i];
		i++;
		j++;
	}
	sstr[j] = 0;
	return (sstr);
}