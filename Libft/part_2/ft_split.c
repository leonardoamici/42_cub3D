/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:57:08 by lamici            #+#    #+#             */
/*   Updated: 2023/07/07 15:26:25 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	sn;

	i = 0;
	sn = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			sn++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (sn);
}

static size_t	ft_superstrlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_splitter(const char *s, char c)
{
	int		i;
	int		ns;
	int		j;
	char	**str;

	j = 0;
	i = 0;
	ns = ft_count(s, c);
	str = malloc((ns + 1) * sizeof(char *));
	while (ns--)
	{
		while (s[i] != 0)
		{
			if (s[i] != c)
			{
				str[j] = ft_substr(s, i, ft_superstrlen(&s[i], c));
				i = i + ft_superstrlen(&s[i], c);
				break ;
			}
			i++;
		}
		j++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(const char *str, char c)
{
	if (str)
		return (ft_splitter(str, c));
	else
		return (NULL);
}
