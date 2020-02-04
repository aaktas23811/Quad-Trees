// Abdulsamet AKTAS 23811. CS300 homework1. Enjoy :)

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
using namespace std;
class Rectangle {
public:
	Rectangle::Rectangle(); // default constructor
	Rectangle::Rectangle(int T,int L, int B, int R); // Constructor with parameters
	// ======  to get private members of rectangle ======= // 
	int Rectangle::getTop(); 
	int Rectangle::getLeft();
	int Rectangle::getBottom();
	int Rectangle::getRight();
	// ======  to get private members of rectangle ======= // 
	bool Rectangle::IsBottomSide(int centerY); // it returns true if the rectangle in the bottom side otherwise returns false
	bool Rectangle::IsRightSide(int centerX); // it returns true if the rectangle in the right side otherwise returns false
	bool Rectangle::intersect_y(int line); // it checks if line intersects with y 
	bool Rectangle::intersect_x(int line); // it checks if line intersects with x 

	bool Rectangle::VerticalLine(int); // returns true if the point on the line
	bool Rectangle::HorizantalLine(int); // returns true if the point on the line

private:
	int Top;
	int Left;
	int Bottom;
	int Right;

};

#endif