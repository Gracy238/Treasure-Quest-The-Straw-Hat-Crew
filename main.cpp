#include "straw_hat.hpp"
#include <iostream>

int main() {
    // Example usage of StrawHatTreasury
    StrawHatTreasury treasury(3); // 3 crewmates

    // Adding treasures
    std::vector<Treasure> treasures = {
        Treasure(1, 10, 5),
        Treasure(2, 20, 10),
        Treasure(3, 15, 15),
        Treasure(4, 5, 20),
        Treasure(5, 30, 25)
    };

    std::cout << "Adding Treasures:" << std::endl;
    for (const auto& t : treasures) {
        treasury.add_treasure(t);
        std::cout << "Added Treasure ID: " << t.id << ", Size: " << t.size
                  << ", Arrival Time: " << t.arrival_time << std::endl;
    }

    // Getting completion times
    std::vector<Treasure> completion_times = treasury.get_completion_time();
    std::cout << "\nTreasure Completion Times:" << std::endl;
    for (const auto& t : completion_times) {
        std::cout << "Treasure ID: " << t.id << ", Completion Time: " << t.completion_time << std::endl;
    }

    return 0;
}