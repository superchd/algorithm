#include <iostream>
#include <string>

string  example;
string  reverse;

using namespace std;

void    my_input(void){
    cin >> example;
    reverse = example;
    reverse.reverse(example.length());
    return;
}


int main(void){

    my_input();
    cout << reverse << endl << example << endl;
    return;




}
