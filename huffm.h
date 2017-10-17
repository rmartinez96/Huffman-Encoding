#include <string>
#include <iostream>

using namespace std;

class Huffman
{
public:
	char x;
	int freq;
	int n;
	int tSIZE;
	Huffman * A;
	Huffman * C;
	Huffman * G;
	Huffman * T;
	string huffCode;

	Huffman()
	{
		x = 128;
		n = 128;
		freq = 0;
		tSIZE = 0;
		A = NULL;
		C = NULL;
		G = NULL;
		T = NULL;
	}

	void hM(Huffman * t)
	{
	}

	void print(Huffman * root, char a[], int c)
	{
		if (root->A != NULL)
		{
			a[c] = 'A';
			print(root->A, a, c + 1);
		}
		if (root->C != NULL)
		{
			a[c] = 'C';
			print(root->C, a, c + 1);
		}
		if (root->G != NULL)
		{
			a[c] = 'G';
			print(root->G, a, c + 1);
		}
		if (root->T != NULL)
		{
			a[c] = 'T';
			print(root->T, a, c + 1);
		}

		int x, n;
		if (!(root->A) && !(root->C) && !(root->G) && !(root->T))
		{
			cout  << root->x << ": " << root->freq << ":: ";
			x = root->freq * c;

			for (int i = 0; i < c; i++)
				cout << a[i];

			cout << ": " << x << endl;

			tSIZE += x;
		}
	}

	void printSIZE()
	{
		cout << "Size of Harry Potter book: " << tSIZE << endl;
	}
};
