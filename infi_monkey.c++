#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

string infi_monkey() {
    int max_score = 0;
    int score;
    string given_str;
    string  generated_str = "";
    string best_match = "";
    string alphabets = "abcdefghijklmnopqrstuvwxyz ";
    given_str = "methinks it is like a weasel";
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < given_str.length(); j++) {
            generated_str += alphabets[rand() % alphabets.length()];
        }
        for (int k = 0; k < given_str.length(); k++) {
            if (generated_str[k] == given_str[k]) {
               score ++; 
            }
        }        
        if (score > max_score) {
            max_score = score;
            best_match = generated_str;
        }    
    }
        return best_match;
}

int main(int argc, char* argv[]) {
    cout << infi_monkey();
    return 0;
}
