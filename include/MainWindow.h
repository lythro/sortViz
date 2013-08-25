#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <vector>

#include "VerboseVector.h"
#include "AbstractDisplay.h"
#include "QSortDisplay.h"
#include "AbstractSort.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void access(std::vector<int>* list, int index);

private slots:
	void startStop();
	void finished();

	void adjustVector(int new_count);

private:
    Ui::MainWindow *ui;

	void connectActions();

	bool m_running;

	QThread m_thread;

	AbstractSort* m_sort;
	VerboseVector* m_list;
	//AbstractDisplay* m_display;
	QSortDisplay* m_display;
};

#endif // MAINWINDOW_H
