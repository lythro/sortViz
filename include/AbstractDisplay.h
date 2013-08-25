#ifndef ABSTRACTDISPLAY_H_
#define ABSTRACTDISPLAY_H_

#include "VerboseVector.h"
#include <QObject>

class AbstractDisplay : public QObject
{
	Q_OBJECT

public:
	// overwritten by QSortDisplay, 
	// needed to allow classes register for a paintevent
	// callback
	virtual void render()
	{
	}

public slots:
	// called when an element of VerboseVector is accessed
	virtual void access( std::vector<int>* vector, int index ) = 0;
};

#endif
