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
#include <bitset>
#include <chrono>
#include <boost/algorithm/string.hpp>
using namespace std;

class conststr {
    const char* p;
    std::size_t sz;
public:
    template<std::size_t N>
    constexpr conststr(const char(&a)[N]): p(a), sz(N - 1) {}
 
    // constexpr functions signal errors by throwing exceptions
    // in C++11, they must do so from the conditional operator ?:
    constexpr char operator[](std::size_t n) const
    {
        return n < sz ? p[n] : throw std::out_of_range("");
    }
    constexpr std::size_t size() const { return sz; }
};

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
    return 7;
}

bitset<7> encode(string &s) {
    // Default constructor. 
    // Constructs a bitset with all bits set to zero.
    bitset<7> encoded;
    for (char c : s) {//Set the relevant bits
        encoded.set(ctoidx(c));
    }
    return encoded;
}

bitset<7> encode_known(const vector<string> &codes, const uint d) {
    bitset<7> output;
    for (string s : codes) {
        if (s.length() == d) {
            output = encode(s);
        }
    }
    return output;
}

// This function/method is called once for each sample (line in the data input file)
//
// To solve this task with min. space and time use a bitset to represent ABCDEFG -> (1,1,1,1,1,1,1,1),
// e.g AB -> (1,1,0,0,0,0,0), for this problem order does not matter.
// using a bitset gives us the ability to use bitwise functions on the data while using minimal space
// symmetric difference and difference will be represented using p^q(p xor q), p&q~(p and not q) respectively
// for each set of observations (the first 10 sequences of characters) we substract what we don't know
// from what we know in the same order to form a unique pattern we can use to correctly identify what we don't know.
// To accomplish this we will emplore a bitset datastructure to hold the bits of each digit. (represented as described above)
// 
// 1. First we calculate the mappings of what we already know, namely values which have string lengths of:
//   2(1 display), 4(4 display), 6 (8 display) and 3 (7 display)
// 2. From this we then compute a difference vector for each unknown mapped to each known.
// 3. Using this new information compute a correct mapping then calculate the four digit code for this sample.
unsigned int part_two(const vector<string> &codes, const vector<string> &four_digits) {

    //knowns
    const std::bitset<7> one =   encode_known(codes, 2);
    const std::bitset<7> four =  encode_known(codes, 4);
    const std::bitset<7> seven = encode_known(codes, 3);
    const std::bitset<7> eight = encode_known(codes, 7);

    //unknowns
    std::bitset<7> zero;
    std::bitset<7> two;
    std::bitset<7> three;
    std::bitset<7> five;
    std::bitset<7> six;
    std::bitset<7> nine;

    for (string str : codes) {
        bitset<7> x = encode(str);
        uint8_t first =  (x & ~one  ).count();
        uint8_t second = (x & ~four ).count();
        uint8_t third =  (x & ~seven).count();
        uint8_t forth =  (x ^ eight).count();

        if (first == 3 // the first bitwise set difference between x and one has 3 one bits set.
        && second == 2 // the second bitwise set difference between x and four has 2 one bits set.
        &&  third == 2 // the third bitwise set difference between x and seven has 2 one bits set.
        &&  forth == 2) { // finally the set symmetric difference between x and eight has 2 bits set.
            //this corresponds to the digit 3.
            //to discover these mappings first start with the number you have, in this case 3
            //then perform the operations with the number 3 as x in this case.
            three = x;
        }
        
        if (first == 4
        && second == 3
        &&  third == 3
        &&  forth == 1) {
            zero = x;
        }

        if (first == 4
        && second == 3
        &&  third == 3
        &&  forth == 2) {
            two = x;
        }

        if (first == 4
        && second == 2
        &&  third == 3
        &&  forth == 2) {
            five = x;
        }

        if (first == 5
        && second == 3
        &&  third == 4
        &&  forth == 1) {
            six = x;
        }

        if (first == 4
        && second == 2
        &&  third == 3
        &&  forth == 1) {
            nine = x;
        }
    }
    
    //At this point using each bitset we have a correct mapping for each of the output digits
    //so all that is left is to use the mapping to calculate the output.
    string output = "";
    for (string d : four_digits) {
        bitset<7> x = encode(d);
        if (x == zero)  { output.push_back('0'); }
        if (x == one)   { output.push_back('1'); }
        if (x == two)   { output.push_back('2'); }
        if (x == three) { output.push_back('3'); }
        if (x == four)  { output.push_back('4'); }
        if (x == five)  { output.push_back('5'); }
        if (x == six)   { output.push_back('6'); }
        if (x == seven) { output.push_back('7'); }
        if (x == eight) { output.push_back('8'); }
        if (x == nine)  { output.push_back('9'); }
    }
    
    return stoi(output);
}

int main() {
    std::string delimiter = " | ";
    vector<string> codes;
    codes.reserve(10);
    vector<string> four_digits;
    four_digits.reserve(4);
    string line;
    int part1_count = 0;
    unsigned long int part2_count = 0;
    ifstream file("./data/input_aoc8.txt");
    auto start = std::chrono::high_resolution_clock::now();
    while (getline(file, line)) {
        string first = line.substr(0, line.find(delimiter));
        string second = line.substr(line.find(delimiter) + delimiter.length());
        string delim = " ";
        boost::split(codes, first, boost::is_any_of(" "));
        boost::split(four_digits, second, boost::is_any_of(" "));
        part1_count += part_one(four_digits);
        part2_count += part_two(codes, four_digits);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    file.close();
    // This code is 10x slower than my rust implementation 
    // (same algorithm, main difference is in rust I could use a switch statement to avoid branching).
    // switch statements in C++ are too big of a hassle (constexpr ect), rust makes non-branching code 10x easier.
    cout << "Part 1 -> Count: " << part1_count << endl;
    cout << "Part 2 -> Count: " << part2_count << endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds" << endl;
}


