#include "PaintWidget.h"
#include <QPainter>
#include <iostream>
#include <QStyleOption>

PaintWidget::PaintWidget(QWidget*& widget)
	: QWidget( widget )
{
	setAttribute(Qt::WA_PaintOutsidePaintEvent, true);

	m_observer = NULL;
}

void PaintWidget::setObserver(AbstractDisplay* o)
{
	m_observer = o;
}

void PaintWidget::paintEvent(QPaintEvent* e)
{

	// apply stylesheet
	QStyleOption opt;
	opt.init(this);

	QPainter p(this);
	p.setRenderHint( QPainter::Antialiasing );

	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

	p.end();

	// call observer to paint this
	if (m_observer) m_observer->render();

	// request to be painted
	//emit paintRequest();

}
