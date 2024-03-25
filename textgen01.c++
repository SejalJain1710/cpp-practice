#include <iostream>
#include <fstream>
#include <random>
#include <unordered_set>

using namespace std;

const string ALPHABETS("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
default_random_engine rand_engine;
uniform_int_distribution<size_t> dist(0, ALPHABETS.length() - 1);

string make_word(int how_long) {
    string word;
    for (int i = 0; i < how_long; ++i) {
        word += ALPHABETS[dist(rand_engine)];
    }            
    return word;
}

unordered_set<string> load_words(string filename) {
    unordered_set<string> words;
    ifstream sowpods(filename);
    string word;
    while (sowpods >> word) {
        words.insert(word);
    }
    return words;
}

int main(int argc, char* argv[]) {
    const int word_length = stoi(argv[1]);
    string word;
    unordered_set<string> words = load_words("sowpods.txt");

    for (int words_generated = 0; words_generated < 10; ++words_generated) {
        int attempts = 0;
        while (words.find(word = make_word(word_length)) == words.end()) {
            ++attempts;
        }
        cout << attempts << " " << word << endl;
    }
    return 0;
}

