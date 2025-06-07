#pragma once

#include <memory>
#include <string>

namespace troy {

    struct artifact {
        // constructors needed (until C++20)
        artifact(std::string name) : name(name) {}
        std::string name;
    };

    struct power {
        // constructors needed (until C++20)
        power(std::string effect) : effect(effect) {}
        std::string effect;
    };

    struct human
    {
        artifact *possession;
        human(artifact art)
        {
            possession->std::make_unique<artifact>(art);
        }
    };

}  // namespace troy
