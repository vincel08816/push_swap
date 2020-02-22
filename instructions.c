#include "push_swap.h"
// typedef struct s_stacks
// {
// 	short		*a;
// 	short		*b;
// 	int		size_a;
// 	int		size_b;
// }				t_stacks;

// typedef void	t_f(t_stacks *s);


// void	sa(t_stacks *s);
// void	sb(t_stacks *s);
// void	ss(t_stacks *s);
// void	pa(t_stacks *s);
// void	pb(t_stacks *s);
// void	ra(t_stacks *s);
// void	rb(t_stacks *s);
// void	rr(t_stacks *s);
// void	rra(t_stacks *s);
// void	rrb(t_stacks *s);
// void	rrr(t_stacks *s);

void		sa(t_stacks *s)
{
	int	tmp;

	tmp = *(s->a + 1);
	*(s->a + 1) = *(s->a);
	*(s->a) = tmp;
}

void		sb(t_stacks *s)
{
	int	tmp;

	tmp = *(s->b + 1);
	*(s->b + 1) = *(s->b);
	*(s->b) = tmp;
}

void		ss(t_stacks *s)
{
	sa(s);
	sb(s);
}

void		pa(t_stacks *s)
{
	--s->b;
	*((s->b)) = *((s->a));
	++s->a;
	s->size_a--;
	s->size_b++;
}

void		pb(t_stacks *s)
{
	--s->a;
	*((s->a)) = *((s->b));
	++s->b;
	s->size_b--;
	s->size_a++;
}

/*
**	first element becomes the last element
*/

void		rra(t_stacks *s)
{
	(s->a)--;
	*(s->a) = *(s->a + s->size_a);
}
void		rrb(t_stacks *s)
{
	(s->b)--;
	*(s->b) = *(s->b + s->size_b);
}
void		rrr(t_stacks *s)
{
	rra(s);
	rrb(s);
}

/*
**	last element becomes the first one
*/

void		ra(t_stacks *s)
{
	*(s->a + s->size_a) = *(s->a);
	(s->a)++;
}

void		rb(t_stacks *s)
{
	*(s->b + s->size_b) = *(s->b);
	(s->b)++;
}

void		rr(t_stacks *s)
{
	ra(s);
	rb(s);
}

/*	Steps required to make this function

		1.)	value reduction (just use merge sort on an array of integer pointers then change it to increasing order)
		(this is done)
		2.)	stack creation (use the small arr for normal stuff and reallocate a big one?)
		(this is done)
		2b)	create hash_table functions
		3.)	pathlist creation (linked list and adding)
			a.) I'm going to use the libft struct s_list structure
			b.)	going to cast the void * to char *
			c.) and list size lol is the list size
		4.)	instead of re-allocating just resetting the array back to the middle
*/
int asdf = 0;
static size_t		from_beginning(t_pq *paths, t_ref *ref, t_stacks *s, t_hash *h_table)
{
	char	*options;
	size_t	key;

	asdf++;
	if (paths->cur && paths->cur->list)
		apply_path(paths->cur->list,  s);
	key = create_key(s, ref, ref->prime_list);
	if (h_table->end[key])
	{
		printf("from_beginning");
		print_stacks(s);
		return (key);
	}
	if (!(paths->head))
	{
		options = path_options(s, 0);
		h_table->begin[key] = 1;
		append_new_paths(paths, options);
	}
	if (!h_table->begin[key])
		append_new_paths(paths, options);
	paths->cur = paths->cur->next;
	return (0);
}

static size_t		from_end(t_pq *paths, t_ref *ref, t_stacks *s, t_hash *h_table)
{
	char	*options;
	size_t	key;

	asdf++;
	if (paths->cur && paths->cur->list)
		apply_path(paths->cur->list,  s);
	key = create_key(s, ref, ref->prime_list);
	// printf("b\tasdf = %d, key = %zu\n", asdf, key);
	if (key == 3904)
	{
		printf("from end: key = 3904\n");
		if (paths->cur && paths->cur->list)
			print_path(paths->cur->list);
		print_stacks(s);
	}
	if (h_table->begin[key])
	{
		printf("from end");
		print_stacks(s);
		return (key);
	}
	if (!(paths->head))
	{
		options = path_options(s, 0);
		h_table->end[key] = 1;
		append_new_paths(paths, options);
	}
	if (!h_table->end[key])
		append_new_paths(paths, options);
	paths->cur = paths->cur->next;
	return (0);
}


char	*solver(t_ref *ref, t_stacks *s, t_hash *h_table)
{
	int			layer;
	t_pq		paths;
	t_pq		path2;
	char		*ret;
	size_t		hit;
	t_stacks	*s2 = init_stacks(ref);

	int i = -1;
	while (++i < ref->size)
		s2->a[i] = ref->solution[i];
	paths = (t_pq){0, 0, 0};
	path2 = (t_pq){0, 0, 0};
	layer = 0;
	while (layer < 10000000000)
	{
		reset_stacks(ref, s);
		reset_sol(ref, s2);
		if (hit = from_beginning(&paths, ref, s, h_table))
		{
			print_stacks(s);
			break;
		}
		if (hit = from_end(&path2, ref, s2, h_table))
			break;
		layer++;
	}
	printf("\n\nlayer = %d, key = %zu\n", layer, hit);
	printf("%ld, %ld\n\n", ft_strlen(paths.cur->list), ft_strlen(path2.cur->list));
	// for (paths)
	exit (1);
	//search previous layer of the function to find the corresponding match
}

#include <stdio.h>

int		main(void)
{
	// int arr[] = {4591, -8642, -6791,   828, -8584,  2022,  4387, -3229,  -506};
	int arr[] = {10,9,1,6,5,4,3,3,2,1};
	t_ref		*ref;
	t_stacks	*s;
	t_hash		h_table;
	char		*init;

	/*	hash table, init reference, and init stacks	*/
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	bf_value_reduction(arr, arr_size);
	ref = init_ref(arr, arr_size);
	s = init_stacks(ref);
	h_table = (t_hash){init_table(ref), init_table(ref)};
	ref->pass = create_key((t_stacks[]){0,0,ref->solution, 0, 0, 0, 0}, ref, \
	ref->prime_list);
	printf("ref_size = %d", ref->size);
	// printf("%ld,n", create_key((t_stacks[]){0,0,ref->solution, 0, 0, 0, 0}, ref, \
	ref->prime_list));
	solver(ref, s, &h_table);
}
