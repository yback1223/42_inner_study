/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:10:53 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 14:16:14 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length_of_word(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	count_word(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*putting_word(char *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = length_of_word(str, c);
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**split;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!str)
		return (0);
	len = count_word(str, c);
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (0);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			split[i++] = putting_word(str, c);
		while (*str && *str != c)
			str++;
	}
	split[i] = 0;
	return (split);
}
