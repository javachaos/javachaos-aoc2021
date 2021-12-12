#include "BinaryMatrix.h"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <math.h>
#include <chrono>
#include <boost/algorithm/string.hpp>
using namespace std;

int part_one(const vector<string> &codes) {
    int count = 0;
    for (string code : codes) {
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

char itochar(const int &i) {
        switch(i) {
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
        case 3:
            return 'd';
        case 4:
            return 'e';
        case 5:
            return 'f';
        case 6:
            return 'g';
        }
        return 'x';
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

unsigned int part_two(const vector<string> &codes, const vector<string> &four_digits) {
    unsigned int count = 0;
    std::map<int, string> map = {
        {0, ""},
        {1, ""},
        {2, ""},
        {3, ""},
        {4, ""},
        {5, ""},
        {6, ""},
        {7, ""},
        {8, ""},
        {9, ""}
    };
    std::map<int, string> five_set = {
        {2, ""},
        {3, ""},
        {5, ""}
    };
    std::map<int, string> six_set = {
        {0, ""},
        {6, ""},
        {9, ""}
    };
    std::unordered_map<int, int> delta_map;
    vector<int> index_list_5 = {2, 3, 5};
    vector<int> index_list_6 = {0, 6, 9};
    vector<string> all_codes;
    all_codes.insert(all_codes.end(), codes.begin(), codes.end());
    all_codes.insert(all_codes.end(), four_digits.begin(), four_digits.end());
    for (auto c : all_codes) {
        switch(c.length()) {
            case 2:
                delta_map[ctoidx('c')] = ctoidx(c[0]);
                delta_map[ctoidx('f')] = ctoidx(c[1]);
                break;
            case 3:
                delta_map[ctoidx('a')] = ctoidx(c[0]);
                delta_map[ctoidx('c')] = ctoidx(c[1]);
                delta_map[ctoidx('f')] = ctoidx(c[2]);
                break;
            case 4:
                delta_map[ctoidx('b')] = ctoidx(c[0]);
                delta_map[ctoidx('d')] = ctoidx(c[1]);
                delta_map[ctoidx('c')] = ctoidx(c[2]);
                delta_map[ctoidx('f')] = ctoidx(c[3]);
                break;
            case 7:
                delta_map[ctoidx('a')] = ctoidx(c[0]);
                delta_map[ctoidx('b')] = ctoidx(c[1]);
                delta_map[ctoidx('c')] = ctoidx(c[2]);
                delta_map[ctoidx('d')] = ctoidx(c[3]);
                delta_map[ctoidx('e')] = ctoidx(c[4]);
                delta_map[ctoidx('f')] = ctoidx(c[5]);
                delta_map[ctoidx('g')] = ctoidx(c[6]);
                break;
            
        }
    }
    set<string> s;
    set<string> t;
    for (auto d : all_codes) {
        switch(d.length()) {
            case 2:
                map[1] = d;
                break;
            case 3:
                map[7] = d;
                break;
            case 4:
                map[4] = d;
                break;
            case 5:
                s.insert(d);
                if (s.size() == 3) {
                    vector<string> five_temp(t.begin(), t.end());
                    five_set[index_list_5[0]] = five_temp[0];
                    five_set[index_list_5[1]] = five_temp[1];
                    five_set[index_list_5[2]] = five_temp[2];
                }
                break;
            case 6:
                t.insert(d);
                if (t.size() == 3) {
                    vector<string> six_temp(t.begin(), t.end());
                    six_set[index_list_6[0]] = six_temp[0];
                    six_set[index_list_6[1]] = six_temp[1];
                    six_set[index_list_6[2]] = six_temp[2];
                }
                break;
            case 7:
                map[8] = d;
                break;
            
        }
    }

    while (map.size() < 10) {
        vector<string> five_temp(t.begin(), t.end());
        vector<string> six_temp(t.begin(), t.end());
        for (auto pair : map) {
            switch (pair.second.length()) {
                case 5:
                    map[index_list_5[0]] = five_temp[0];
                    map[index_list_5[1]] = five_temp[1];
                    map[index_list_5[2]] = five_temp[2];
                    next_permutation(index_list_5.begin(), index_list_5.end());
                    break;
                case 6:
                    map[index_list_6[0]] = six_temp[0];
                    map[index_list_6[1]] = six_temp[1];
                    map[index_list_6[2]] = six_temp[2];
                    next_permutation(index_list_6.begin(), index_list_6.end());
                    break;
            }
        }
        for (auto m : map) {
            int valid = 1;
            for (auto c : m.second) {
                if (ctoidx(c) > 0 && (delta_map[ctoidx(c)] != ctoidx(c))) {
                    valid = 0;
                    map.erase(m.first);
                    break;
                }
            }
            if (!valid) {
                break;
            }
        }//TODO fiddle with this

    }
    cout << "map size: " << map.size() << endl;
    cout << "Map: " << endl;
    for (auto m : map) {
        cout << m.first << ": " << *m.second.begin() << endl;
    }
    if (map.size() != 10) {
        cout << "Error: map size is not 10" << endl;
        return 0;
    }
    int i = 3;
    for (auto s : four_digits) {
        for (auto m : map) {
            if (s.compare(m.second) == 0) {
                    count += m.first * pow(10, i);
            }
        }
        i--;
    }
    return count;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::string delimiter = " | ";
    vector<string> codes;
    codes.reserve(10);
    vector<string> four_digits;
    four_digits.reserve(4);
    string line;
    int part1_count = 0;
    unsigned long int part2_count = 0;
    ifstream file("./data/input_aoc8.txt");
    while (getline(file, line)) {        
        string first = line.substr(0, line.find(delimiter));
        string second = line.substr(line.find(delimiter) + delimiter.length());
        string delim = " ";
        boost::split(codes, first, boost::is_any_of(" "));
        boost::split(four_digits, second, boost::is_any_of(" "));
        part1_count += part_one(four_digits);
        part2_count += part_two(codes, four_digits);
    }
    file.close();
    
    cout << "Part 1 -> Count: " << part1_count << endl;
    cout << "Part 2 -> Count: " << part2_count << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
}


