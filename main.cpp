// Raul Martinez
// raul.martinez01@utrgv.edu

#include <iostream>
#include <fstream>
#include <string>
#include "minHeap.h"
#include "huffm.h"

using namespace std;

int main()
{
	Huffman * table = new Huffman[127];
	Huffman * n = NULL;
	minHeap<Huffman*> mH;
	int size = 0;
	fstream file;
	string str;
	int m=0;

	//Setting all frequencies to 0
	for (int i = 0; i < 127; i++)
		table[i].freq = 0;

	//Finding all the different chars used in the file
	file.open("harryPotter.txt");
	char c;
	while (file >> noskipws >> c)
	{
		int j = c;
		table[j].freq = table[j].freq + 1;
		table[j].x = c;

		if (table[j].n == 128)
		{
			table[j].n = size;
			size++;
		}
	}
	file.close();

	// inserting into minHeap
	for (int i = 0; i < 128; i++)
	{
		if (table[i].freq != 0)
		{
			mH.insert(&table[i]);
			m++;
		}
	}

	while ((m % 3) != 1)
	{
		mH.insert(new Huffman);
		m++;
		size++;
	}

	// add letters to nodes
	while (!mH.empty())
	{
		int sum;
		n = new Huffman;
		n->A = mH.extractMin();
		n->C = mH.extractMin();
		n->G = mH.extractMin();
		n->T = mH.extractMin();
		n->freq = n->A->freq + n->C->freq + n->G->freq + n->T->freq;

		if (!(mH.empty()))
		{
			mH.insert(n);
		}
	}

	char arr[100];
	int counter = 0;
	n->print(n, arr, counter);
	cout << endl;

	
	cout << "Chars: " << size << endl;
	n->printSIZE();


	file.open("harryPotter.txt");
	int encoder = 0;
	while (encoder != 100)
	{
		getline(file, str);
		for (int i = 0; i < str.length(); i++)
		{
			cout << table[i].huffCode;
		}
		encoder++;
	}
	file.close();

	
	cout << endl;

	return 0;
}