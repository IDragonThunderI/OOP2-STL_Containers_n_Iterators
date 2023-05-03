#include <iostream>
#include <queue>
#include <vector>
#include <cfloat>
#include "../Misc/ATD-time.h"
using namespace std;

template<typename T>
class Vector
{
	queue<T> que;
	void copyVectorToQueue(queue<T>& que, const vector<T> vec);
	void copyQueueToVector(queue<T>& que, vector<T>& vec);
public:
	Vector() {};
	Vector(const vector<T> vec);
	Vector(const Vector<T>& obj);
	~Vector() {};
	void pushBack(const T element);
	void print();
	const T minValue();
	const T maxValue();
	void removeElement(const T key);
	void increaseAllElements(T value);
};

template<typename T>
Vector<typename T>::Vector(const vector<T> vec)
{
	if (vec.empty())
		return;
	else
		copyVectorToQueue(que, vec);
}

template<typename T>
Vector<typename T>::Vector(const Vector<T>& obj)
{
	Vector copy;
	copy.que = obj.que;
}

template<typename T>
void Vector<typename T>::copyVectorToQueue(queue<T>& que, const vector<T> vec)
{
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
		que.push(*i);
}

template<typename T>
void Vector<typename T>::copyQueueToVector(queue<T>& que, vector<T>& vec)
{
	vec.clear();
	while (!que.empty())
	{
		vec.push_back(que.front());
		que.pop();
	}
}

template<typename T>
void Vector<typename T>::print()
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	copyVectorToQueue(que, vec);
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
		cout << *i << " ";
	cout << "\n";
}

template<>
void Vector<TIME>::print()
{
	vector<TIME> vec;
	copyQueueToVector(que, vec);
	copyVectorToQueue(que, vec);
	for (typename vector<TIME>::const_iterator i = vec.begin(); i != vec.end(); i++)
		(*i).print();
	cout << "\n";
}

template<typename T>
void Vector<typename T>::pushBack(const T element)
{
	que.push(element);
}

template<typename T>
const T Vector<typename T>::minValue()
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	copyVectorToQueue(que, vec);
	T minValue = FLT_MAX;
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i < minValue)
			minValue = *i;
	}
	return minValue;
}

template<>
const TIME Vector<TIME>::minValue()
{
	vector<TIME> vec;
	copyQueueToVector(que, vec);
	copyVectorToQueue(que, vec);
	TIME minValue = MAX_TIME;
	for (typename vector<TIME>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i < minValue)
			minValue = *i;
	}
	return minValue;
}

template<typename T>
const T Vector<typename T>::maxValue()
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	copyVectorToQueue(que, vec);
	T maxValue = -(FLT_MAX);
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i > maxValue)
			maxValue = *i;
	}
	return maxValue;
}

template<>
const TIME Vector<TIME>::maxValue()
{
	vector<TIME> vec;
	copyQueueToVector(que, vec);
	copyVectorToQueue(que, vec);
	TIME maxValue = TIME();
	for (typename vector<TIME>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i > maxValue)
			maxValue = *i;
	}
	return maxValue;
}

template<typename T>
void Vector<typename T>::removeElement(const T key)
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i == key)
		{
			vec.erase(i);
			copyVectorToQueue(que, vec);
			cout << "Element has been successfully removed!\n";
			return;
		}
	}
	copyVectorToQueue(que, vec);
	cout << "Element not found!\n";
}

template<typename T>
void Vector<typename T>::increaseAllElements(T value)
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	for (typename vector<T>::iterator i = vec.begin(); i != vec.end(); i++)
		*i = *i + value;
	copyVectorToQueue(que, vec);
}	

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ЗАДАЧА №5 */\n\n";

	vector<float> flt{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	Vector<float> vector1(flt);
	vector1.print();

	vector1.pushBack(vector1.minValue());
	vector1.print();

	vector1.removeElement(3.0);
	vector1.print();

	float sum1 = vector1.maxValue() + vector1.minValue();
	vector1.increaseAllElements(sum1);
	vector1.print();

	cout << "\n";

	vector<TIME> time{ TIME(), TIME(1, 20, 30, 400), TIME(4, 30, 20, 100), TIME(23, 59, 60, 0), TIME(128, 256, 512, 1024) };
	Vector<TIME> vector2(time);
	vector2.print();

	vector2.pushBack(vector2.minValue());
	vector2.print();

	vector2.removeElement(TIME(24, 0, 0, 0));
	vector2.print();

	TIME sum2 = vector2.maxValue() + vector2.minValue();
	vector2.increaseAllElements(sum2);
	vector2.print();

	return 0;
}