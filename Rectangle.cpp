// Abdulsamet AKTAS 23811. CS300 homework1. Enjoy :)

#include<iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle()
{
	Top = NULL;
	Left = NULL;
	Bottom = NULL;
	Right = NULL;
}

Rectangle::Rectangle(int T,int L, int B, int R)
{
	Top = T;
	Left = L;
	Bottom = B;
	Right = R;
}

int Rectangle::getTop()
{
	return Top;
}

int Rectangle::getLeft()
{
	return Left;
}

int Rectangle::getBottom()
{
	return Bottom;
}

int Rectangle::getRight()
{
	return Right;
}

bool Rectangle::IsBottomSide(int centerY)
{
	if (Top >= centerY) // if rectangle is on the bottom side
	{
		return true;
	}

	return false; // on the top side
}

bool Rectangle::IsRightSide(int centerX)
{
	if (Left >= centerX) // if rectange is on the right side
	{
		return true;
	}

	return false; // on the left side
}

bool Rectangle::intersect_y(int line)
{
	if (line < Bottom && line >= Top)
	{
		return true;
	}

	return false;
}

bool Rectangle::intersect_x(int line)
{
	if (line >= Left && line < Right)
	{
		return true;
	}

	return false;
}

bool Rectangle::VerticalLine(int XCORD)
{
	int center = (Left+Right)/2;
	if (center == XCORD)
	{
		return true;
	}
	else
		return false;
}
bool Rectangle::HorizantalLine(int YCORD)
{
	int center = (Top+Bottom)/2;
	if (center == YCORD)
	{
		return true;
	}
	else 
		return false;
}