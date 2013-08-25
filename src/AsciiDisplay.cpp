#include "AsciiDisplay.h"
#include <iostream>
using namespace std;

#ifdef _WINDOWS
	#include <Windows.h>
#else
	#include <unistd.h>
	#define Sleep(x) usleep((x)*1000)
#endif

AsciiDisplay::AsciiDisplay()
{
	m_delay = 500;
}

void AsciiDisplay::access(vector<int>* v, int index)
{
	cout << "accessed vector[" << index << "] == " << (*v)[index] << endl;

	// baaaad, hardcoded :-(
	for (int val = 50; val >= 0; val--)
	{
		for (int pos = 0; pos < v->size(); pos++)
		{
			if ((*v)[pos] >= val)
			{
				if (pos == index)
				{
					cout << " \033[31m#\033[39m ";
				}
				else
				{
					cout << " # ";
				}
			}
			else
			{
				cout << "   ";
			}
		}
		cout << endl;
	}
	cout << endl;

	Sleep(m_delay);
}


void AsciiDisplay::setDelay(int msec)
{
	m_delay = msec;
}

AsciiDisplay::~AsciiDisplay()
{
}
