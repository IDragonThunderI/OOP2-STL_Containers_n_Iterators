#include <iostream>
#include <list>
#include <cfloat>
using namespace std;

template<typename T>
void print(const T container)
{
	if (container.empty())
		cout << "\nEmpty!!!\n";
	else
		for (typename T::const_iterator i = container.begin(); i != container.end(); i++)
			cout << *i << " ";
	cout << "\n";
}

template<typename T>
const typename T::value_type minValue(const T container)
{
	typename T::value_type minValue = FLT_MAX;
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
	typename T::value_type maxValue = -(FLT_MAX);
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
	cout << "/* ÇÀÄÀ×À ¹1 */\n\n";

	list<float> list1{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	print(list1);

	list1.push_back(minValue(list1));
	print(list1);

	removeElement(list1, 3.0f);
	print(list1);

	float sum = maxValue(list1) + minValue(list1);
	for (list<float>::iterator i = list1.begin(); i != list1.end(); i++)
		*i += sum;
	print(list1);

	return 0;
}