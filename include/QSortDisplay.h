#ifndef QSORTDISPLAY_H_
#define QSORTDISPLAY_H_

#include "AbstractDisplay.h"
#include "PaintWidget.h"

#include <QPainter>
#include <QPaintDevice>
#include <vector>

class QSortDisplay : public AbstractDisplay
{

	Q_OBJECT

public:
	QSortDisplay( PaintWidget* dev );
	~QSortDisplay();

	void setDelay(int msec);
	void setMaxValue(int val);

	void render();

public slots:
	void access( std::vector<int>* list, int index );

private:
	int m_delay;
	int m_lastIndex;
	int m_maxVal;

	std::vector<int>* m_lastVector;

	QPainter* m_painter;
	PaintWidget* m_dev;
};

#endif
