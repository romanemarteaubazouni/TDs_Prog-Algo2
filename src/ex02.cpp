#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right) {
    // Il faut swap jusqu'à ce que le pivot soit à sa place
    // Comment ?
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    // On trouve l'indice de la partition
    size_t place_of_pivot {quick_sort_partition(vec, left, right)};

    // On trie récursivement le tableau de gauche
    if (place_of_pivot > 0) {
        quick_sort(vec, left, place_of_pivot - 1);
    }

    quick_sort(vec, place_of_pivot + 1, right); // On trie récursivement le tableau de droite
}

void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

int main() {
    std::vector<int> array {};
    int size {};
    int numbers {};
    std::cout << "Combien d'entiers voulez-vous entrer ? ";
    std::cin >> size;
    std::cout << "Entrez " << size << " entiers :\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers;
        array.push_back(numbers);
    }

    if (is_sorted(array)) {
        std::cout << "Le tableau est déjà trié\n";
    }
    else {
        quick_sort(array);
        std::cout << "Voici le tableau trié : ";
        for (int nb : array) {
            std::cout << nb << " ";
        }
        std::cout << '\n';
    }

    return 0;
}