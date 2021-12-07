#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream file("./data/input_aoc3.txt");
    string line;
    vector<string> input;
    while (getline(file, line)) {
        input.push_back(line);
    }//TODO Complete this
    
    return 0;
}