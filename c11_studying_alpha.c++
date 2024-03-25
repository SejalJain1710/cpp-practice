#include <iostream>
#include <vector>

using namespace std;

bool study_aplha(string known, string word) {
    sort(known.begin(), known.end());
    sort(word.begin(), word.end());
    return (strcmp(known, word) == 0)
}

int main(int argv, char* argc) {
    int n;
    string s, w, ans;
    cin >> s;
    cin >> n ;
    for (int t = 0; t < n; t++) {
        cin >> w;
        ans = if study_alpha(s, w)? "Yes": "No";
        cout << ans;
    }
    return 0;
}

