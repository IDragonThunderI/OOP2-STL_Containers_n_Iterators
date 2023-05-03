#include <iostream>
#include <queue>
#include <vector>
#include <cfloat>
#include "../Misc/ATD-time.h"
using namespace std;

template<typename T>
void copyVectorToQueue(queue<T>& que, const vector<T> vec)
{
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
		que.push(*i);
}

template<typename T>
void copyQueueToVector(queue<T>& que, vector<T>& vec)
{
	while (!que.empty())
	{
		vec.push_back(que.front());
		que.pop();
	}
}

template<typename T>
void print(queue<T> que)
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
		cout << *i << " ";
	cout << "\n";
}

template<>
void print(queue<TIME> que)
{
	vector<TIME> vec;
	copyQueueToVector(que, vec);
	for (typename vector<TIME>::const_iterator i = vec.begin(); i != vec.end(); i++)
		(*i).print();
	cout << "\n";
}

template<typename T>
const T minValue(queue<T> que)
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	T minValue = FLT_MAX;
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i < minValue)
			minValue = *i;
	}
	return minValue;
}

template<>
const TIME minValue(queue<TIME> que)
{
	vector<TIME> vec;
	copyQueueToVector(que, vec);
	TIME minValue = MAX_TIME;
	for (typename vector<TIME>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i < minValue)
			minValue = *i;
	}
	return minValue;
}

template<typename T>
const T maxValue(queue<T> que)
{
	vector<T> vec;
	copyQueueToVector(que, vec);
	T maxValue = -(FLT_MAX);
	for (typename vector<T>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i > maxValue)
			maxValue = *i;
	}
	return maxValue;
}

template<>
const TIME maxValue(queue<TIME> que)
{
	vector<TIME> vec;
	copyQueueToVector(que, vec);
	TIME maxValue = TIME();
	for (typename vector<TIME>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (*i > maxValue)
			maxValue = *i;
	}
	return maxValue;
}

template<typename T>
void removeElement(queue<T>& que, const T key)
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
	cout << "Element not found!\n";
}

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ЗАДАЧА №4 */\n\n";

	vector<float> flt{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	queue<float> queue1;
	copyVectorToQueue(queue1, flt);
	print(queue1);

	queue1.push(minValue(queue1));
	print(queue1);

	removeElement(queue1, 3.0f);
	print(queue1);

	float sum1 = maxValue(queue1) + minValue(queue1);
	vector<float> vec1;
	copyQueueToVector(queue1, vec1);
	for (vector<float>::iterator i = vec1.begin(); i != vec1.end(); i++)
		*i += sum1;
	copyVectorToQueue(queue1, vec1);
	print(queue1);

	cout << "\n";

	vector<TIME> time{ TIME(), TIME(1, 20, 30, 400), TIME(4, 30, 20, 100), TIME(23, 59, 60, 0), TIME(128, 256, 512, 1024) };
	queue<TIME> queue2;
	copyVectorToQueue(queue2, time);
	print(queue2);

	queue2.push(minValue(queue2));
	print(queue2);

	removeElement(queue2, TIME(24, 0, 0, 0));
	print(queue2);

	TIME sum2 = maxValue(queue2) + minValue(queue2);
	vector<TIME> vec2;
	copyQueueToVector(queue2, vec2);
	for (vector<TIME>::iterator i = vec2.begin(); i != vec2.end(); i++)
		*i = *i + sum2;
	copyVectorToQueue(queue2, vec2);
	print(queue2);

	return 0;
}