#ifndef _QUICKSORT_H
#define _QUICKSORT_H

template<typename Type>
class Quicksort {	
	Quicksort() {}
	static int partition(Type** arr, int left_index, int right_index);
	static void swap(Type** arr, int left_index, int right_index);
public:	
	static void sort(Type** arr, int start, int end);

};

#endif // !_QUICKSORT_H

template<typename Type>
inline int Quicksort<Type>::partition(Type** arr ,int left_index, int right_index)
{
	auto pivot = arr[right_index];
	int push_index = left_index;

	for (int i = left_index; i < right_index; ++i)
	{
		if (arr[i] < pivot)
		{
			swap(arr, i, push_index);
			push_index++;
		}
	}
	swap(arr, push_index, right_index);
	return push_index;
}

template<typename Type>
inline void Quicksort<Type>::swap(Type** arr, int left_index, int right_index)
{
	auto temp_var = arr[left_index];
	arr[left_index] = arr[right_index];
	arr[right_index] = temp_var;
}

template<typename Type>
inline void Quicksort<Type>::sort(Type** arr, int start, int end)
{
	int* stack = new int[end - start + 1];
	int top = -1;

	stack[++top] = start;
	stack[++top] = end;

	while (top >= 0)
	{			
		end = stack[top--];
		start = stack[top--];
		int pivot_index = partition(arr, start, end);

		if (pivot_index - 1 > start)
		{
			stack[++top] = start;
			stack[++top] = pivot_index - 1;
		}

		if (pivot_index + 1 < end)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = end;
		}
	}

	delete[] stack;
}
