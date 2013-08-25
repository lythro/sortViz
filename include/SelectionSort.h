#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "VerboseVector.h"
#include "AbstractSort.h"

class SelectionSort : public AbstractSort
{
public:
	void msort(VerboseVector& list);
};

#endif
