#include <bits/stdc++.h> 
using namespace std; 

bool isAlphabaticOrder(string s) 
{
    int n = s.length(); 
    if (n < 26)
        return false;
    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1] or s[i] - s[i-1] > 1)  
           return false; 
    }
    return true; 
} 

int main() 
{ 
    string s = "aabbbccdddeefggghhiijjjkkkklmmmmmnoopppqstttuuuvwwwxxxyz";
    if (isAlphabaticOrder(s)) 
       cout << "Yes" << endl; 
    else
       cout << "No" << endl; 
  
    return 0; 
} 