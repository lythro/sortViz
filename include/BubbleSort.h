#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include "VerboseVector.h"
#include "AbstractSort.h"

class BubbleSort : public AbstractSort
{
public:
	void msort(VerboseVector& list);
};

#endif
