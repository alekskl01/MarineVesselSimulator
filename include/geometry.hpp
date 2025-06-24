#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct Point {
    double x, y;
};

inline bool operator==(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}

bool overlap(const std::vector<Point>& poly1, const std::vector<Point>& poly2);

std::vector<Point> read_polygon_from_file(const std::string& filename);