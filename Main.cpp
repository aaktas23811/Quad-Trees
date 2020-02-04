// Abdulsamet AKTAS 23811. CS300 homework1. Enjoy :)

#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <vector>
#include"Rectangle.h"
#include"Tree.h"

using namespace std;

int main ()	
{
	string file;
	cout << "Please enter the filename: \n";
	cin >> file;
	ifstream input;
	input.open(file.c_str());

	input.clear();
	input.seekg(0);

	string s1,s2;
	int Top, Bottom, Left, Right;

	getline(input,s1);
	istringstream line1(s1);
	line1 >> Top >> Left >> Bottom  >> Right;

	Rectangle extented(Top, Left,  Bottom, Right);
	QuadTree *tree = new QuadTree(extented);
	bool flag = true;
	while (getline(input,s2) && flag)
	{
		istringstream line2(s2);
		line2 >> Top;
		if (Top>=0)
		{
			line2 >> Bottom >> Left >> Right;
			Rectangle ToBeAdded(Top, Bottom, Left, Right);
			tree->add(tree, ToBeAdded);
		}
	}
	int queryX,queryY;
	vector<Rectangle> L;
	do
	{
		cout << "Please enter the query point: ";
		cin >> queryX >> queryY;
		if(queryX != -1 )
		{
			tree->QuerySearch(tree,L,queryX,queryY);
			if (L.size() < 1)
			{
				cout << 0 << endl;
			}
		
			if (L.size() > 0)
			{
				cout << L.size() << endl;
				for (int i = 0; i < L.size(); i++)
				{
					cout << L[i].getTop() << " " << L[i].getLeft() << " " << L[i].getBottom() << " " << L[i].getRight() << endl;
				}
			}
		}

	} while (queryX != -1 );

	
	return 0;
}