#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <stdbool.h>

using namespace std;

int		n,k;

vector<string> 	words;

bool	palindrome(string example){

	for (int i = 0; i < example.length(); i++){
		if (example[i] != example[example.length() - i - 1]) {
			return false;}
	}
	return true;
}

bool	psudo(string example){

	string subtract;

	for (int i = 0; i < example.length() - 1; i++){
		subtract = example.erase(i, i);
		if (palindrome(subtract)) {
			cout << "true";
			return true;}
	}
	cout << "false";
	return false;
}

void	my_input(void){

	string	word_input;
	cin  >> k;
	cin  >> word_input;

	for (int i = 0; i < k; i++){
		words.push_back(word_input);}
	return;
}

void	my_judge(vector<string> inputs){
		
	for(auto word : inputs){
		if (palindrome(word)){
			cout << "1";
		}
		else if(psudo(word)){
			cout << "2";
		}
	}
	return ;
}

int	main(void) {

//	my_input();
//	my_judge(words);
	string num;
	cin >> num;
	psudo(num);
}
