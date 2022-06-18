#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>

using namespace std;

struct	work{

	int	num;
	int	C;
	int	D;
	int	empty;
};

vector<work>	w;
vector<work>	seat_a;
vector<work>	seat_b;
queue<work>	candidate;

int		N,T,k;

bool	compare(work w1, work w2){
	return w1.C > w2.C;
}

bool	compare_days(work w1, work w2){
	return w1.D < w2.D;
}

void	my_print(vector<work> w){

	for (const auto &item : w) {
        	cout << "[" << item.num << "] = " << "c: " << item.C << ", D: " << item.D << endl ;
    	}
	cout << endl;
}

void	my_print(work *w){

	for (int i = 0; i < T; i++) {
        	cout << "[" << w[i].num << "] = " << "c: " << w[i].C << ", D: " << w[i].D << endl ;
    	}
	cout << endl;
}

bool	have_seat(work w1, work *M){

	for (int i = 0; i < T; i++){
		if (M[i].empty == 0 && w1.D > i + 1)
			{return true;}
	}
	return false;
}

bool	is_full(work *M1, work *M2){
	
	for (int i = 0; i < T; i++){
		if (M1[i].empty == 0) {
			return false;
		}
		if (M2[i].empty == 0) {
			return false;
		}
	}
	return true;
}

void	my_input(){

	work		example;

	int		first, second;

	cin >> N >> T >> k;

	for (int i = 0; i < N; i++){
		
		cin >> first >> second;
		example.num = i;
		example.C = first;
		example.D = second;
		w.push_back(example);
	}
}

void	assign_seat(work w, work *M1){
	for (int j = T - 1 ; j > 0; j--){
		if (M1[j].empty == 0){
			M1[j] = w;
			M1[j].empty = 1;
			break;
		}
	}

	for (int i = 0; i < T; i++){
		if (M1[i] != 0) {
			example.num = M[i].



	}
}

void	my_sol(){
	
	work M1[100];
	work M2[100];

	sort(w.begin(), w.end(), compare);
	for (int i = 0; i < w.size(); i++){
		candidate.push(w[i]);
	}

	for (int i = 0; i < T; i++){
		M1[i].num	= -1;
		M1[i].C		= -1;
		M1[i].D		= -1;
		M1[i].empty	= 0;
	}

	for (int i = 0; i < T; i++){
		M2[i].num	= -1;
		M2[i].C		= -1;
		M2[i].D		= -1;
		M2[i].empty	= 0;
	}
	int i = 0;
	int flag = 0;
	int temp;
	while (!is_full(M1, M2)){
		//queue를 쓰면, 만약 아닐떄 어떡할꺼여? 엉??!! 
		while (!have_seat(candidate.front(), M1)) {k++;}
			assign_seat(candidate.pop(), &M1);
		while (!have_seat(w[k], M2)) {k++;}
			assign_seat(w[k], &M2);
	}
	my_print(M1);
}

int	main(void){

	my_input();
	my_sol();
}
