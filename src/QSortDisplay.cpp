#include "QSortDisplay.h"
#include "sleep.h"

#include <QPainter>
#include <vector>
#include <iostream>

QSortDisplay::QSortDisplay(PaintWidget* dev)
{
	m_dev = dev;
	m_painter = new QPainter();
	m_lastVector = NULL;
	m_lastIndex = 0;
	m_maxVal = 100;
	m_delay = 100;

	m_dev->setObserver( this );
}

void QSortDisplay::setMaxValue( int val )
{
	m_maxVal = val;
}

void QSortDisplay::setDelay(int msec)
{
	if (msec < 0) msec = 0;
	m_delay = msec;
}

void QSortDisplay::access( std::vector<int>* list, int index )
{
	m_lastIndex = index;
	m_lastVector = list;

	//std::cout << "access " << index << std::endl;

	m_dev->repaint();
	// delay!
	Sleep( m_delay );
}

void QSortDisplay::render()
{
	if (m_lastVector == NULL) return;

	m_painter->begin(m_dev);

	//std::cout << "render" << std::endl;

	m_painter->scale( m_dev->width() / 2000.,
					m_dev->height() / 2000. );

	m_painter->fillRect( 0, 0, 2000., 2000.,
						QColor( 255, 255, 255 ) );
	
	m_painter->translate( 0, 2000. );

	// bar width
	float w = 2000. / m_lastVector->size();

	QColor black(0, 0, 0);
	QColor red(255, 0, 0);
	QColor green(0, 255, 0);

	for (int i = 0; i < m_lastVector->size(); i++)
	{
		float val = static_cast<float> ((*m_lastVector)[i]);
		val /= m_maxVal;
		val *= -2000.;

		// assuming that pos = value is correct:
		QColor* color = (i == (*m_lastVector)[i] ? &green : &black);

		// if current: override green with red
		color = (i == m_lastIndex ? &red : color);

		m_painter->fillRect( 0., 0., 
			w,  val, 
			*color );

		m_painter->translate( w, 0. );
	}

	m_painter->end();
}

QSortDisplay::~QSortDisplay()
{
	m_dev->setObserver( NULL );
	delete m_painter;
}
