/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 14:00:54 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 14:00:44 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_checkcolor(char *str)
{
	char *out;

	out = NULL;
	if (ft_strncmp(str, "{red}", 5) == 0)
		out = ft_strdup("\033[31m");
	else if (ft_strncmp(str, "{black}", 7) == 0)
		out = ft_strdup("\033[30m");
	else if (ft_strncmp(str, "{blue}", 6) == 0)
		out = ft_strdup("\033[34m");
	else if (ft_strncmp(str, "{white}", 7) == 0)
		out = ft_strdup("\033[37m");
	else if (ft_strncmp(str, "{cyan}", 6) == 0)
		out = ft_strdup("\033[36m");
	else if (ft_strncmp(str, "{bcyan}", 6) == 0)
		out = ft_strdup("\033[1;36m");
	else if (ft_strncmp(str, "{yellow}", 8) == 0)
		out = ft_strdup("\033[33m");
	else if (ft_strncmp(str, "{magenta}", 9) == 0)
		out = ft_strdup("\033[35m");
	else if (ft_strncmp(str, "{green}", 7) == 0)
		out = ft_strdup("\033[32m");
	return (out);
}

static char		*ft_strreplace1(char *dst, char *src, int start, int end)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(dst) - (end - start) + ft_strlen(src);
	if (!(ret = malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 0;
	while (i < start)
	{
		ret[i] = dst[i];
		i++;
	}
	while (src[j])
		ret[i++] = src[j++];
	while (dst[++end])
		ret[i++] = dst[end];
	ret[i] = '\0';
	ft_strdel(&dst);
	return (ret);
}

static char		*ft_strreplace3(char *dst, char *src, int start, int end)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(dst) - (end - start) + ft_strlen(src);
	if (!(ret = malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 0;
	while (i < start)
	{
		ret[i] = dst[i];
		i++;
	}
	while (src[j])
		ret[i++] = src[j++];
	while (dst[++end])
		ret[i++] = dst[end];
	ret[i] = '\0';
	ft_strdel(&dst);
	return (ret);
}

int				ft_colorlen(char *str)
{
	int		i;
	int		j;
	int		ret;
	char	*check;

	j = 0;
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '{')
		{
			if ((check = ft_checkcolor(str + i)) != NULL)
			{
				if (str[i + 1] == 'b' && str[i + 2] == 'c')
					ret += 2;
				j++;
			}
			ft_strdel(&check);
		}
		i++;
	}
	return (j * 8 + ret);
}

char			*ft_color(char *str)
{
	int		i;
	int		j;
	char	*code;

	i = 0;
	while (str[i])
	{
		if (str[i] == '{')
		{
			j = 0;
			if ((code = ft_checkcolor(str + i)) != NULL)
			{
				while (str[i + j] != '}')
					j++;
				str = ft_strreplace3(str, code, i, i + j);
			}
			else if (ft_strncmp(str + i, "{eoc}", 5) == 0)
			{
				str = ft_strreplace1(str, "\033[m", i, i + 4);
			}
			ft_strdel(&code);
		}
		i++;
	}
	return (str);
}
