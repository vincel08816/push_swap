#include "push_swap.h"

static int		is_prime(int n)
{
	int		i;

	i = 2;
	while (i < n)
	{
		if (!(n % i))
			return (0);
		i++;
	}
	return (1);
}

int		*prime_list(int primes)
{
	int	*ret;
	int i;
	int n;

	n = 1;
	i = 0;
	ret = malloc(sizeof(int) * primes);
	
	while (i < primes)
		if (is_prime(n++))
			ret[i++] = n - 1;
	return (ret);
}

size_t		table_size(int *primes, int *sol, int size)
{
	int		i;
	size_t	sum;

	i = -1;
	sum = 0;
	while (++i < size)
		sum += primes[sol[i]] * primes[i + sol[size - 1] + size];
	return (sum);
}

char		*init_table(t_ref *ref)
{
	size_t	size;
	size_t	i;
	char	*ret;

	size = table_size(ref->prime_list, ref->solution, ref->size);
	printf("size = %zu\n", size);
	ref->pass = size;
	if (!(ret = malloc(sizeof(char) * (size + 1))))
	{
		printf("this program sucks");
		exit(1);
	}
	i = 0;
	while (i < size)
		ret[i++] = 0;
	return (ret);
}

int		add_table_entry(size_t value, char *table)
{
	if (table[value])
		return (0);
	table[value] = 1;
	return (1);
}

// // biggest is the largest number in the stacks  
// // stack a is biggest + i;
// // stack b is biggest + list size + i
// // size is the total list size

size_t		create_key(t_stacks *s, t_ref *ref, int *primes)
{
	size_t	sum;
	int		i;
	int		biggest;

	biggest = ref->solution[ref->size - 1];
	sum = 0;
	i = -1;
	while (++i < s->size_a)
		sum += primes[s->a[i]] * primes[i + biggest];
	i = -1;
	while (++i < s->size_b)
		sum += primes[s->b[i]] * primes[i + biggest + ref->size];
	return (sum);
}
