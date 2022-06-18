#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int	flag;
float 	remember;
vector<float> ans;


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

	if (direction == 1)	{epsilon = 0.49;} 
	else			{epsilon = 0.51;} 

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
	float len = length(center(A, B), center(C, D)); //현재 두점 사이의 거리 

	if (첫번째 선분에 있는점을 왼쪽으로 옮겼을때 거리 < len && 첫번째 선분에 있는점을 오른쪽으로 옮겼을때 거리 < len && 두번째 선분에 있는점을 왼쪽으로 옮겼을때 거리 < len && 두번째 선분에 있는 점을 오른쪽으로 옮겼을떄 거리 < len)	
	{
		cout << ceil(len);
		ans.push_back(ceil(len));
		return length(center(A, B), center(C, D));}

	if (왼쪽으로 조금 옮겼을 때 거리 < 현재 두 점의 거리)
	{
		remember = len;
		if (첫번째 선분에 있는점을 왼쪽으로 옮긴다) 
		{
			recursive_min(A, A 와 B의 중점, C, D);
		}
		else (두번째 선분에 있는점을 왼쪽으로 옮긴다)
		{
			recursive_min(A, B, C, C와 D의 중점);
		}
	}
	else if (오른쪽으로 미세하게 옮겼을 떄 거리 < 현재 두점의 거리)
	{
		if (첫번째 선분에 있는점을 오른쪽으로 옮긴다) 
		{
			mid = center(A, B);
			recursive_min(mid, B, C, D);
		}
		else(두번째 선분에 있는 점을 오른쪽으로 옮긴다)
		{
			mid = center(C, D);
			recursive_min(A, B, mid, D);
		}
	}
	else // 다른 선분에 있는 점을 옮긴다.
	{
		if (flag == 0) {flag = 1;} 
		else	       {flag = 0;}
		return recursive_min(A, B, C, D);
	}
	return len;
}

int 	main(void){

	my_input();
	flag = 0;
	recursive_min(A, B, C, D);
	cout << ans[0];
}
