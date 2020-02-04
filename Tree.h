// Abdulsamet AKTAS 23811. CS300 homework1. Enjoy :)

#ifndef TREE_H_
#define TREE_H_

#include "Rectangle.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class QuadTree 
{
	public:
		QuadTree::QuadTree(); // default constructor 
		QuadTree::QuadTree(Rectangle); // constructer with parameter
		void QuadTree::add(QuadTree*& t, Rectangle r  ); // creating the binary quad tree
		void QuadTree::QuerySearch(QuadTree*&,vector<Rectangle>&, int, int); // it finds the query points.

	private:
		Rectangle Extent;
		vector<Rectangle> Vertical, Horizontal;
		QuadTree *TopLeft, *TopRight, *BottomLeft, *BottomRight;
};

#endif