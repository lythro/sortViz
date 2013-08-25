#include "BubbleSort.h"

void BubbleSort::msort(VerboseVector& list)
{
	int tmp;
	bool swap;

	do
	{
		swap = false;
		for (int i = 0; i < list.size()-1; i++)
		{
			if (list[i] > list[i+1])
			{
				tmp = list[i];
				list[i] = list[i+1];
				list[i+1] = tmp;
				swap = true;
			}
		}
	} while( swap );
}
