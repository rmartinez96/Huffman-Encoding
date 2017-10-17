// Raul Martinez
// raul.martinez01@utrgv.edui

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class minHeap
{
public:
	vector<T> item;

minHeap()
	{
		// do nothing
	}

	int parent(int i)
	{
		if (i == 0)
			return i;

		else if (i % 2 == 0)
			return(i - 1) / 2;

		else
			return i / 2;
	}

	int lChild(int i)
	{
		return i + (i + 1);
	}

	int rChild(int i)
	{
		return i + (i + 2);
	}

	void insert(T x)
	{
		item.push_back(x);
		int last = item.size() - 1;
		bubbleUp(last);
	}

	void bubbleUp(int i)
	{
		if (item[parent(i)]->freq > item[i]->freq)
		{
			swap(item[i], item[parent(i)]);
			bubbleUp(parent(i));
		}
	}

	void bubbleDown(int i)
	{
		int left = lChild(i);
		int right = rChild(i);

		int small = i;

		if (left < item.size() && item[left]->freq < item[i]->freq)
			small = left;

		if (right < item.size() && item[right]->freq < item[small]->freq)
			small = right;

		if (small != i)
		{
			swap(item[i], item[small]);
			bubbleDown(small);
		}
	}

	T extractMin()
	{
		T x;
		x = item[0];
		swap(item[0], item[item.size() - 1]);
		item.pop_back();
		bubbleDown(0);
		return x;
	}

	bool empty()
	{
		return item.size() == 0;
	}
};