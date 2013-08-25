#ifndef VERBOSEVECTOR_H_
#define VERBOSEVECTOR_H_

#include <vector>
#include <QObject>

class VerboseVector : public QObject
{

	Q_OBJECT

public:
	VerboseVector()
		: m_vector()
	{
	}

	~VerboseVector()
	{
	}

	//
	int& operator[](int index)
	{
		emit accessed(&m_vector, index);
		return m_vector[index];
	}

	//
	void push_back(int item)
	{
		m_vector.push_back(item);
	}

	//
	std::vector<int>::iterator begin()
	{
		return m_vector.begin();
	}

	//
	std::vector<int>::iterator end()
	{
		return m_vector.end();
	}

	//
	int size()
	{
		return m_vector.size();
	}

	//
	void clear()
	{
		m_vector.clear();
	}

signals:
	void accessed(std::vector<int>* vector, int index);

private:
	std::vector<int> m_vector;
};

#endif
