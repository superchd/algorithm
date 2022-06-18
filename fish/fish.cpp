#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <stdbool.h>
#include <array>
using namespace std;


int		n, m,k;
int 		arr[MAX] = {0,};
bool 		visited[MAX] = {0,};


vector<vector<int>> 	numbers;

void	my_input(void){

	int		num;
	vector<int>	example;

	cin  >> k;
	for (int j = 0; j < 5; j++){
		for (int i = 0; i < k; i++){
			cin >> num;
			example.push_back(num);}
		number.push_back(example);
	}
	return;
}

bool	test(int num, vector<int>example){
	
	for (int i = 0; i < example.size(); i++){
		if ( )
		{             }
	}

}

bool	filp(void){

	for (int i = 0; i < example.size(); i++){
		if (!test(i, example)){
			return false;
		}
	}
	return true;
}

bool	monotonic(vector<int> example){

	for(int i = 0; i < example.size(); i++){
		if (example[i] == i + 1) {
			return false;}
	}
	return true;
}

void reverse_str(int start, int end) {
 
    int test, test1;
    cin>>test>>test1;
 
    int	num;
 
    vector<int> vec;
    
    for(int i = 0; i < test; i++){
        cin >> num;
        vec.push_back(num);
    }
    2
    for(int i = 0; i < test; i++){
        reverse(vec[i].begin(), vec[i].end());
    }
    return 0;
}

int	main(void) {
	my_input();
	my_sol();
}
