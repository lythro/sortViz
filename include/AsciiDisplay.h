#ifndef ASCIIDISPLAY_H_
#define ASCIIDISPLAY_H_

#include "AbstractDisplay.h"

class AsciiDisplay : public AbstractDisplay
{
	Q_OBJECT
public:
	AsciiDisplay();
	~AsciiDisplay();

public slots:
	void access( std::vector<int>* vector, int index );

	void setDelay(int msec);

private:
	int m_delay;

};

#endif
