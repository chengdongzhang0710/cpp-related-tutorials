#pragma once
#include <iostream>
using namespace std;

template<typename T>
class MyArray
{
private:
	T* pAddress;
	int arrayCapacity;
	int arraySize;

public:
	MyArray(int capacity)
	{
		this->arrayCapacity = capacity;
		this->arraySize = 0;
		this->pAddress = new T[this->arrayCapacity];
	}

	MyArray(const MyArray& arr)
	{
		this->arrayCapacity = arr.arrayCapacity;
		this->arraySize = arr.arraySize;
		this->pAddress = new T[arr.arrayCapacity];
		for (int i = 0; i < this->arraySize; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->arrayCapacity = 0;
			this->arraySize = 0;
		}

		this->arrayCapacity = arr.arrayCapacity;
		this->arraySize = arr.arraySize;
		this->pAddress = new T[arr.arrayCapacity];
		for (int i = 0; i < this->arraySize; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	void pushBack(const T& val)
	{
		if (this->arrayCapacity == this->arraySize)
		{
			return;
		}
		this->pAddress[this->arraySize] = val;
		this->arraySize++;
	}

	void popBack()
	{
		if (this->arraySize == 0)
		{
			return;
		}
		this->arraySize--;  // 让用户访问不到最后一个元素即为尾删，逻辑删除
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	int getCapacity()
	{
		return this->arrayCapacity;
	}

	int getSize()
	{
		return this->arraySize;
	}

	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
};
