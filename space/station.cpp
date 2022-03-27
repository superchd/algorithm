#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


struct 	Point{
	float x;
	float y;
	float z;
};

Point A, B, C, D;


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

Point   coordinate(Point first, Point second, int t){

	Point current;
	float epsilon;

	epsilon = t / length(first, second);
	current.x = (1 - epsilon) * first.x + epsilon * second.x;
	current.y = (1 - epsilon) * first.y + epsilon * second.y;
	current.z = (1 - epsilon) * first.z + epsilon * second.z;
	return current;
}

float	min_distance(){

	Point		line_1, line_2;
	int		min;
	min 		= length(A, C);
	for(int i = 0; i < length(A, B); i++){
		line_1 = coordinate(A, B, i);
		for(int j = 0; j < length(C, D); j++){
			line_2 = coordinate(C, D, j);
			if (min > length(line_1, line_2)) {min = length(line_1, line_2);}
		}
	}
	return min;
}

int 	main(void){

	my_input();
	cout << min_distance();
}
