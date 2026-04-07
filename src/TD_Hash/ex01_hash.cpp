#include <iostream>
#include <vector>

size_t folding_string_hash(std::string const& s, size_t max) {
    size_t hash {0};
    for (char const& c : s) {
        hash += c;
        // On fait le modulo sur le hash
        // On veut faire, à chaque itération, hash = (hash + c) % max
        hash %= max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash {0};
    for (size_t i {0}; i < s.size(); i++) {
        hash += s[i]*(i + 1);
        hash %= max;
    }
    return hash;
}

size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m) {
    size_t hash {0};
    size_t power {1};
    for (size_t i {0}; i < s.size(); i++) {
        hash += s[i]*power;
        hash %= m;
        power *= p;
    }
    return hash;
}

int main() {
    std::string str {};
    std::cout << "Entrez une string : " << std::endl;
    std::cin >> str;

    size_t sum {folding_string_ordered_hash(str, 100)};
    std::cout << "La somme vaut " << sum << std::endl;
    return 0;
}