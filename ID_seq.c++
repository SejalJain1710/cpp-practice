#include <iostream>
#include <vector>

using namespace std;

vector<int> min_possible_number(string seq) {
       vector<int> ans{1}; //vector<int> ans(seq.length() + 1, 0);
        int consecutive_d = 0; 
        for(int i = 1; i <= seq.length(); ++i) {
            if (seq[i-1] == 'I') {
                consecutive_d = 0;
                ans.insert(ans.begin() + i, i + 1);    //ans[i] = i + 1;
             } else {
                 consecutive_d ++;
                 ans.insert(ans.begin() + i - consecutive_d, i + 1);   //ans[i - consecutive_d] = i + 1;
             }                 
        }
        return ans;
}

int main(int argc, char* argv[]) {
    string sequence;
    vector<int> min_possible_no;
    cout << "Enter seq: ";
    cin >> sequence;
    min_possible_no = min_possible_number(sequence);
    for (int number: min_possible_no) {
        cout << number;
    }
    return 0;
}
