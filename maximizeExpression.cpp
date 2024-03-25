#include <bits/stdc++.h> 
using namespace std; 

pair<int, int> maxExpression(vector<int> p, vector<int> x) {
    int maxDiff = INT_MIN, maxSum = INT_MIN, maxi, maxj;
    int n = x.size();
    for (int i = n-1; i >=0; i--) {
        maxDiff = max(p[i] - x[i], maxDiff);
        if (maxDiff == p[i] - x[i])
            maxi = i;
        maxSum = max(p[i] + x[i], maxSum);
        if (maxSum == p[i] + x[i])
            maxj = i;
    }
    return make_pair(maxi, maxj);
}

int main() {
    vector<int> x = {1, 3, 4, 5, 7, 8};
    vector<int> p = {8, 1, 20, 7, 8, 9};
    pair<int, int> ans = maxExpression(p, x);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}