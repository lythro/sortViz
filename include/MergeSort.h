#ifndef MERGESORT_H_
#define MERGESORT_H

#include "AbstractSort.h"
#include "VerboseVector.h"

class MergeSort : public AbstractSort
{
public:
	void msort(VerboseVector& list);

private:
	void msort(VerboseVector& list, int l, int r);
};

#endif
