#pragma once

#include <vector>
#include <memory>

#include "geometry.hpp"
#include "hull_shape.hpp"

struct KinematicState {
    double x, y, heading; // Position and orientation
    double vx, vy, vheading; // Linear and angular velocity
    double ax, ay, aheading; // Linear and angular acceleration
};

struct VesselSpec {
    float x, y, heading;
    float vx, vy, vheading;
    HullShape shape;
};

class Vessel {
public:
    Vessel(KinematicState state, std::vector<Point> extent);

    void update(double dt);

    KinematicState get_kinematic_state() const;
    std::vector<Point> get_extent_polygon() const;

protected:
    KinematicState kinematic_state_;
    const std::vector<Point> extent_;
};

std::unique_ptr<Vessel> create_vessel_from_spec(const VesselSpec& spec);