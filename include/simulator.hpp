#pragma once

#include <vector>
#include <memory>

#include "vessel.hpp"

class Simulator {
public:
    explicit Simulator(double timestep_seconds = 0.1): timestep_seconds_(timestep_seconds) {};

    void run();
    void add_vessel(std::unique_ptr<Vessel> vessel) {
        vessels_.emplace_back(std::move(vessel));
    }
private:
    std::vector<std::unique_ptr<Vessel>> vessels_;
    double timestep_seconds_ = 0.1;

    void update();
    void render();
};
