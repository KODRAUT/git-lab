#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: textstat <file>" << endl;
        return 1;
    }
    ifstream in(argv[1]);
    if (!in) {
        cout << "Cannot open file: " << argv[1] << endl;
        return 1;
    }
    string line;
    int lines = 0, words = 0, chars = 0;
    while (getline(in, line)) {
        lines++;
        chars += line.size();
        stringstream ss(line);
        string w;
        while (ss >> w) words++;
    }
    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Chars: " << chars << endl;
    return 0;
}
