#include <iostream>
#include <vector>

using namespace std;


vector<string> fizzbuzz(int no) {

}    


int main(int argc, char* argv) {
    int n = stoi(argv[1]);

    vector<string> fb = fizzbuzz(n);

    for (int i: fb) {
        cout << i << "  ";
    }    

    return 0;
        
}
