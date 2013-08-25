#include "QuickSort.h"

void QuickSort::msort(VerboseVector& list)
{
	sort(list, 0, list.size()-1);
}

void QuickSort::sort(VerboseVector& list, int low, int high)
{
	int i = low;
	int j = high;
	int mid = (low + high)/2;
	int x = list[mid];

	do
	{
		while (list[i] < x) i++;
		while (list[j] > x) j--;

		if (i <= j)
		{
			int tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;

			i++;
			j--;
		}

	} while( i <= j);

	if (low < j) sort(list, low, j);
	if (high > i) sort(list, i, high);

	list[high];
}
