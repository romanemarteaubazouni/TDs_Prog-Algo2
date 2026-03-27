# S2 | Prog&Algo: TD03 Algorithmes de tri

## TD03 Algorithmes de tri

**Romane MARTEAU--BAZOUNI**

# Exercice 3 (Comparaison des algorithmes)

*RMQ : On aurait pu créer des fichiers .hpp pour stocker les fonctions de tri rapide ou par sélection pour éviter de les recopier dans cet exercice. Cela ne me semblait cependant pas essentiel pour ce TD.*

## Que constatez-vous ? Que pouvez-vous en dire ?
Grâce au fichier ScoperTimer.hpp, on a initialisé trois différents timers pour la fonction de tri par sélection, tri rapide et tri `std::sort` de la bibliothèque standard.

Exemple :

```cpp
int main() {
    ScopedTimer timer{"Tri par sélection"};
    std::vector<int> array {generate_random_vector(500, 100)};
    selection_sort(array);
}
```
Les résultats sont les suivants (pour un tableau de 500 élements, générés aléatoirement entre 0 et 100) :

| Tri par sélection     | Tri rapide | Tri standard  |
| :-------------------: |:----------:|:-------------:|
|  **0.4726ms**   |   **0.075ms**   |   **0.1164ms**  |

Si on augmente le nombre d'élements dans le tableau (1000), on constate des grands écarts dans les timers :

| Tri par sélection     | Tri rapide | Tri standard  |
| :-------------------: |:----------:|:-------------:|
|  **1.4416ms**   |   **0.2848ms**   |   **0.2612ms**  |

C'est encore plus marquant pour 10 000 élements :

| Tri par sélection     | Tri rapide | Tri standard  |
| :-------------------: |:----------:|:-------------:|
|  **159.082ms**   |   **3.993ms**   |   **2.6534ms**  |

Même si nous parlons ici de millisecondes, on peut dire que :
- le tri rapide (par récursivité) est bien rapide et est assez optimisé pour de grands tableaux ;
- le tri par sélection est bien plus long puisqu'il doit parcourir répétitivement le tableau de 500 élements ou plus. Il est inutilisable pour des tableaux trop grands. C'est là qu'on constate vraiement sa complexité en O(n²) et qu'on comprend qu'une complexité en O(nlog(n)) est plus rapide ;
- Après quelques recherches, j'ai trouvé que le tri `std::sort` de la bibliothèque standard a une complexité en O(nlog(n)) et démarre par un tri rapide puis utilise plusieurs autres algorithmes de tri par la suite. Vu les résultats des timers, c'est la méthode optimale pour de grands tableaux.

Le tri par sélection est inutile pour des grands tableaux mais le tri rapide et le tri `std::sort` se valent (avec un léger avantage pour le tri standard), car leurs complexités sont équivalentes.

# Exercice 4 (dichotomie)

Résultats de compilation :

*Rmq : mon code compte les indices à partir de 1, et non 0 puisque que nous y sommes plus habitués.*

- [1, 2, 2, 3, 4, 8, 12] : 8 est à l'indice 6

- [1, 2, 3, 3, 6, 14, 12, 15] : Le tableau n'est pas trié

- [2, 2, 3, 4, 5, 8, 12, 15, 16] : 16 est à l'indice 9

- [5, 6, 7, 8, 9, 10, 11, 12, 13] : 6 est à l'indice 2

- [1, 2, 3, 4, 5, 6, 7, 8, 9] : 10 est à l'indice -1 (non trouvé)