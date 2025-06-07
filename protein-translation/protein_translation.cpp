#include "protein_translation.h"

namespace protein_translation {
    const std::unordered_map<std::string, std::string> codon_table {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"},
        {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
        {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}
    };

    std::vector<std::string> proteins(std::string protein) {

        std::vector<std::string> protein_vector{};

        // stores currently processing substring
        std::string current_codon{};

        for (int i = 0; i <= static_cast<int>(protein.length()); i += 3) {
            // extracting 3 letters = 1 codon
            current_codon = protein.substr(i, 3);

            // search for matching codon in codon_table
            for (const auto& [codon, protein] : codon_table) {
                if (current_codon == codon) {
                    // if current codon equals STOP, then exit function and return current proteins
                    if (protein == "STOP")
                        return protein_vector;

                    protein_vector.push_back(protein);
                }
            }
        }

        return protein_vector;
    }

}  // namespace protein_translation
