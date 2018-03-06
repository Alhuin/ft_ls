/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 16:27:16 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:27:16 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	size_t			nbmots(char const *s, char c)
{
	int		i;
	int		count;
	size_t	mots;

	mots = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count = 0;
		else if (s[i] != c && count == 0)
		{
			mots++;
			count = 1;
		}
		i++;
	}
	return (mots);
}

static	size_t			lgmot(char const *s, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

char					**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (!s || !(tab = malloc(sizeof(*tab) * (nbmots(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			if (!(tab[j] = malloc(sizeof(**tab) * (lgmot(s, i, c) + 1))))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
