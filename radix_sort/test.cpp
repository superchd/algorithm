#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int		target;
int		total = 0;
int		temp;

vector<string> 	words;

map<string, int> m;

void	my_input(){
	string word;
	cin >> target;
	temp = target;
	while(total < 30){
	       cin >> word;	
		words.push_back(word);
		m.insert({word, total + 1});
		total++;
	}
	return;
}

void	radix_sort(int idx, vector<string> range_str, int target){

	if (range_str.size() == 1) {
		cout << m.find(range_str[0])->second << endl; 
		return;}

	vector<string> A;
	vector<string> G;
	vector<string> C;
	vector<string> T;
	vector<string> N;
	vector<vector<string>> Next;

	int num_a = 0;
	int num_g = 0;
	int num_c = 0;
	int num_t = 0;
	int num_n = 0;
	int bucket = 0;

	vector<int> counts;
	for (int i = 0; i < range_str.size(); i++){
		if (range_str[i][idx] == 'a') {A.push_back(range_str[i]); 	num_a++;}
		else if (range_str[i][idx] == 'c') {C.push_back(range_str[i]); num_c++;}
		else if (range_str[i][idx] == 'g') {G.push_back(range_str[i]); num_g++;}
		else if (range_str[i][idx] == 'n') {T.push_back(range_str[i]); num_n++;}
		else 				   {N.push_back(range_str[i]); 	num_t++;}
	}
	counts.push_back(num_a);counts.push_back(num_c);counts.push_back(num_g);counts.push_back(num_n);counts.push_back(num_t);
	Next.push_back(A);Next.push_back(C);Next.push_back(G);Next.push_back(T);Next.push_back(N);
	
	target -= counts[0];

	while(target > 0){
		bucket++;
		target -= counts[bucket];
	}
	target += counts[bucket];
	radix_sort(idx + 1, Next[bucket], target);
}

int	main(void){
	my_input();
	radix_sort(0, words, target - 1);
	target = temp;
	radix_sort(0, words, target);
	target = temp;
	radix_sort(0, words, target + 1);
	return 0;
}
