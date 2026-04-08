#include <iostream>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    // Question 2/3
    int hash() {
        // Valeurs des couleurs (pas de 13 car 13 cartes dans une couleur)
        int hash_kind {static_cast<int>(kind) * 13};
        // Valeurs des cartes (allant de 1 à 13)
        int hash_value {static_cast<int>(value) + 1};

        return (hash_kind + hash_value);
    }
};

// Question 1
bool operator==(Card const& a, Card const& b) {
    return a.value == b.value && a.kind == b.kind;
}