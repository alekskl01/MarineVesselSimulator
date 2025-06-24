#include <iostream>
#include <thread>
#include <chrono>

#include "vessel.hpp"
#include "simulator.hpp"


void Simulator::run() {
    using namespace std::chrono;
    std::chrono::duration<double> target_frame_time(timestep_seconds_);
    while (true) {
        auto start = steady_clock::now();

        update();
        render();

        // Ensures a maximum framerate is maintained
        auto elapsed = duration_cast<milliseconds>(steady_clock::now() - start);
        if (elapsed < target_frame_time)
            std::this_thread::sleep_for(target_frame_time - elapsed);
        else
            std::cerr << "[Simulator] Frame took " << elapsed.count() << " ms (over budget).\n";
    }
}

void Simulator::update() {
    for (const auto& vessel : vessels_) {
        vessel->update(timestep_seconds_);
    }
}

void Simulator::render() {
    // TODO: Implement rendering
    std::cout << "[Simulator] Rendering not implemented.\n";
}