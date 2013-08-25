#include "MainWindow.h"
#include "ui_mainwindow.h"

#include "SelectionSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

#include "VerboseVector.h"
#include "QSortDisplay.h"

#include <iostream>
#include <QThread>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	m_running = false;
	m_list = new VerboseVector();
	m_sort = new SelectionSort();
	m_display = new QSortDisplay(ui->widget);


	m_list->push_back( 10 );

	connectActions();
}


void MainWindow::connectActions()
{
	QObject::connect( ui->pushButtonStartStop, SIGNAL(clicked()),
		this, SLOT(startStop()) );	
	
	// setup the display to listen for accesses
	// in our vector
	QObject::connect(
		m_list, 
		SIGNAL(accessed(std::vector<int>*, int)),
		m_display,
		SLOT(access(std::vector<int>*, int))
	);

	QObject::connect(
		ui->spinBoxCount,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(adjustVector(int))
	);


	// debug
	/*
	QObject::connect(
		m_list,
		SIGNAL(accessed(std::vector<int>*, int)),
		this,
		SLOT(access(std::vector<int>*, int))
	);
	*/
}

void MainWindow::adjustVector(int new_count)
{
	m_display->setMaxValue(new_count);

	if (m_list->size() > new_count)
	{
		m_list->clear();
	}
	else
	{
		new_count -= m_list->size();
	}

	int offset = m_list->size();
	for (int i = 0; i < new_count; i++)
	{
		m_list->push_back( offset + i );
	}

	random_shuffle( m_list->begin(), m_list->end() );
	(*m_list)[0];
}

void MainWindow::access(std::vector<int>* list, int index)
{
	std::cout << "list[" << index << "] == " << (*list)[index]
		<< std::endl;
}

void MainWindow::startStop()
{
	if (m_running)
	{
		// TODO stop
		/*
		m_running = false;
		ui->pushButtonStartStop->setText( "Start" );
		ui->groupBoxSettings->setEnabled( true );
		*/
	}
	else
	{
		m_list->clear();

		// support for float delays? TODO
		int delay = static_cast<int>(ui->spinBoxDelay->value());
		int count = ui->spinBoxCount->value();
		
		// fill the vector
		for (int i = 0; i < count; i++)
		{
			m_list->push_back( i );
		}
		random_shuffle( m_list->begin(), m_list->end() );

		// apply settings
		m_display->setMaxValue( count );
		m_display->setDelay( delay );

		// select sorting algorithm
		if (ui->radioButtonSelection->isChecked())
		{
			delete m_sort;
			m_sort = new SelectionSort();
		}
		else if (ui->radioButtonBubble->isChecked())
		{
			delete m_sort;
			m_sort = new BubbleSort();
		}
		else if (ui->radioButtonQuick->isChecked())
		{
			delete m_sort;
			m_sort = new QuickSort();
		}
		else if (ui->radioButtonMerge->isChecked())
		{
			delete m_sort;
			m_sort = new MergeSort();
		}

		m_running = true;
		ui->pushButtonStartStop->setText( "Stop" );
		ui->groupBoxSettings->setEnabled( false );

		std::cout << "sorting" << std::endl;
		// sort the vector
		m_sort->msort( *m_list );
		std::cout << "sorted" << std::endl;

		finished();
	}
}

void MainWindow::finished()
{
	m_running = false;
	ui->pushButtonStartStop->setText( "Start" );
	ui->groupBoxSettings->setEnabled( true );
}

MainWindow::~MainWindow()
{
    delete ui;
	delete m_list;
	delete m_sort;
	delete m_display;
}
