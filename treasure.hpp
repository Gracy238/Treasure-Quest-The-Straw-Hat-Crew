#ifndef TREASURE_HPP
#define TREASURE_HPP

class Treasure {
public:
    int id;
    int size;
    int arrival_time;
    int completion_time;

    Treasure(int id_, int size_, int arrival_time_)
        : id(id_), size(size_), arrival_time(arrival_time_), completion_time(-1) {}
};

#endif