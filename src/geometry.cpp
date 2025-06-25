#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "geometry.hpp"


bool overlaps(const std::vector<Point>& poly1, const std::vector<Point>& poly2) {
    // TODO: Implement algorithm to check if two polygons overlap
    return false;
}

std::vector<Point> read_polygon_from_file(const std::string& filename) {
    std::vector<Point> polygon;
    std::ifstream file(filename);
    
    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double x, y;
        if (iss >> x >> y) {
            polygon.push_back({x, y});
        } else {
            std::cerr << "Warning: Skipping malformed line: " << line << std::endl;
        }
    }

    return polygon;
}
