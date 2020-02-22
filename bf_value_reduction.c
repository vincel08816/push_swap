#include "push_swap.h"
static void	bf_merge(int **arr, int size)
{
	int		i;
	int		j;
	int		k;
	int		middle;
	int		*cpy[size];

	i = -1;
	middle = size / 2 + size % 2;
	while (++i < size)
		cpy[i] = arr[i];
	i = 0;
	j = middle;
	k = 0;
	while (i < middle && j < size)
		arr[k++] = (*cpy[i] <= *cpy[j]) ? cpy[i++] : cpy[j++];
	while (i < middle)
		arr[k++] = cpy[i++];
	while (j < size)
		arr[k++] = cpy[j++];
}

void	bf_msort(int **arr, int size)
{
	if (size > 1)
	{
		bf_msort(arr, size / 2 + size % 2);
		bf_msort(arr + size / 2 + size % 2, size / 2);
		bf_merge(arr, size);
	}
}

static void	value_reduction2(int size, int **arr)
{
	int		arr2[size];
	int		i;
	int		value;

	i = -1;
	while (++i < size)
		arr2[i] = *arr[i];
	i = 0;
	value = 1;
	*arr[i] = 1;
	while (++i < size)
	{
		value += arr2[i] > arr2[i - 1];
		*arr[i] = value;
	}
}

static int	**arrofptrs(int *arr, int size)
{
	int		i;
	int		**ret;

	if (!(ret = malloc(sizeof(int*) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = arr + i;
	return (ret);
}

// I need to find the array size
void	bf_value_reduction(int *arr, int size)
{
	int		**reduce;
	int		i;
	int		value;

	reduce = arrofptrs(arr, size);
	bf_msort(reduce, size);
	i = 0;
	value_reduction2(size, reduce);
	free(reduce);
}

static void	arr_merge(int arr[], int size)
{
	int		i;
	int		j;
	int		k;
	int		middle;
	int		cpy[size];

	i = -1;
	middle = size / 2 + size % 2;
	while (++i < size)
		cpy[i] = arr[i];
	i = 0;
	j = middle;
	k = 0;
	while (i < middle && j < size)
		arr[k++] = (cpy[i] <= cpy[j]) ? cpy[i++] : cpy[j++];
	while (i < middle)
		arr[k++] = cpy[i++];
	while (j < size)
		arr[k++] = cpy[j++];
}

void	arr_msort(int arr[], int size)
{
	if (size > 1)
	{
		arr_msort(arr, size / 2 + size % 2);
		arr_msort(arr + size / 2 + size % 2, size / 2);
		arr_merge(arr, size);
	}
}
