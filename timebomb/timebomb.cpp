#include "timebomb.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int result, ans, flag;

void tour(int depth, queue<int> q, int size){

	queue<int> Next;
	int	prev, curr;

	if (size == 1) {flag = q.front(); return;}

	for (int i = 1; i <= size / 2; i += 1){
		prev = q.front(); q.pop();
		curr = q.front(); q.pop();

		if (i != size) 	{result = box_comp(prev, curr);}
		else 		{break;}

		if (result == 1) {Next.push(prev);}
		else             {Next.push(curr);}
	}
	Next.push(q.front());
	tour(depth + 1, Next, Next.size());
}

int main( ) {

	queue<int> q;
	queue<int> Next;

	box_ready( );
	N = box_size( );
	
	for (int i = 1; i <= N; i++){
		q.push(Box[i]);
	}
	tour(0, q, N);
	box_report(flag);
}
