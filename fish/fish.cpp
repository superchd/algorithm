#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <stdbool.h>
#include <array>
using namespace std;

int		n, m,k;

vector<vector<int>> 	numbers;

void	my_input(void){

	int		num;
	vector<int>	example;

	cin  >> k;
	for (int j = 0; j < 5; j++){
		example.clear();
		for (int i = 0; i < k; i++){
			cin >> num;
			example.push_back(num);}
		numbers.push_back(example);
	}
	return;
}

int	monotonic(vector<int> ex){

	int cnt = 0;
	// 순차적으로 증가하는 구간이 몇개인가?
	for(int i = 0; i < ex.size() - 1; i++){
		if (ex[i] + 1 != ex[i + 1]) {cnt++;}
	}
	return cnt;
}

void	my_sol(void){
	int flag;
	
	// 벡터 하나씩 검증하자
	for (int k = 0; k < numbers.size(); k++){
		// 벡터하나를 함수에 넣어서 리턴하는 값으로 결과를 판단
		flag = monotonic(numbers[k]);
		if (flag == 2) 	   {cout << "one";}
		else if (flag == 3) {cout << "two";}
		else		   {cout << "over";}
		cout << endl;
	}
	return;
}

int	main(void) {
	my_input(); // 입력받기
	my_sol();
}
