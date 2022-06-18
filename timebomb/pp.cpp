#include <iostream>
#include <vector>
#include <algorithm>
#include "timebomb.h"

using namespace std;

struct nset {
	int index;
	int val;
};

int 	main(){
	
	int N, result;
	int 	*Winner;
	int 	k;
	int 	sz;

	box_ready();
	sz = box_size();
	k = sz;
	N = sz;

	Winner = new int[k];

	for(int i = 1; i < k; i++) {
		Winner[i] = -1;
	}

	int j = k;

	for (int i = k - 1; i >= k / 2 && j != 1; i--){
		if (box_comp(j, j - 1) == -1) Winner[i] = j - 1;
		else Winner[i] = j;
		j -= 2;
	}
	
	if (j == 1) {
		Winner[k / 2] = 1;
		int challenger = Winner[k / 2 * 2];
		if (box_comp(challenger, 1) == 1) Winner[k / 2] = challenger;
	}

	for (int i = k / 2 - 1; i >= 1; i--){
		j = 2 * i;
		if (box_comp(Winner[j], Winner[j + 1]) == -1) Winner[i] = Winner[j + 1];
		else Winner[i] = Winner[j];
	}

	int max_index = Winner[1];

	nset 		example;
	vector<nset>	compare;

	for (int i = 1; i < k; i++)
  		cout << Winner[i] << " "; //모든 값 출력 : 0 1 2 3 4
	cout << endl;

	for (int i = 1; i <= sz; i++){
		if (Winner[i] == max_index) {
			if (i != 8){
			example.index = Winner[i + 1];
			example.val   = Box[Winner[i + 1]];
			compare.push_back(example);
			}
			if (i != 1){
				example.index = Winner[i - 1];
				example.val   = Box[Winner[i - 1]];
				compare.push_back(example);
			}
		}
	}

	for (int i = 1; i < k; i++)
  		cout << compare[i].val << " "; //모든 값 출력 : 0 1 2 3 4
	cout << endl;

	int max=compare[0].val;
	int idx;
	for (int i = 1; i < k; i++)
	{
		if(max < compare[i].val)
		{
		    max = compare[i].val;
		    idx = compare[i].index;
		}
	}
	result = idx;
	cout << endl << result << endl;
	box_report(result);
}
