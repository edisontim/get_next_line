/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:52:46 by tedison           #+#    #+#             */
/*   Updated: 2021/04/14 11:27:32 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_malloc(char **str, int size, int bytes)
{
	int	i;

	i = 0;
	*str = malloc(size);
	if (!(*str))
		return (0);
	while (i <= bytes)
	{
		(*str)[i] = 0;
		i++;
	}
	return (1);
}

int	ft_strlen(char *s, unsigned long *set1, unsigned long *set2)
{
	int	i;

	i = 0;
	*set1 = 0;
	*set2 = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char					*final;
	unsigned long int		final_l;
	unsigned long int		s1_l;
	unsigned long int		i;
	unsigned long int		j;

	s1_l = ft_strlen((char *) s1, &i, &j);
	final_l = s1_l + ft_strlen((char *)s2, &i, &j);
	if (!ft_malloc(&final, sizeof(*final) * final_l + 1, 0))
		return (NULL);
	while (i < final_l)
	{
		if (i < s1_l)
			final[i] = s1[i];
		else
		{
			if (s2[j] == '\n')
				break ;
			final[i] = s2[j++];
		}
		final[++i] = 0;
	}
	free((char *)s1);
	return (final);
}

int	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}

char	*ft_strdup(char *s1, char *s2)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s1[i])
		i++;
	copy = malloc(sizeof(*copy) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	free(s2);
	return (copy);
}
