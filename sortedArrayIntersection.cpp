#include <bits/stdc++.h> 
using namespace std; 

vector<int> printIntersection(int arr1[], int arr2[], int m, int n) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else {
            result.push_back(arr2[j]);
            i++;
            j++;
        }
    }
    return result;
} 

int main() 
{ 
    int arr1[] = { 1, 2, 4, 5, 6 }; 
    int arr2[] = { 2, 3, 5, 7 }; 
  
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> ans = printIntersection(arr1, arr2, m, n); 
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0; 
}
