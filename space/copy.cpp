#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int	flag;
float 	remember;

struct 	Point{
	float x;
	float y;
	float z;
};

Point	A,B,C,D;
void	my_input(void){

	float x, y, z;

	cin >> x >> y >> z;
	A.x = x;
	A.y = y;
	A.z = z;
	cin >> x >> y >> z;
	B.x = x;
	B.y = y;
	B.z = z;
	cin >> x >> y >> z;
	C.x = x;
	C.y = y;
	C.z = z;
	cin >> x >> y >> z;
	D.x = x;
	D.y = y;
	D.z = z;
}

float	length(Point first, Point second){

	float result;
	result = sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2));
	return result;
}

Point	center(Point first, Point second){

	Point middle;

	middle.x = (first.x + second.x) / 2;
	middle.y = (first.y + second.y) / 2;
	middle.z = (first.z + second.z) / 2;
	return middle;
}

Point   coordinate(Point first, Point second, int direction){

	Point current;
	float epsilon;

	if (direction == 1)	{epsilon = 0.49;} // 왼쪽으로 옮기자
	else			{epsilon = 0.51;} // 오른쪽으로 옮기자

	current.x = (1 - epsilon) * first.x + epsilon * second.x;
	current.y = (1 - epsilon) * first.y + epsilon * second.y;
	current.z = (1 - epsilon) * first.z + epsilon * second.z;
	return current;
}

float	left(Point A, Point B, Point C, Point D, int flag){

	Point ex;

	if (flag == 1)  
	{
		ex = coordinate(A, B, 1);
		return length(ex, center(C, D));
	}
	else 
	{
		ex = coordinate(C, D, 1);
		return length(center(A, B), ex);
	}
}

float	right(Point A, Point B, Point C, Point D, int flag){

	Point ex;

	if (flag == 1) 
	{
		ex = coordinate(A, B, 0);
		return length(ex, center(C, D));
	}
	else 
	{
		ex = coordinate(C, D, 0);
		return length(center(A, B), ex);
	}
}

float	recursive_min(Point A, Point B, Point C, Point D) {
	
	Point mid;
	float len = length(center(A, B), center(C, D));

	if (abs(left(A, B, C, D, flag) - right(A, B, C, D, flag)) <= 1)
	{
		if (flag == 1)	{ flag = 0;}
		else		{ flag = 1;}
	}

	if (left(A, B, C, D, 0) >= len && right(A, B, C, D, 0) >= len && left(A, B, C, D, 1) >= len && right(A, B, C, D, 1) >= len)	
	{
		cout << ceil(len);
		return length(center(A, B), center(C, D));}

	if (left(A, B, C, D, flag) < len) // flag에 따라 첫번째점을 왼쪽으로 옮길지, 두번째 점을 왼쪽으로 옮길지 정함
	{
		remember = len;
		if (flag == 1) // 첫번째 점을 왼쪽으로 옮긴다.
		{
			mid = center(A, B);
			recursive_min(A, mid, C, D);
		}
		else // 두번째 점을 왼쪽으로 옮긴다.
		{
			mid = center(C, D);
			recursive_min(A, B, C, mid);
		}
	}
	else if (right(A, B, C, D, flag) < len)
	{
		if (flag == 1) // 첫번째 점을 오른쪽으로 옮긴다.
		{
			mid = center(A, B);
			recursive_min(mid, B, C, D);
		}
		else // 두번째 점을 오른쪽으로 옮긴다.
		{
			mid = center(C, D);
			recursive_min(A, B, mid, D);
		}
	}
	else
	{
		if (flag == 0) {flag = 1;}
		else	       {flag = 0;}
		return recursive_min(A, B, C, D);
	}
	return len;
}

int 	main(void){

	my_input();
	flag = 1;
	recursive_min(A, B, C, D);
}
