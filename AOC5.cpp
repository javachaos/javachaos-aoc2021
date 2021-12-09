#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <chrono>
#include <math.h>
using namespace std;

struct Point {
    ushort x;
    ushort y;
    Point(ushort x, ushort y) : x(x), y(y) {}
    string toString() {
        return to_string(x) + "," + to_string(y);
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};
struct Line {
    Point start;
    Point end;
    Line(Point start, Point end) : start(start), end(end) {}
    string toString() {
        return start.toString() + " -> " + end.toString();
    }
    bool operator==(const Line& other) const {
        return start == other.start && end == other.end;
    }
};

// Return the point where the two lines segments intersect
Point intersect(Line l0, Line l1) {
    double p0_x = l0.start.x;
    double p0_y = l0.start.y;
    double p1_x = l0.end.x;
    double p1_y = l0.end.y;
    double p2_x = l1.start.x;
    double p2_y = l1.start.y;
    double p3_x = l1.end.x;
    double p3_y = l1.end.y;

    double s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;
    double s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        double i_x = p0_x + (t * s1_x);
        double i_y = p0_y + (t * s1_y);
        return Point(i_x,i_y);
    }
    return Point(0,0); // No collision
}

void print_matrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    vector<vector<int>> grid(64, vector<int>(64));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            grid[i][j] = 0;
        }
    }
    print_matrix(grid);
    std::string delimiter = " -> ";
    vector<Line> lines;
    ifstream file("./data/input_aoc5.txt");
    string line;
    while (getline(file, line)) {
        string first = line.substr(0, line.find(delimiter));
        string second = line.substr(line.find(delimiter) + delimiter.length());
        Point firstPoint(stoi(first.substr(0, first.find(","))), stoi(first.substr(first.find(",") + 1)));
        Point secondPoint(stoi(second.substr(0, second.find(","))), stoi(second.substr(second.find(",") + 1)));
        //if (firstPoint.x == secondPoint.x || firstPoint.y == secondPoint.y) {
            lines.push_back(Line(firstPoint, secondPoint));
        //}
    }
    file.close();
    cout << "Number of lines: " << lines.size() << endl;
    vector<Point> overlappingPoints;
    // Part 1
    for (auto line0 : lines) {
        for (auto line1 : lines) {
            //TODO Sleep
        }
    }
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    print_matrix(grid);
}