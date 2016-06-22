#pragma once
#include<iostream>
#include<vector>
using namespace std;

//仿函数
template<class T>
struct Less
{
public:
	bool operator()(const T& l, const T& r) const
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
public:
	bool operator()(const T& l, const T& r) const
	{
		return l > r;
	}
};

template<class T,class Compare>
class Heap
{
public:
	Heap()
	{}
	Heap(T* a, int size)
	{
		for (int i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}
		//建堆
		for (int i = (size - 2) / 2; i >= 0; i--)
		{
			_AdjustDown(i);
		}
	}

	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size()-1);
	}

	void Pop()
	{
		_a[0] = _a[_a.size() - 1];
		_a.pop_back();
		_AdjustDown(0);
	}

	T& Top()
	{
		return _a[0];
	}
	bool Empty()
	{
		return _a.empty();
	}

	int Size()
	{
		return _a.size();
	}
	void Print()
	{
		for (int i = 0; i < _a.size(); i++)
		{
			cout << _a[i] << " ";
		}
		cout << endl;
	}
protected:
	void _AdjustDown(int parent)
	{
		Compare com;
		int child = parent * 2 + 1;
		while (child < _a.size())
		{ 
			if (child + 1 < _a.size() && com(_a[child] , _a[child + 1]))//在数组有效范围内 且 左小于右
			{
				child++;
			}
			if (com(_a[child] , _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
		
	}

	void _AdjustUp(int child)//向上调整
	{
		int parent = (child - 1) / 2;
		Compare com;
		while (parent >= 0 )
		{
			if (com(_a[child] , _a[parent]))
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

private:
	vector<T> _a;
};

