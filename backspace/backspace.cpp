#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <stdbool.h>
#include <array>
using namespace std;

#define MAX 1000

int		n, m,k;
int 		arr[MAX] = {0,};
bool 		visited[MAX] = {0,};

struct word_set{
	string first_wd;
	string second_wd;	
};

vector<word_set> 	words;
vector<int>		select_index;

void	my_input(void){

	word_set 	example;
	string 		word_1;
	string 		word_2;

	cin  >> k;

	for (int i = 0; i < k; i++){
		cin >> word_1;
		cin >> word_2;
		example.first_wd	= word_1;
		example.second_wd 	= word_2;
		words.push_back(example);}
	return;
}

vector<int> make_vec(int num){

	vector<int> example;

	for (int i = 0; i < num; i++){
		example.push_back(i);
	}
	return example;
}

bool	is_included(vector<int> vec, int num) {

	auto it = find(vec.begin(), vec.end(), num);
	if (it == vec.end()) {
        	return false;
	}
	else{
        	return true;
	}
}

string	make_new_str(string a){

	string new_str;
	string new_new;
	
	for (int i = 0; i < a.size(); i++){
		if(i != a.size() - 1){
			if(a[i + 1] == '/') {
				new_str.append(1, '/');}
		}
	}
	for (int i = 0; i < new_str.size(); i++){
		if(new_str[i] != '/') {
			new_new.append(1, '/');}
	}
	cout <<  "thank" << new_new << endl;
	return new_new;
}

bool dfs(int num, int cnt, string a, string b)
{
	string final_str;
	string real_str;
	n = a.size();
	
    if(cnt == m)
    {
        for(int i = 0; i < m; i++){
		select_index.push_back(arr[i] - 1);
	//	cout << arr[i] - 1;
	}
	for (int i = 0; i < a.size(); i++) {
		if (is_included(select_index, i)){
			final_str.append(1, a[i]);}
		else {
			final_str.append(1, '/');}
	}
	for (int i = 0; i < select_index.size(); i++) {
	//	cout << select_index[i];
	}
	cout << endl;
	cout << final_str << endl;
	real_str = make_new_str(final_str);
	select_index.clear();
	if (real_str == b) 	{
		final_str.erase();
		real_str.erase();
		return true;}
	else			{
		final_str.erase();
		real_str.erase();
		return false;}
        cout << '\n';
    }
    for(int i = num; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i+1,cnt+1, a ,b);
            visited[i] = false;
        }
    }
}

bool	compare_words(string a, string b){

	string final_str;
	string real_str;
	n = a.size();
	
	if (dfs(1, 0, a , b)) {return true;}
	else {return false;}

}

bool	my_judge(word_set example){
	
	string a;
	string b;
	
	a = example.first_wd;
	b = example.second_wd;

	for (m = 0; m < a.size(); m++){
		if (compare_words(a,b)) { return true;}
	}
	return false;
}

void	my_sol(void){

	for (int i = 0; i < k; i++) {
		if (my_judge(words[i]))
			{cout << "YES";}
		else
			{cout << "NO";}
	}
}

int	main(void) {
	my_input();
	my_sol();
}
