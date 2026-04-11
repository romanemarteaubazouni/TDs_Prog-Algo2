#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>

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
    int hash() const {
        // Valeurs des couleurs (13 cartes dans une couleur)
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
        size_t operator()(Card const& card) const {
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

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
    name += '0' + std::to_string(card_value);
    }else if (card_value == 10) {
    name += "10";
    }else if (card_value == 11) {
    name += 'J';
    }else if (card_value == 12) {
    name += 'Q';
    }else if (card_value == 13) {
    name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
    name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
    name += "Diamond";
    }else if (card.kind == CardKind::Club) {
    name += "Club";
    }else if (card.kind == CardKind::Spade) {
    name += "Spade";
    }
    return name;
}
// Question 4
int main() {
    std::vector<Card> random_cards {get_cards(100)};
    std::unordered_map<Card, int> cards {};
    for (Card const& card : random_cards) {
        cards[card]++;
    }
    for (auto const& pair : cards) {
        std::cout << "La carte " << card_name(pair.first) << " apparait " << pair.second << " fois.\n";
    }
    return 0;
}