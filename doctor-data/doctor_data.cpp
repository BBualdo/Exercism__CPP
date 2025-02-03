#include "doctor_data.h"

using namespace heaven;

Vessel::Vessel(string name, int generation)
{
    this->name = name;
    this->generation = generation;
}

Vessel::Vessel(string name, int generation, star_map::System system)
{
    this->name = name;
    this->generation = generation;
    this->current_system = system;
}

Vessel Vessel::replicate(const string name)
{
    return Vessel(name, this->generation + 1, this->current_system);
}

void Vessel::make_buster()
{
    this->busters++;
}

bool Vessel::shoot_buster()
{
    if (this->busters > 0)
    {
        busters--;
        return true;
    }
    return false;
}

string heaven::get_older_bob(const Vessel& vessel1, const Vessel& vessel2)
{
    return vessel1.generation < vessel2.generation ? vessel1.name : vessel2.name;
}

bool heaven::in_the_same_system(const Vessel& vessel1, const Vessel& vessel2)
{
    return vessel1.current_system == vessel2.current_system;
}
