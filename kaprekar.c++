#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int next_term(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());
    int min = stoi(s);
    reverse(s.begin(), s.end());
    int max = stoi(s);
    return max - min;
}        

vector<int> sequence(int no) {
    vector<int> seq;

    do {
        seq.push_back(no);
        no = next_term(no);
    }while (no != next_term(no));

    return seq;
}    

       
int main(int argc, char* argv[]) {
    int START = stoi(argv[1]);

    vector<int> kaprekar_seq = sequence(START);
    
    for (const int i : kaprekar_seq) {
        cout << setw(6) << i;
    }

    return 0;
}


