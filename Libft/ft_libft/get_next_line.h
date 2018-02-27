/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 22:45:31 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/22 20:56:40 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 6
# define FDMAX 126
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>

typedef struct			s_gnl
{
	char				*str;
	int					fd;
}						t_gnl;

int						get_next_line(const int fd, char **line);
#endif
