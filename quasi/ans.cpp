#include <iostream>
#include <cstring>

using namespace std;

struct element{
	string  str;
	int	row;
	int	col;
};

int main(void) {
    string a, b;
    element** table;
    cin >> a >> b;

    // make new string
    table = new element * [a.size()];
    for (int i = 0; i < a.size(); i++) {
        table[i] = new element[b.size()];
    }

    //dynamic programming
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 0; j < b.size() - 1; j++) {
//		cout << "Here is [" << i << "][" << j << "]\n" ;
//		cout << "a[" << i << "] = " << a[i] << ", b[" << j << "] = " << b[j] << endl;
		element left_upper  = table[i][j];
		element left	= table[i + 1][j];
		element upper	= table[i][j + 1];
//		cout << "left_upper is: " << left_upper.str << endl;
//		cout << "left is: " << left.str << endl;
//		cout << "upper is: " << upper.str << endl;
		if (a[i] != b[j]) {
			if      (left_upper.str.size() >= left.str.size())
			 	{table[i + 1][j + 1] = left_upper;
				if (left_upper.str.size() < upper.str.size())
					{table[i + 1][j + 1] = upper;}
				}
                    	else if (left_upper.str.size() < left.str.size())
				{table[i + 1][j + 1] = left;
				if (left.str.size() < upper.str.size())
					{table[i + 1][j + 1] = upper;}
			}
		}
		else {
			if      (left_upper.str.size() + 1 >= left.str.size())
			 	{
					if (i - left_upper.row <= 2 && j - left_upper.col <= 2){ 
					table[i + 1][j + 1].str = table[i][j].str + a[i];
				 	table[i + 1][j + 1].row = i;
				 	table[i + 1][j + 1].col = j;
					}
					else {
						table[i + 1][j + 1] = table[i][j - 1];
					}
				}
				if (left_upper.str.size() + 1 < upper.str.size())
					{table[i + 1][j + 1] = table[i][j + 1];}
                    	else if (left_upper.str.size() + 1 < left.str.size())
				{table[i + 1][j + 1] = table[i + 1][j];
				if (left.str.size() < upper.str.size())
					{table[i + 1][j + 1] = table[i][j + 1];}
				}	
    	}
//		cout << "table[i+1][j+1]: " <<  table[i+1][j+1].str << endl;
    }
    }
    cout << table[0][b.size() - 1].str << endl;

    return 0;
}
