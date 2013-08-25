#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "VerboseVector.h"
#include "AbstractSort.h"

class QuickSort : public AbstractSort
{
public:
	void msort(VerboseVector& list);

private:
	void sort(VerboseVector& list, int low, int high);
};

#endif
