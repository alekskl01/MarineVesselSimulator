#pragma once

#include <string>
#include <stdexcept>

enum class HullShape {
    Rectangle,
    TriangularBow
    // Add more shapes as needed
};

inline std::string get_hull_shape_path(HullShape shape) {
    switch (shape) {
        case HullShape::Rectangle:     return "../data/hull_shapes/rectangle.txt";
        case HullShape::TriangularBow: return "../data/hull_shapes/triangular_bow.txt";

        default: throw std::invalid_argument("Unknown HullShape enum value");
    }
}
