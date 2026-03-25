#include <iostream>
#include <vector>
#include <algorithm>

int search(std::vector<int> &vec, int elem) {
    int left {0};
    int right {static_cast<int>(vec.size() - 1)};

    while (left <= right) {
        int middle {(left + right) / 2};
        if (vec[middle] == elem)
        {
            return middle + 1; // +1 car les indices commencent à 0 pour l'ordinateur, mais est plus parlant en parant de 1 pour l'humain
        }
        // Si l'élement est grand, on se place à droite
        else if (vec[middle] < elem) {
            left = middle + 1;
        }
        // Si l'élement est grand, on se place à gauche
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

    std::cout << "Voici élement est à la " << search(array, elem) << "eme place du tableau.\n";
        return 0;
}