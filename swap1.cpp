//home/tovantran/Ctest/swap1.cpp --> 2015-06-17 by ./.tv  owner: tovantran

#include <iostream>
using namespace std;
void swap1 (int left, int right)
{
	int temp;
	temp = left;
	left = right;
	right = temp;
}
//C and C++ pass by pointer
void swap2 (int *p_left, int *p_right)
{
	int temp = *p_left;
	*p_left = *p_right;
	*p_right = temp;
}
//Only C++ pass by references
void swap3 (int &p_left, int &p_right)
{
	int temp = p_left;
	p_left = p_right;
	p_right = temp;
}

int main ()
{
	int x = 1, y = 2;
	swap1( x, y );
	cout << x << " " << y << '\n';
	swap2( & x, & y );
	cout << x << " " << y << '\n';
	swap3( x,  y );
	cout << x << " " << y << '\n';
}
//swap1
//1 2
//2 1
//1 2
