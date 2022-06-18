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

string	new_word(string example, int index){

	string 	a;
	string	addition;
	
	for (int i = 0; i < example.length() ; i++){

		if (i != index){
			addition = example[i];
			a.append(addition);
		}
	}
	return a;
}

bool	psudo(string example){

	
	string subtract;
	string temp;

	for (int i = 0; i < example.length() - 1; i++){
		//temp = example;
		//subtract = temp.erase(i, i);// erase 하니까 진짜 메모리에 있는 값을 없애서 문제가 생기네 다른방법없나??
		subtract = new_word(example, i);	
		if (palindrome(subtract)) 
		{
			return true;
		}
	}
	return false;
}

void	my_input(void){

	string	word_input;
	cin  >> k;

	for (int i = 0; i < k; i++){
		cin >> word_input;
		words.push_back(word_input);}
	return;
}

void	my_judge(vector<string> inputs){
		
	for(auto word : inputs){
		if (palindrome(word)){
			cout << "1" << endl;
		}
		else if(psudo(word)){
			cout << "2" << endl;
		}
		else{
			cout << "3" << endl;
		}
	}
	return ;
}

int	main(void) {

	my_input();
	my_judge(words);
}
