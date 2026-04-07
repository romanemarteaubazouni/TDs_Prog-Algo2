#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

int search(std::vector<int> &vec, int elem) {
    // Bornes du tableau où la recherche s'effectue
    int left {0};
    int right {static_cast<int>(vec.size() - 1)};

    while (left <= right) {
        int middle {(left + right) / 2};
        if (vec[middle] == elem)
        {
            return middle + 1; // Les indices commencent à 0 pour l'ordinateur, mais sont plus parlant en partant de 1 pour l'homme
        }
        // Si l'élement est grand, on se place à droite du milieu
        else if (vec[middle] < elem) {
            left = middle + 1;
        }
        // Si l'élement est petit, on se place à gauche du milieu
        else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> array {};
    int size {};
    int numbers {};
    int elem {};
    std::cout << "Combien d'entiers voulez-vous entrer ? ";
    std::cin >> size;
    std::cout << "Entrez " << size << " entiers :\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers;
        array.push_back(numbers);
    }

    std::cout << "Quel chiffre cherchez-vous ? ";
    std::cin >> elem;

    if (!is_sorted(array)) {
        std::cout << "Votre tableau n'est pas trié.\n";
    }

    else if (search(array, elem) == -1) {
        std::cout << "Votre élement n'est pas dans le tableau (indice " << search(array, elem) << ").\n";
    }
    else {
    std::cout << "Votre élement est à la " << search(array, elem) << "eme place du tableau.\n";
    }
    return 0;
}