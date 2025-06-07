#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace protein_translation {
    extern const std::unordered_map<std::string, std::string> codon_table;

    std::vector<std::string> proteins(std::string protein);
}  // namespace protein_translation
