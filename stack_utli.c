#include "push_swap.h"

t_ref	*init_ref(int *input, int input_size)
{
	t_ref	*ret;
	int		i;

	if (!(ret = (t_ref*)malloc(sizeof(t_ref))) || \
	!(ret->a = malloc(sizeof(int*) * input_size)) || \
	!(ret->solution = malloc(sizeof(int) * input_size)))
		return (NULL);
	i = -1;
	while (++i < input_size)
	{
		ret->a[i] = input[i];
		ret->solution[i] = input[i];
	}
	ret->size = input_size;
	arr_msort(ret->solution, input_size);
	ret->prime_list = prime_list(500 * 4);
	return (ret);
}

t_stacks	*init_stacks(t_ref *ref)
{
	t_stacks	*ret;
	int			i;

	if (!(ret = malloc(sizeof(t_stacks))) || \
	!(ret->free_a = malloc(sizeof(int) * (ref->size * POO))) || \
	!(ret->free_b = malloc(sizeof(int) * (ref->size * POO))))
		return (0);
	ret->a = ret->free_a + ref->size * POO2;
	ret->b = ret->free_b + ref->size * POO2;
	ret->size_a = ref->size;
	ret->size_b = 0;
	ret->total_size = ref->size;
	i = -1;
	while (++i < ref->size)
		ret->a[i] = ref->a[i];
	return(ret);
}

void	print_stacks(t_stacks *s)
{
	printf("stack a:\n");
	for (int i = 0; i < s->size_a; i++)
		printf("%d ", s->a[i]);
	printf("\n");
	printf("stack b:\n");
	for (int i = 0; i < s->size_b; i++)
		printf("%d ", s->b[i]);
	printf("\n");
}


void	reset_stacks(t_ref *ref, t_stacks *s)
{
	int		i;

	s->a = s->free_a + ref->size * POO2;
	s->b = s->free_b + ref->size * POO2;
	s->size_a = ref->size;
	s->size_b = 0;
	i = -1;
	while (++i < ref->size)
		s->a[i] = ref->a[i];
}

void	reset_sol(t_ref *ref, t_stacks *s)
{
	int		i;

	s->a = s->free_a + ref->size * POO2;
	s->b = s->free_b + ref->size * POO2;
	s->size_a = ref->size;
	s->size_b = 0;
	i = -1;
	while (++i < ref->size)
		s->a[i] = ref->solution[i];
}

void		print_path(char *s2)
{
	char	*s[12] = {"what", "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int		i;

	i = -1;
	while (s2[++i])
		printf("%s ", s[(int)s2[i]]);
	printf("\n");
}