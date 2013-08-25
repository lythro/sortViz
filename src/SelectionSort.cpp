#include "SelectionSort.h"

void SelectionSort::msort(VerboseVector& list){
	for (int i = 0; i < list.size(); i++)
	{
		int pos = i;
		int min = list[i];
			for (int j = i+1; j < list.size(); j++)
		{
			if (list[j] < min)
			{
				min = list[j];
				pos = j;
			}
		}

		list[pos] = list[i];
		list[i] = min;
	}
}
