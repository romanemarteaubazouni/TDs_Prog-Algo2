#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

void counting_sort(std::vector<int> & vec, int const max) {
    // On remplit notre vector avec des 0
    // Remarque : std::array<int, max> ne marche pas ici car max est un argument de la fonction, inconnue
    std::vector<int> array_of_occurences(max + 1, 0); // Equivalent Python de [0] * (max + 1), indisponible en C++

    // Compte des occurences
    for(size_t i {}; i < vec.size(); i++)
    {
        int current_number {vec[i]};
        array_of_occurences[current_number]++;
    }
    // On vide le tableau pour le re-remplir, trié
    vec.clear();

    for (size_t j {}; j < array_of_occurences.size(); j++)
    {
        for (int k {}; k < array_of_occurences[j]; k++)
        {
            vec.push_back(j);
        }
    }
}

int main() {
    std::vector<int> array {};
    int size {};
    int numbers {};
    int max {};
    std::cout << "Combien d'entiers voulez-vous entrer ? ";
    std::cin >> size;
    std::cout << "Entrez " << size << " entiers :\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers;
        array.push_back(numbers);
    }

    std::cout << "Quelle est la valeur maximale du tableau ? ";
    std::cin >> max;

    if (is_sorted(array)) {
        std::cout << "Le tableau est déjà trié\n";
    }
    else {
        counting_sort(array, max);
        std::cout << "Voici le tableau trié : ";
        for (int nb : array) {
            std::cout << nb << " ";
        }
        std::cout << '\n';
    }

    return 0;
}