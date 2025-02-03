#pragma once
#include <string>

using namespace std;

namespace star_map
{
    enum class System
    {
        BetaHydri,
        EpsilonEridani,
        Sol,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
} // namespace star_map

namespace heaven
{
    class Vessel
    {
    public:
        star_map::System current_system = star_map::System::Sol;
        string name;
        int generation;
        int busters = 0;

        Vessel(string name, int generation);
        Vessel(string name, int generation, star_map::System system);

        Vessel replicate(string name);

        void make_buster();

        bool shoot_buster();
    };

    string get_older_bob(const heaven::Vessel& vessel1, const heaven::Vessel& vessel2);

    bool in_the_same_system(const heaven::Vessel& vessel1, const heaven::Vessel& vessel2);
} // namespace heaven