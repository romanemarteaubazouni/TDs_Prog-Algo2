#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

void selection_sort(std::vector<int> & vec) {
    // Initialisation des variables contenant le minimum actuel de chaque tour
    int minimum {};
    int place_in_vec {};

    for (size_t i{}; i < vec.size(); i++)
    {
        minimum = vec[i];
        place_in_vec = i;
        for (size_t j{i + 1}; j < vec.size(); j++)
        {
            // Comparaison au minimum actuel
            if (vec[j] < minimum) {
                minimum = vec[j];
                place_in_vec = j;
            }
        }
        // Le minimum est placé
        std::swap(vec[i], vec[place_in_vec]);
    }
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
        selection_sort(array);
        std::cout << "Voici le tableau trié : ";
        for (int nb : array) {
            std::cout << nb << " ";
        }
        std::cout << '\n';
    }

    return 0;
}