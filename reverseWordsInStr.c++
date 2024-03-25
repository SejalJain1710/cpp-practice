#include <iostream>

using namespace std;

string reverseSentence(string sentence) {
    string word = "";
    string reversed_sentence = "";
    for (char ch: sentence) {
        if (ch == " ") {
            reversed_sentence = word + " " + reversed_sentence;
            word = "";
        } else {
            word += ch;
        }
    }
    return reversed_sentence;
}

int main(int argc, char* argv[]) {
    string sentence = argv[1];
    string reversed_sentence = reverseSentence(sentence);
    cout << reversed_sentence;
    return 0;
} 
