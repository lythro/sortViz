FIND_PACKAGE (Qt4 REQUIRED)

ADD_DEFINITIONS (${QT_DEFINITIONS})

#SET( QT_USE_QTXML TRUE )
#SET( QT_USE_QTOPENGL TRUE )
SET( QT_WRAP_CPP TRUE )

INCLUDE (${QT_USE_FILE})

SET ( UI_sources
	# all your .ui files
	../ui/mainwindow.ui
)
  	
QT4_WRAP_UI ( UI_headers ${UI_sources})


SET ( App_sources
	# all your .cpp files
	main.cpp
	MainWindow.cpp
	PaintWidget.cpp

	AsciiDisplay.cpp
	QSortDisplay.cpp

	SelectionSort.cpp
	BubbleSort.cpp
	QuickSort.cpp
	MergeSort.cpp
)

QT4_WRAP_CPP ( MOC_headers
	# all header files that need to be moc'ed
	# (the ones using Q_OBJECT macro)
	../include/MainWindow.h
	../include/PaintWidget.h

	../include/VerboseVector.h
	../include/AbstractDisplay.h
	../include/QSortDisplay.h
	../include/AsciiDisplay.h

	../include/AbstractSort.h # needs to be a QObject for threading
)


INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}/include ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} )

ADD_EXECUTABLE ( sortViz
	${App_sources}
	${MOC_headers}
	${UI_headers}
)

TARGET_LINK_LIBRARIES( sortViz ${QT_LIBRARIES} )
