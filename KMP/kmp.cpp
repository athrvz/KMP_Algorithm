#include <bits/stdc++.h>
using namespace std;

void /*bool*/ kmp(string txt, string patt) {
	int txtLen = txt.size(), pattLen = patt.size();
	
	if(txtLen == 0) return;
	
	// Precomputing Prefix Table
	vector <int> prefTable(pattLen + 1, 0);
	for(int i = 1; i < pattLen; i++) {
		int j = prefTable[i + 1];
		while(j > 0 && patt[j] != patt[i])
			j = prefTable[j];
		if(j > 0 || patt[j] == patt[i])
			prefTable[i + 1] = j + 1;
	}
	// for(int x : prefTable) cout << x << " ";

	// Match one by one
	for(int i = 0, j = 0; i < txtLen; i++) {
		if(txt[i] == patt[j]) {
			if(++j == pattLen) // whole patt matched
				cout << "shift: " << i - j + 1 << endl;
				// return true;
		}
		else if(j > 0) {
			j = prefTable[j];
			i--;
		}
	}
	// return false;
}

int main(int argc, char const *argv[]) {
	string text = "ABCABABCABAC";
    string pattern = "CAB";
    // string pattern = "BAB";
 
    kmp(text, pattern);
	return 0;
}