#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define POO 5000
#define POO2 2500

typedef struct s_intarr
{
	int		size;
	int		*arr;
}		t_intarr;

typedef struct	s_ref
{
	int	*a;
	int size;
	int	*prime_list;
	int *solution;
	size_t	pass;
}				t_ref;

typedef struct s_stacks
{
	int		*free_a;
	int		*free_b;
	int		*a;
	int		*b;
	int		total_size;
	int		size_a;
	int		size_b;
}				t_stacks;

typedef struct	s_paths
{
	char	*list;
	int		len;
	struct s_paths *next;
}				t_paths;

typedef struct	s_pq
{
	t_paths	*head;
	t_paths *cur;
	t_paths	*end;
}				t_pq;

typedef struct	s_hash
{
	char	*begin;
	char	*end;
}				t_hash;

typedef void	t_move(t_stacks *s);

void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	ss(t_stacks *s);
void	pa(t_stacks *s);
void	pb(t_stacks *s);
void	ra(t_stacks *s);
void	rb(t_stacks *s);
void	rr(t_stacks *s);
void	rra(t_stacks *s);
void	rrb(t_stacks *s);
void	rrr(t_stacks *s);

static t_move *moves[12] = {NULL, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

void	bf_value_reduction(int *arr, int size);
void	bf_msort(int **arr, int size);
void	arr_msort(int arr[], int size);

void	reset_stacks(t_ref *ref, t_stacks *s);
void	reset_sol(t_ref *ref, t_stacks *s);
t_stacks	*init_stacks(t_ref *ref);
t_ref	*init_ref(int *input, int input_size);
void	print_stacks(t_stacks *s);

int		*prime_list(int primes);
size_t		table_size(int *primes, int *sol, int size);
char		*init_table(t_ref *ref);

size_t		create_key(t_stacks *s, t_ref *ref, int *primes);



char	*path_options(t_stacks *s, t_paths *path);
t_paths	*create_new_path(t_paths *cur, char a);
void	*append_new_paths(t_pq *paths, char *options);
void	apply_path(char *cur_path, t_stacks *s);
void		print_path(char *s2);

// ra ra ra pa rra rra rra sb pb  solution
#endif