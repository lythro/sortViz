#ifndef PAINTWIDGET_H_
#define PAINTWIDGET_H_

#include <QWidget>
#include "AbstractDisplay.h"

class PaintWidget : public QWidget
{

	Q_OBJECT
public:
	PaintWidget(QWidget*& widget);

	void setObserver(AbstractDisplay* observer);

protected:
	virtual void paintEvent(QPaintEvent* e);

private:
	AbstractDisplay* m_observer;

/*
signals:
	void paintRequest();
	// does not work like expected,
	// signal is queued, reactions take place _after_
	// repaint-event. :-(
	// --> not visible.

	// solution: register callbacks to do the
	//			drawing directly during the paintEvent
*/
};

#endif
