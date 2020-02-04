// Abdulsamet AKTAS 23811. CS300 homework1. Enjoy :)

#include <iostream>
#include "Rectangle.h"
#include "Tree.h"

using namespace std;

QuadTree::QuadTree()
{
	TopLeft = NULL;
	TopRight = NULL;
	BottomLeft = NULL;
	BottomRight = NULL;
}

QuadTree::QuadTree(Rectangle r)
{
	Extent = r;
	TopLeft = NULL;
	TopRight = NULL;
	BottomLeft = NULL;
	BottomRight = NULL;
}

void QuadTree::add(QuadTree*& t, Rectangle r)
{
	int CenterX = (Extent.getBottom() + Extent.getTop()) / 2;
	int CenterY = (Extent.getLeft() + Extent.getRight()) / 2;

	QuadTree *temp = new QuadTree(Extent);

	if ( r.intersect_x(CenterY)) 
	{
		t->Vertical.push_back(r);
	}
		
	else if (r.intersect_y(CenterX)) 
	{
		t->Horizontal.push_back(r);
	}
	else if (r.IsBottomSide(CenterY) && r.IsRightSide(CenterX)) // Bottom Right
	{
		temp->Extent = Rectangle(CenterY+1, CenterX+1, Extent.getBottom(), Extent.getRight());
	
		if (t->BottomRight == NULL)
		{
			t->BottomRight = temp;
		}
		t->BottomRight->add(t->BottomRight, r);
	}
	else if (r.IsBottomSide(CenterX) && !(r.IsRightSide(CenterY))) // Bottom Left
	{
		temp->Extent = Rectangle(CenterY+1, Extent.getLeft(), Extent.getBottom(), CenterX);

		if (t->BottomLeft == NULL)
		{
			BottomLeft = temp;
		}
		t->BottomLeft->add(t->BottomLeft, r);
	}
	else if (!r.IsBottomSide(CenterX) && r.IsRightSide(CenterY)) // Top Right
	{
		temp->Extent = Rectangle(Extent.getTop(), CenterX+1, CenterY, Extent.getRight());

		if (t->TopRight == NULL)
		{
			TopRight = temp;
		}
		t->TopRight->add(t->TopRight, r);
	}
	else if (!r.IsBottomSide(CenterX) && !r.IsRightSide(CenterY)) // Top Left
	{
		temp->Extent = Rectangle(Extent.getTop(), Extent.getLeft(), CenterY, CenterX);

		if (t->TopLeft == NULL)
		{
			TopLeft = temp;
		}
		t->TopLeft->add(t->TopLeft, r);
	}
}
void QuadTree::QuerySearch(QuadTree*& tree,vector<Rectangle>& ListOfRec, int queryX, int queryY)
{
	if (tree->Extent.VerticalLine(queryX))
	{
		for (int i = 0; i < Vertical.size(); i++)
		{
			if(Vertical[i].intersect_x(queryX) && Vertical[i].intersect_y(queryY))
				ListOfRec.push_back(Vertical[i]);
		}
	}
	else if (tree->Extent.HorizantalLine(queryY))
	{
		for (int i = 0; i < Horizontal.size(); i++)
		{
			if(Horizontal[i].intersect_y(queryY) && Horizontal[i].intersect_x(queryX))
				ListOfRec.push_back(Horizontal[i]);
		}
	}
	else
	{
		int centerX = (Extent.getLeft() + Extent.getRight())/2;
		int centerY = (Extent.getTop()+Extent.getBottom())/2;
		if ( queryX < centerX && queryY < centerY) //Top Left
		{
			if (tree->TopLeft != NULL)
				tree->TopLeft->QuerySearch(TopLeft,ListOfRec,queryX,queryY);
		}
		else if ( queryX > centerX && queryY < centerY)//Top Right 
		{
			if (tree->TopRight != NULL)
				tree->TopRight->QuerySearch(TopRight,ListOfRec,queryX,queryY);
		}
		else if (queryX < centerX && queryY > centerY)// Bottom Left
		{
			if (tree->BottomLeft != NULL)
				tree->BottomLeft->QuerySearch(BottomLeft,ListOfRec,queryX,queryY);
		}
		else if (queryX > centerX && queryY > centerY) // Bottom Right
		{
			if (tree->BottomRight != NULL)
				tree->BottomRight->QuerySearch(BottomRight,ListOfRec,queryX,queryY);
		}

		for (int k = 0; k < Horizontal.size(); k++)
		{
			if(Horizontal[k].intersect_y(queryY) && Horizontal[k].intersect_x(queryX))
				ListOfRec.push_back(Horizontal[k]);
		}
		for (int j = 0; j < Vertical.size(); j++)
		{
			if(Vertical[j].intersect_x(queryX) && Vertical[j].intersect_y(queryY))
				ListOfRec.push_back(Vertical[j]);
		}
	}
}