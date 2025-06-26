#include <cmath>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <memory>

#include "vessel.hpp"
#include "hull_shape.hpp"


// ==== Vessel Class ====

Vessel::Vessel(KinematicState state, std::vector<Point> extent): kinematic_state_(state), extent_(extent) {
    if (extent.empty()) {
        throw std::invalid_argument("Extent polygon cannot be empty");
    }
}

void Vessel::update(double dt) {
    kinematic_state_.x += kinematic_state_.vx * dt;
    kinematic_state_.y += kinematic_state_.vy * dt;
    kinematic_state_.heading += kinematic_state_.vheading * dt;

    kinematic_state_.vx += kinematic_state_.ax * dt;
    kinematic_state_.vy += kinematic_state_.ay * dt;
    kinematic_state_.vheading += kinematic_state_.aheading * dt;
}

KinematicState Vessel::get_kinematic_state() const {
    return kinematic_state_;
}

std::vector<Point> Vessel::get_extent_polygon() const {
    return extent_;
}

// =======================


std::unique_ptr<Vessel> create_vessel_from_spec(const VesselSpec& spec) {
    std::vector<Point> extent;
    try {
        extent = read_polygon_from_file(get_hull_shape_path(spec.shape));
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to create vessel from spec: " + std::string(e.what()));
    }

    KinematicState kinematic = {
        spec.x, spec.y, spec.heading,
        spec.vx, spec.vy, spec.vheading,
        0.0, 0.0, 0.0
    };

    return std::make_unique<Vessel>(kinematic, extent);
}


