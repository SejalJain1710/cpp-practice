#include <bits/stdc++.h> 
using namespace std; 

int minSteps(int n) {
    if (n == 1)
        return 0;
    int steps[100] = {0};
    steps[1] = 0;
    for(int i = 2; i <= n; i++){
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if (i % 3 == 0)
            op1 = steps[i/3];
        if (i % 2 == 0)
            op2 = steps[i/2];
        op3 = steps[i-1];
        steps[i] = min(op1, min(op2, op3)) + 1;
        cout << steps[i] <<"\t";
    }
    return steps[n];
}

int main() {
    cout << minSteps(12) << endl;
    return 0;
}
