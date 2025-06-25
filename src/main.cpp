
#include <iostream>
#include <array>
#include <vector>
#include <string>

#include "vessel.hpp"
#include "simulator.hpp"
#include "hull_shape.hpp"


int main() {
    constexpr int num_vessels = 2;

    constexpr std::array<VesselSpec, num_vessels> specs = {{
    {
        .x = 0.0,
        .y = 0.0,
        .heading = 0.0,
        .vx = 2.0,
        .vy = 0.0,
        .vheading = 0.2,
        .shape = HullShape::Rectangle
    },
    {
        .x = 5.0,
        .y = 2.0,
        .heading = 1.0,
        .vx = 0.5,
        .vy = 1.0,
        .vheading = -0.1,
        .shape = HullShape::TriangularBow
    }
    }};

    std::vector<Vessel> vessels;
    for (const auto& spec : specs) {
        try {
            vessels.push_back(create_vessel_from_spec(spec));
        } catch (const std::exception& e) {
            std::cerr << "[Error creating vessel]: " << e.what() << std::endl;
        }
    }

    Simulator simulator(0.05);
    for (auto& v : vessels) {
        simulator.add_vessel(v); 
    }

    std::cout << "Welcome to the Vessel Simulator!" << std::endl;

    simulator.run();
}