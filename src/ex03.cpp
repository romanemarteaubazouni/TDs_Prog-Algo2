/*Les réponses au questions sont dans le README*/

#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void selection_sort(std::vector<int> & vec) {
    int minimum {};
    int place_in_vec {};
    for (size_t i{}; i < vec.size(); i++)
    {
        minimum = vec[i];
        place_in_vec = i;
        for (size_t j{i + 1}; j < vec.size(); j++)
        {
            if (vec[j] < minimum)
            {
                minimum = vec[j];
                place_in_vec = j;
            }
        }
        std::swap(vec[i], vec[place_in_vec]);
    }
}

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right) {
    // Le principe du code est expliqué dans le cours
    int pivot {vec[right]};
    size_t current {left};

    // On trouve les élements plus petits que notre pivot
    for (size_t i{left}; i < right; i++) {
        if (vec[i] <= pivot) {
            std::swap(vec[i], vec[current]);
            current++;
        }
    }
    std::swap(vec[right], vec[current]); // On place le pivot au milieu du tableau
    return current;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    // Condition d'arrêt de la récursivité
    if (left >= right) {
        return;
    }
    // On trouve l'indice de la partition
    size_t place_of_pivot {quick_sort_partition(vec, left, right)};

    // On trie récursivement le tableau de gauche
    if (place_of_pivot != 0) {
        quick_sort(vec, left, place_of_pivot - 1);
    }

    quick_sort(vec, place_of_pivot + 1, right); // On trie récursivement le tableau de droite
}

void quick_sort(std::vector<int> & vec) {
    // Condition d'arrêt de la récursivité
    if (vec.size() == 0) {
        return;
    }
    quick_sort(vec, 0, vec.size() - 1);
}

int main () {
    ScopedTimer timer{"Tri de la bibliotheque standard"};
    std::vector<int> array {generate_random_vector(10000, 100)};
    std::sort(array.begin(), array.end());

    // ScopedTimer timer{"Tri par sélection"};
    // std::vector<int> array {generate_random_vector(10000, 100)};
    // selection_sort(array);

    // ScopedTimer timer{"Tri rapide"};
    // std::vector<int> array {generate_random_vector(10000, 100)};
    // quick_sort(array);

    return 0;
}