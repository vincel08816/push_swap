// # include "push_swap.h"


// t_stacks	*create_stacks(int size, char **av)
// {
// 	t_stacks	*new;
// 	int			i;
// 	int			j;

// 	i = 1;
// 	if ((!(new = malloc(sizeof(t_stacks)))) && \
// 	!(new->free_a = malloc(sizeof(int) * size * 20)) && \
// 	!(new->free_b = malloc(sizeof(int) * size * 20)))
// 		return NULL;
// 	j = size * 11;
// 	new->a = i + j;
// 	new->b = i + j;
// 	while (i < size)
// 		new->a[i + j] = ft_atoi(av[i]);
// 	new->size_a = size;
// 	new->size_b = 0;
// 	return (new);
// }

// int			check_instruction(char *av)
// {
// 	char	**fnlist;
// 	int		i;

// 	i = 0;
// 	fnlist = (char**){"sa\n","sb\n", "ss\n", \
// 			"pa\n", "pb\n", \
// 			"ra\n", "rb\n", "rr\n", \
// 			"rra\n", "rrb\n", "rrr\n"};
// 	while (fnlist[i])
// 		if (!ft_strcmp(fnlist, av))
// 			return (1);
// 	return (0);
// }

// void		selector(t_stacks *stacks, char *s)
// {
// 	(!ft_strcmp("sa", s) ? sa(s) : 0);
// 	(!ft_strcmp("sb", s) ? sb (s) : 0);
// 	(!ft_strcmp("ss", s) ? ss(s) : 0);
// 	(!ft_strcmp("pa", s) ? pa(s) : 0);
// 	(!ft_strcmp("pb", s) ? pb(s) : 0);
// 	(!ft_strcmp("ra", s) ? ra(s) : 0);
// 	(!ft_strcmp("rb", s) ? rb(s) : 0);
// 	(!ft_strcmp("rr", s) ? rr(s) : 0);
// 	(!ft_strcmp("rra", s) ? rra(s) : 0);
// 	(!ft_strcmp("rrb", s) ? rrb(s) : 0);
// 	(!ft_strcmp("rrr", s) ? rrr(s) : 0);
// }
// t_intarr	*iarrdup(int *a, int size)
// {
// 	t_intarr	*b;
// 	int			i;

// 	if (!(b = malloc(sizeof(t_intarr))) ||
// 		!(b->arr = malloc(sizeof(int))))
// 		return (NULL);
// 	i = -1;
// 	b->size = size;
// 	while (++i < size)
// 	{
// 		b->arr[i] = a[i];
// 	}
// 	return (b);
// }

// int		arr_cmp(int *a, int *b, int size)
// {
// 	int i;

// 	i = -1;
// 	while (++i < size)
// 	{
// 		if (a[i] != b[i])
// 			return (0);
// 	}
// 	return (1);
// }

// int		main(int ac, char **av)
// {
// 	t_intarr	*solution;
// 	t_stacks	*states;
// 	int			j;
// 	int 		i;
// 	t_node		*instructions;

// 	i = 1;
// 	while (av[i][j] && av[i])
// 	{
// 		while (ft_strchr("123456789\n", av[i][j]))
// 			j++;
// 		i++;
// 	}
// 	j = i;
// 	if (!(av[i] == 0) && !ft_strchr("spr", av[i][0]))
// 	{
// 		ft_putstr("Error\n");
// 		return 0;
// 	}
// 	while (check_instructions(av[i]))
// 		i++;
// 	if (av[i] != 0)
// 	{
// 		ft_putstr("Error\n");
// 		return 0;
// 	}
// 	states = create_stacks(j, av);
// 	solution =iarrdup(states->a, states->size_a);
// 	i = j;
// 	while (i < av - 1)
// 	{
// 		selector(states, av[i]);
// 		i++;
// 	}
// 	ft_putstr(arr_cmp(states->a, solution->arr, j) ? "OK" : "KO");
// }
