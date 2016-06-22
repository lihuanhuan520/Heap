#include"Heap.h"
#include"HuffmanTree.h"
void Test()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	int len = sizeof(a) / sizeof(a[0]);
	Heap<int,Less<int>> hp(a, len);
	hp.Print();

	hp.Push(22);
	hp.Print();

	hp.Push(0);
	hp.Print();

	hp.Pop();
	hp.Print();

}

int main()
{
	//Test();
	HuffmanTreeTest();
	return 0;
}