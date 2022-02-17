#include <bits/stdc++.h> 
using namespace std;

void precomputeShifts(string patt, map <char, int> & mismatchTable) {
	int len = patt.size();
	for(int i = 0; i < len; i++) {
		char currChar = patt[i];
		int shift = max(1, len - i - 1);
		mismatchTable[currChar] = shift;
	}
}

int boyer_moore(string txt, string patt, map <char, int> & mismatchTable) {
	int skips = 0;
	for(int i = 0; i <= txt.size() - patt.size(); i += skips) {
		skips = 0;
		for(int j = patt.size() - 1; j >= 0; j--) {
			if(patt[j] != txt[i + j]) {
				if(mismatchTable[txt[i + j]] != 0) {
					skips = mismatchTable[txt[i + j]];
					break;
				}
				else {
					skips = patt.size();
					break;
				}
			}
		}
		if(skips == 0) return i;
	}
}

int main() {
	string text = "ABCABABCABAC";
    string pattern = "CAB";
    // string pattern = "BAB";
 	map <char, int> mismatchTable;
    precomputeShifts(text, mismatchTable);
    cout << "pattern found at: " << boyer_moore(text, pattern, mismatchTable);
	return 0;
}