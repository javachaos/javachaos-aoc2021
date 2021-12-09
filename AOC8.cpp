#include "BinaryMatrix.h"
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <chrono>
#include <math.h>
#include <boost/algorithm/string.hpp>
using namespace std;

struct Matrix7x7 {
    unsigned int matrix[7][7];
    Matrix7x7() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    Matrix7x7(unsigned int m[7][7]) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                matrix[i][j] = m[i][j];
            }
        }
    }

    bool operator==(const Matrix7x7& other) const {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    void operator++() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                matrix[i][j]++;
            }
        }
    }
    void operator--() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                matrix[i][j]--;
            }
        }
    }
    void operator+=(const Matrix7x7& m) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                matrix[i][j] += m.matrix[i][j];
            }
        }
    }
    void operator-=(const Matrix7x7& m) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                matrix[i][j] -= m.matrix[i][j];
            }
        }
    }
    void operator*=(const Matrix7x7& m) {
        Matrix7x7 temp;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 7; k++) {
                    temp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
                }
            }
        }
        *this = temp;
    }
    // Search along each row and column x,y to ensure we can place a value.
    // (ensure permutation matrix)
    bool can_place(int x, int y) {
        for (int i = 0; i < 7; i++) {
            if (matrix[i][y] > 0) {
                return false;
            }
            if (matrix[x][i] > 0) {
                return false;
            }
        }
        return true;
    }

    bool is_permutation() {
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if(can_place(i,j)) {
                    return false;
                }
            }
        }
        return true;
    }
};

vector<string>& permute(vector<string> &input, string a, int l, int r)
{
    if (l == r)
        input.push_back(a);
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(input, a, l+1, r);
            swap(a[l], a[i]);
        }
    }
    return input;
}

int part_one(const vector<string> &codes) {
    int count = 0;
    for (auto code : codes) {
        if (code.size() == 2) {
            count++;
        }
        if (code.size() == 3) {
            count++;
        }
        if (code.size() == 4) {
            count++;
        }
        if(code.size() == 7) {
            count++;
        }
    }
    return count;
}

int ctoidx(const char &s) {    
    switch(s) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
    }
    return -1;
}

void encode_matrix(Matrix7x7 &m, const string &permute, const string &code) {
    for (auto s : permute) {
        for (auto c : code) {
            if (m.can_place(ctoidx(c), ctoidx(s))) {
                m.matrix[ctoidx(c)][ctoidx(s)] = 1;
            }
        }
    }
}

unsigned int part_two(const vector<string> &codes, const vector<string> &four_digits) {
    unsigned int count = 0;
    map<string, Matrix7x7> possible_solutions;
    vector<string> permutations;
    vector<string> correct_mappings = {"cf", "acf", "bcdf", "abcdefg"};

    //find the shortest string in codes.
    auto smin = *std::min_element(codes.begin(), codes.end(), 
                     [] (const std::string& s1, const std::string& s2) { 
                         return s1.length() < s2.length(); });
    for (string s : correct_mappings) {
        if (s.length() == smin.length()) {
            permutations = permute(permutations, s, 0, s.length() - 1);
        }
    }
    for (auto permute : permutations) {
        Matrix7x7 m;
        for (auto code : codes) {
            encode_matrix(m, permute, code);
        }
        possible_solutions.insert(pair<string, Matrix7x7>(permute, m));
    }
    for (auto code : codes) {
        
    }
    return count;
}

int main() {
    std::string delimiter = " | ";
    vector<string> codes;
    vector<string> four_digits;
    ifstream file("./data/input_aoc8.txt");
    string line;
    int part1_count = 0;
    int part2_count = 0;
    unsigned long int count2 = 0;

    while (getline(file, line)) {        
        string first = line.substr(0, line.find(delimiter));
        string second = line.substr(line.find(delimiter) + delimiter.length());
        string delim = " ";
        boost::split(codes, first, boost::is_any_of(" "));
        boost::split(four_digits, second, boost::is_any_of(" "));
        part1_count += part_one(four_digits);
        //part2_count += part_two(codes, four_digits);
    }
    file.close();
    
    cout << "Part 1 -> Count: " << part1_count << endl;
    cout << "Part 2 -> Count: " << part2_count << endl;
}


