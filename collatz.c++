#include <iostream>
#include <vector>

using namespace std;

bool iseven(int num) {
    return (num % 2 == 0);
}

vector<int> collatz(int n) {
    vector<int> sequence;
    while (n != 4 ) {
        sequence.push_back(n);
        n = iseven(n)? n / 2: 3 * n + 1;
    }
    sequence.push_back(4); 
    sequence.push_back(2);
    sequence.push_back(1);
    return sequence;
}    

int main(int argc, char* argv[]) {
    vector<int> collatz_seq;
    int no;
    cout << "Number? :" ;
    cin >> no;
    collatz_seq = collatz(no);
    for (int i = 0; i < collatz_seq.size(); i++)
        cout << collatz_seq[i] << " ";
    return 0;
}    


