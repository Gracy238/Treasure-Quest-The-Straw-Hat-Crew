#ifndef CREWMATE_HPP
#define CREWMATE_HPP

#include "treasure.hpp"
#include "heap.hpp"
#include <vector>

class CrewMate {
private:
    int current_load;
    int last_update;
    Heap<Treasure> treasure_jo_abhi_mere_pass_hai;
    std::vector<Treasure> treasure_jo_proccess_ho_chuke;

public:
    CrewMate()
        : current_load(0), last_update(0),
          treasure_jo_abhi_mere_pass_hai(
              [this](const Treasure& a, const Treasure& b) {
                  return compare(a, b);
              }, std::vector<Treasure>()) {}

    bool compare(const Treasure& a, const Treasure& b) const {
        int a_w = last_update - a.arrival_time;
        int b_w = last_update - b.arrival_time;
        int a_priority = a_w - a.size;
        int b_priority = b_w - b.size;
        if (a_priority == b_priority) {
            return a.id < b.id;
        }
        return a_priority > b_priority;
    }

    void add_treasure_to_crew_mate(const Treasure& treasure_to_insert) {
        int in_time = treasure_to_insert.arrival_time;
        int time_diff = in_time - last_update;

        while (time_diff > 0 && !treasure_jo_abhi_mere_pass_hai.empty()) {
            Treasure& top_treasure = treasure_jo_abhi_mere_pass_hai.top();
            if (top_treasure.size > time_diff) {
                top_treasure.size -= time_diff;
                time_diff = 0;
            } else {
                Treasure treasure_processed = treasure_jo_abhi_mere_pass_hai.extract();
                treasure_processed.completion_time = last_update + treasure_processed.size;
                last_update += treasure_processed.size;
                treasure_jo_proccess_ho_chuke.push_back(treasure_processed);
                time_diff -= treasure_processed.size;
            }
        }

        last_update = in_time;
        treasure_jo_abhi_mere_pass_hai.insert(treasure_to_insert);
        if (current_load > treasure_to_insert.arrival_time) {
            current_load += treasure_to_insert.size;
        } else {
            current_load = treasure_to_insert.size + treasure_to_insert.arrival_time;
        }
    }

    std::vector<Treasure> get_treasures_completion_time() const {
        int store_last_update_time = last_update;
        std::vector<Treasure> temp;
        Heap<Treasure> temp_heap(
            [this](const Treasure& a, const Treasure& b) { return compare(a, b); },
            treasure_jo_abhi_mere_pass_hai.get_arr());

        while (!temp_heap.empty()) {
            Treasure t = temp_heap.extract();
            t.completion_time = store_last_update_time + t.size;
            store_last_update_time = t.completion_time;
            temp.push_back(t);
        }

        std::vector<Treasure> helper = temp;
        helper.insert(helper.end(), treasure_jo_proccess_ho_chuke.begin(), treasure_jo_proccess_ho_chuke.end());

        std::sort(helper.begin(), helper.end(), [](const Treasure& a, const Treasure& b) {
            return a.id < b.id;
        });

        return helper;
    }

    int get_current_load() const { return current_load; }
};

#endif