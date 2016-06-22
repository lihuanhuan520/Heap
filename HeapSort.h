#pragma once 
#include<iostream>
#include<vector>
using namespace std;
//template<class T>
//class Heap
//{
//	public:
//	Heap(const T* a, int k)
//	{
//		_CreateHeap(a, k);
//	}
//
//	void Push(const T& x)
//	{
//		_a.push_back(x);
//		_AdjustUp(_a.size() - 1);
//	}
//
//	T& Top()
//	{
//		return _a[0];
//	}
//
//	void BuildHeap(const T* a, int k)
//	{
//		for (int i = (k - 2) / 2; i >= 0; i--)
//		{
//			_AdjustDown(i);
//		}
//	}
//
//	void Print()
//	{
//
//		for (int i = 0; i < _a.size(); i++)
//		{
//			cout << _a[i] << " ";
//		}
//		cout << endl;
//	}
//
//protected:
//	void _CreateHeap(const T* a, int k)
//	{
//		for (int i = 0; i < k; i++)
//		{
//			_a.push_back(a[i]);
//		}
//
//		//建小堆
//		for (int i = (k - 2) / 2; i >=0; i--)
//		{
//			_AdjustDown(i);
//		}
//	}
//
//	
//	void _AdjustDown(int parent)	//向下调整
//	{
//		int child = parent * 2 + 1;
//		while (child < _a.size())
//		{
//			if (child + 1 < _a.size() && _a[child] > _a[child + 1])
//			{
//				child++;
//			}
//			if (_a[child] < _a[parent])
//			{
//				swap(_a[child], _a[parent]);
//				parent = child;
//				child = parent * 2 + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	void _AdjustUp(int child)//向上调整
//	{
//		int parent = (child - 1) / 2;
//		while (child >= 0)
//		{
//			if (_a[child] > _a[parent])
//			{
//				swap(_a[child], _a[parent]);
//				child = parent;
//				parent = (child - 1) / 2;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//
//private:
//	vector<T> _a;
//};

void AdjustDown(int* a, int parent,int size)	//向下调整
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//建小堆
void BuildHeap(int* a,int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, size);
	}
}

void HeapSort(int* a, int size)
{
	BuildHeap(a, size);
	for (int i = size - 1; i >= 0; i--)
	{
		BuildHeap(a, i);
		swap(a[0], a[i]);
	}
}

void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}