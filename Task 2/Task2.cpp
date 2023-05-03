#include <iostream>
#include <list>
#include "../Misc/ATD-time.h"
using namespace std;

template<typename T>
void print(const T container)
{
	if (container.empty())
		cout << "\nEmpty!!!\n";
	else
		for (typename T::const_iterator i = container.begin(); i != container.end(); i++)
			(*i).print();
	cout << "\n";
}

template<typename T>
const typename T::value_type minValue(const T container)
{
	typename T::value_type minValue = MAX_TIME;
	for (typename T::const_iterator i = container.begin(); i != container.end(); i++)
	{
		if (*i < minValue)
			minValue = *i;
	}
	return minValue;
}

template<typename T>
const typename T::value_type maxValue(const T container)
{
	typename T::value_type maxValue = TIME();
	for (typename T::const_iterator i = container.begin(); i != container.end(); i++)
	{
		if (*i > maxValue)
			maxValue = *i;
	}
	return maxValue;
}

template<typename T>
void removeElement(T& container, const typename T::value_type key)
{
	for (typename T::const_iterator i = container.begin(); i != container.end(); i++)
	{
		if (*i == key)
		{
			container.erase(i);
			cout << "Element has been successfully removed!\n";
			return;
		}
	}
	cout << "Element not found!\n";
}

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ÇÀÄÀ×À ¹2 */\n\n";

	list<TIME> list1{ TIME(), TIME(1, 20, 30, 400), TIME(4, 30, 20, 100), TIME(23, 59, 60, 0), TIME(128, 256, 512, 1024) };
	print(list1);

	list1.push_back(minValue(list1));
	print(list1);

	removeElement(list1, TIME(24, 0, 0, 0));
	print(list1);

	TIME sum = maxValue(list1) + minValue(list1);
	for (list<TIME>::iterator i = list1.begin(); i != list1.end(); i++)
		*i = *i + sum;
	print(list1);

	return 0;
}