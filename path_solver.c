#include "push_swap.h"

static void	remove_options(char options[], char remove[], int rm_size)
{
	int		i;

	i = -1;
	while (remove[++i])
	{
		options[(int)remove[i]] = 0;
	}
}

static char	*create_path_options(char *options)
{
	int		size;
	char	*ret;
	int		i;

	size = 0;
	i = 0;
	while (++i < 12)
		if (options[i])
			size++;
	ret = 0;
	if (!(ret = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = 0;
	i = 0;
	size = 0;
	while (++i < 12)
	{
		if (options[i])
			ret[size++] = (char)i;
	}
	return (ret);
}

/*
**	implement a 60/30 for push-swap ?
**	pa and pb removes the counterparts
**	sa, sb, ss itself
**	ra -> no {rra/rr/rrr/rb}
**	rb -> no {rrb/rr/rrr/ra}
**	rr -> no rrr, rrb, rra, ra, rb
**	rra -> no ra, rr, rrr, rrb
**	rrb -> no rb, rr, rrr, rra 
**	rrr-> rr, rb, ra, rra, rrb
*/

char	*path_options(t_stacks *s, t_paths *path)
{
	char	options[12];
	int		i;
	char	*prev;

	i = -1;
	while (++i < 11)
		options[i] = 1;
	options[0] = 0;
	if (!(s->size_a))
		remove_options(options, (char[]){1, 3, 4, 6, 8, 9, 11}, 7);
	if (!(s->size_b))
		remove_options(options, (char[]){2, 3, 5, 7, 8, 10, 11}, 7);
	if (!path)
		return (create_path_options(options));
	prev = path->list + path->len - 2;
	if (s->size_a <= 1)
		remove_options(options, (char[]){1, 3, 6, 8, 9, 11}, 6);
	if (s->size_b <= 1)
		remove_options(options, (char[]){2, 3, 7, 8, 10, 11}, 6);
	if ((*prev >= 1 && *prev <= 3 ))
		remove_options(options, (char[]){1, 2, 3}, 3);
	else if (*prev == 4 || *prev == 5)
		remove_options(options, (char[]){*prev == 4 ? 5 : 4}, 1);
	else if (*prev == 6)
		remove_options(options, (char[]){7, 8, 9, 11}, 1);
	else if (*prev == 7)
		remove_options(options, (char[]){6, 8, 10, 11}, 4);
	else if (*prev == 8)
		remove_options(options, (char[]){6, 7, 9, 10, 11}, 5);
	else if (*prev == 9)
		remove_options(options, (char[]){6, 8, 10, 11}, 4);
	else if (*prev == 10)
		remove_options(options, (char[]){7, 8, 9, 11}, 4);
	else if (*prev == 11)
		remove_options(options, (char[]){6, 8, 9, 10}, 4);
	return (create_path_options(options));
}

t_paths	*create_new_path(t_paths *cur, char append)
{
	t_paths *ret;
	char	*s;

	ret = 0;
	if (!(ret = malloc(sizeof(t_paths))) || \
	!(s = malloc(sizeof(char *) * (cur->len + 2))))
		return (NULL);
	if (cur->list)
		ft_strcpy(s, cur->list);
	s[cur->len] = append;
	s[cur->len + 1] = 0;
	*ret = (t_paths){s, cur->len + 1, 0};
	return (ret);
}

void	*append_new_paths(t_pq *paths, char *options)
{
	int		i;
	t_paths	*tmp;

	i = 0;
	if (!paths->head)
	{
		tmp = create_new_path(&(t_paths){0, 0, 0}, options[i]);
		*paths = (t_pq){tmp, tmp, tmp};
		while (options[++i])
		{
			tmp->next = create_new_path(&(t_paths){0, 0, 0}, options[i]);
			tmp = tmp->next;
		}
		paths->end = tmp;
	}
	else
	{
		tmp = create_new_path(paths->cur, options[i]);
		paths->end->next = tmp;
		while (options[++i])
		{
			tmp->next = create_new_path(paths->cur, options[i]);
			tmp = tmp->next;
		}
		paths->end = tmp;
	}
}

void	apply_path(char *cur_path, t_stacks *s)
{
	int		i;

	i = -1;
	if (!cur_path)
		return ;
	while (cur_path[++i])
		moves[(int)cur_path[i]](s);
}
