#include <bits/stdc++.h>
using namespace std; 

int minLength(string str, int N, string K, int M) {
	stack<char> stackOfChar; 

	for (int i = 0; i < N; i++) {
		stackOfChar.push(str[i]);
		if (stackOfChar.size() >= M) {
			string l = ""; 
			for (int j = M - 1; j >= 0; j--) {
				if (K[j] != stackOfChar.top()) {
					int f = 0; 
					while (f != l.size()) { 

						stackOfChar.push(l[f]); 
						f++; 
					}
					break; 
				}
				else {
					l = stackOfChar.top() + l;
					stackOfChar.pop(); 
				} 
			} 
		} 
	}
	return stackOfChar.size(); 
} 

int main() 
{ 
	string S1 = "fffoxoxoxfxo"; 
	string S2 = "fox"; 

	int N = S1.length(); 
	int M = S2.length(); 

	cout << minLength(S1, N, S2, M) << endl; 
	return 0; 
} 
