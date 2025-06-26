
#include <iostream>
#include <vector>
#include <string>

#include "vessel.hpp"
#include "simulator.hpp"
#include "hull_shape.hpp"


int main() {
    const std::vector<VesselSpec> specs = {
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
    };

    Simulator simulator(0.05);
    for (const auto& spec : specs) {
        try {
            simulator.add_vessel(create_vessel_from_spec(spec));
        } catch (const std::exception& e) {
            std::cerr << "[Error creating vessel]: " << e.what() << std::endl;
        }
    }

    std::cout << "Welcome to the Vessel Simulator!" << std::endl;

    simulator.run();
}