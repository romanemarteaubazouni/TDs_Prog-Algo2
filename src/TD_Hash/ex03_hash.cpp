#include <iostream>
#include <vector>

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

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}