#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right) {
    // Cet algorithme se base sur le principe du tri rapide, dont chaque étape est détaillée dans le cours

    // Initialisation de notre pivôt (ici, le dernier du tableau)
    int pivot {vec[right]};
    // Initialisation de notre variable de position : elle stocke la place actuelle que devra prendre le pivot
    size_t current {left};

    // Les élements plus petits que le pivot sont placés à sa gauche
    for (size_t i{left}; i < right; i++) {
        if (vec[i] <= pivot) {
            std::swap(vec[i], vec[current]);
            // Avancé de la place finale du pivot
            current++;
        }
    }
    std::swap(vec[right], vec[current]);
    return current;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    // Condition d'arrêt de la récursivité : si le tableau a une taille nulle
    if (left >= right) {
        return;
    }
    // On trouve l'indice de la partition
    size_t place_of_pivot {quick_sort_partition(vec, left, right)};

    // Tri récursif du tableau à gauche du pivot
    if (place_of_pivot != 0) { // Condition pour faire l'opération "place_of_pivot - 1"
        quick_sort(vec, left, place_of_pivot - 1);
    }

    // Tri récursif du tableau à droite du pivot
    quick_sort(vec, place_of_pivot + 1, right);
}

void quick_sort(std::vector<int> & vec) {
    // Condition d'arrêt de la récursivité
    if (vec.size() == 0) {
        return;
    }
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