#include "timebomb.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>



int main( ) {
	int N, result, this;
	queue<int> q;
	box_ready( );
	N = box_size( );
	
	for (int i = 1; i <= N; i += 2){
		if (i != N) 	{result = box_comp(i, i + 1);}
		else 		{break;}

		if (result == 1) {q.push(i);}
	}

	for(int i = 0; i < n; i++){
		if(max<arr[i]) { max = arr[i];}
	}

	box_report(this);
}
