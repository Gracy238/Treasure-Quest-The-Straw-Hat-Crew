#ifndef STRAW_HAT_HPP
#define STRAW_HAT_HPP

#include "crewmate.hpp"
#include "heap.hpp"
#include <vector>
#include <stdexcept>

// Comparison function for CrewMate heap
bool crewmate_compare(const CrewMate &a, const CrewMate &b)
{
    return a.get_current_load() < b.get_current_load();
}

class StrawHatTreasury
{
private:
    Heap<CrewMate> mates;
    int t_count;
    int m_count;
    std::vector<Treasure> temp_t;

public:
    StrawHatTreasury(int m)
        : mates(crewmate_compare, std::vector<CrewMate>(m, CrewMate())),
          t_count(0), m_count(m)
    {
        if (m <= 0)
        {
            throw std::invalid_argument("Number of crewmates must be positive");
        }
    }

    void add_treasure(const Treasure &treasure)
    {
        if (mates.empty())
        {
            throw std::runtime_error("No crewmates available to assign treasure");
        }
        CrewMate crew_mate_with_least_load = mates.extract();
        t_count++;
        temp_t.push_back(treasure);
        crew_mate_with_least_load.add_treasure_to_crew_mate(treasure);
        mates.insert(crew_mate_with_least_load);
    }

    std::vector<Treasure> get_completion_time()
    {
        std::vector<Treasure> ans;
        if (t_count <= m_count)
        {
            for (const Treasure &t : temp_t)
            {
                Treasure t_copy = t;
                t_copy.completion_time = t.size + t.arrival_time;
                ans.push_back(t_copy);
            }
        }
        else
        {
            for (const CrewMate &crewmate : mates.get_arr())
            {
                std::vector<Treasure> treasures = crewmate.get_treasures_completion_time();
                ans.insert(ans.end(), treasures.begin(), treasures.end());
            }
        }
        std::sort(ans.begin(), ans.end(), [](const Treasure &a, const Treasure &b)
                  { return a.id < b.id; });
        return ans;
    }
};

#endif