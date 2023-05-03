#include <iostream>
#include <deque>
#include <vector>
#include <cfloat>
#include "../Misc/ATD-time.h"
using namespace std;

template<typename T>
class Queue
{
private:
	deque<T> que;
public:
	Queue() {};
	Queue(const vector<T> vec);
	Queue(const Queue<T>& obj);
	~Queue() {};
	typename deque<T>::iterator beginIter();
	typename deque<T>::iterator endIter();
	void pushBack(const T element);
	void print() const;
	const T minValue() const;
	const T maxValue() const;
	void removeElement(const T key);
};

template<typename T>
Queue<typename T>::Queue(const vector<T> vec)
{
	if (vec.empty())
		return;
	else
		for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
			que.push_back(*i);
}

template<typename T>
Queue<typename T>::Queue(const Queue<T>& obj)
{
	Queue copy;
	copy.que = obj.que;
}

template<typename T>
typename deque<T>::iterator Queue<typename T>::beginIter()
{
	return que.begin();
}

template<typename T>
typename deque<T>::iterator Queue<typename T>::endIter()
{
	return que.end();
}

template<typename T>
void Queue<typename T>::pushBack(const T element)
{
	que.push_back(element);
}

template<typename T>
void Queue<typename T>::print() const
{
	if (que.empty())
		cout << "\nEmpty!!!\n";
	else
		for (typename deque<T>::const_iterator i = que.begin(); i != que.end(); i++)
			cout << *i << " ";
	cout << "\n";
}

template<>
void Queue<TIME>::print() const
{
	if (que.empty())
		cout << "\nEmpty!!!\n";
	else
		for (typename deque<TIME>::const_iterator i = que.begin(); i != que.end(); i++)
			(*i).print();
	cout << "\n";
}

template<typename T>
const T Queue<typename T>::minValue() const
{
	T minValue = FLT_MAX;
	for (typename deque<T>::const_iterator i = que.begin(); i != que.end(); i++)
	{
		if (*i < minValue)
			minValue = *i;
	}
	return minValue;
}

template<>
const TIME Queue<TIME>::minValue() const
{
	TIME minValue = MAX_TIME;
	for (typename deque<TIME>::const_iterator i = que.begin(); i != que.end(); i++)
	{
		if (*i < minValue)
			minValue = *i;
	}
	return minValue;
}

template<typename T>
const T Queue<typename T>::maxValue() const
{
	T maxValue = FLT_MIN;
	for (typename deque<T>::const_iterator i = que.begin(); i != que.end(); i++)
	{
		if (*i > maxValue)
			maxValue = *i;
	}
	return maxValue;
}

template<>
const TIME Queue<TIME>::maxValue() const
{
	TIME maxValue = TIME();
	for (typename deque<TIME>::const_iterator i = que.begin(); i != que.end(); i++)
	{
		if (*i > maxValue)
			maxValue = *i;
	}
	return maxValue;
}

template<typename T>
void Queue<typename T>::removeElement(const T key)
{
	for (typename deque<T>::const_iterator i = que.begin(); i != que.end(); i++)
	{
		if (*i == key)
		{
			que.erase(i);
			cout << "Element has been successfully removed!\n";
			return;
		}
	}
	cout << "Element not found!\n";
}

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ЗАДАЧА 3 */\n\n";

	vector<float> vec1{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	Queue<float> queue1(vec1);
	queue1.print();

	queue1.pushBack(queue1.minValue());
	queue1.print();

	queue1.removeElement(3.0);
	queue1.print();

	float sum1 = queue1.maxValue() + queue1.minValue();
	for (deque<float>::iterator i = queue1.beginIter(); i != queue1.endIter(); i++)
		*i += sum1;
	queue1.print();

	cout << "\n";

	vector<TIME> time{ TIME(), TIME(1, 20, 30, 400), TIME(4, 30, 20, 100), TIME(23, 59, 60, 0), TIME(128, 256, 512, 1024) };
	Queue<TIME> queue2(time);
	queue2.print();

	queue2.pushBack(queue2.minValue());
	queue2.print();

	queue2.removeElement(TIME(24, 0, 0, 0));
	queue2.print();

	TIME sum2 = queue2.maxValue() + queue2.minValue();
	for (deque<TIME>::iterator i = queue2.beginIter(); i != queue2.endIter(); i++)
		*i = *i + sum2;
	queue2.print();

	return 0;
}