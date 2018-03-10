#include "ft_ls.h"

int			ascii_sort(t_file *to_sort, t_file *node)
{
	return (ft_strcmp(to_sort->name, node->name));
}

int			rev_ascii_sort(t_file *to_sort, t_file *node)
{
	return (ft_strcmp(node->name, to_sort->name));
}

int			time_sort(t_file *to_sort, t_file *node)
{
    if (to_sort->sb.st_mtimespec.tv_sec == node->sb.st_mtimespec.tv_sec)
        return (node->sb.st_mtimespec.tv_nsec - to_sort->sb.st_mtimespec.tv_nsec);
    else
        return (node->sb.st_mtimespec.tv_sec - to_sort->sb.st_mtimespec.tv_sec);
}

int			rev_time_sort(t_file *to_sort, t_file *node)
{
	if (to_sort->sb.st_mtimespec.tv_sec == node->sb.st_mtimespec.tv_sec)
        return (to_sort->sb.st_mtimespec.tv_nsec - node->sb.st_mtimespec.tv_nsec);
    else
        return (to_sort->sb.st_mtimespec.tv_sec - node->sb.st_mtimespec.tv_sec);
}


int			err_sort(t_file *to_sort, t_file *node)
{
	if (!(to_sort->error) && node->error)
		return (1);
	else if (to_sort->error && !(node)->error)
		return (-1);
	else
		return (0);
}
