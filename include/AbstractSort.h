#ifndef ABSTRACTSORT_H_
#define ABSTRACTSORT_H_

#include "VerboseVector.h"

class AbstractSort : public QObject
{
	Q_OBJECT

public:
	virtual void msort(VerboseVector& list) = 0;

//private:
	AbstractSort() { };
};

#endif
