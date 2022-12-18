#ifndef RANDOMSET_H
#define RANDOMSET_H

#include <vector>
#include <iostream>

class RandomSet : public std::vector<int>
{
public:
    RandomSet();

    bool contains(int);
}; // class RandomSet


std::ostream& operator<<(std::ostream&, const RandomSet&);

#endif // RANDOMSET_H
