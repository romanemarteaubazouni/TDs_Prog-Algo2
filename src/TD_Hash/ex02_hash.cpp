#include <iostream>
#include <vector>
#include <map>
// Question 1.1
enum class Direction {
    Up,
    Right,
    Down,
    Left
};
// Question 1.2
struct Position {
    int x;
    int y;
};
// Question 1.3
bool operator==(Position const& a, Position const& b) {
    return a.x == b.x && a.y == b.y;
}
// Question 1.4
std::ostream& operator<<(std::ostream& os, Position const& p) {
    return os << '(' << p.x << ", " << p.y << ')';
}
// Question 1.5
Position operator+=(Position const& a, Position const& b) {
    Position c {(a.x + b.x, a.y + b.y)};
    return c;
}
// Question 1.6
Position operator+(Position const& p, Direction const& d) {
    if (d == Direction::Up) {
        return {(p.x, p.y - 1)};
    }
    if (d == Direction::Down) {
        return {(p.x, p.y + 1)};
    }
    if (d == Direction::Right) {
        return {(p.x + 1, p.y)};
    }
    if (d == Direction::Left) {
        return {(p.x - 1, p.y)};
    }
}
Position operator+=(Position const& p, Direction const& d) {
    if (d == Direction::Up) {
        return {(p.x, p.y - 1)};
    }
    if (d == Direction::Down) {
        return {(p.x, p.y + 1)};
    }
    if (d == Direction::Right) {
        return {(p.x + 1, p.y)};
    }
    if (d == Direction::Left) {
        return {(p.x - 1, p.y)};
    }
}
// Question 1.7
Direction turn_right(Direction const& d) {
    if (d == Direction::Up) {
        return Direction::Right;
    }
    if (d == Direction::Down) {
        return Direction::Left;
    }
    if (d == Direction::Right) {
        return Direction::Down;
    }
    if (d == Direction::Left) {
        return Direction::Up;
    }
}
// Avec une map, même si outil lourd pour cette énumération :
// #include <unordered_map>
// Direction turn_right(Direction const& d) {
//     static const std::unordered_map<Direction, Direction> direction = {
//         {Direction::Up, Direction::Right},
//         {Direction::Right, Direction::Down},
//         {Direction::Down, Direction::Left},
//         {Direction::Left, Direction::Up}
//     };
//     auto new_d = direction.find(d);
//     return new_d->second;
// }

// Question 2
struct Map {
    Position pos_init;
    Direction dir_init;
    std::vector<Position> obstacles;
};

Map read_input (std::istream& input_stream) {
    Map map {};
    int nb_line {};
    for (std::string line{}; std::getline(input_stream, line, '\n') and line != "";) {
        for (int i {}; i < line.size(); i++) {
            if (line[i] == '#') {
                map.obstacles.push_back({nb_line, i});
            }
            else if (line[i] == '^') {
                map.pos_init = {nb_line, i};
                map.dir_init = Direction::Up;
            }
            else if (line[i] == '<') {
                map.pos_init = {nb_line, i};
                map.dir_init = Direction::Left;
            }
            else if (line[i] == '>') {
                map.pos_init = {nb_line, i};
                map.dir_init = Direction::Right;
            }
            else if (line[i] == 'v') {
                map.pos_init = {nb_line, i};
                map.dir_init = Direction::Down;
            }
        }
        nb_line++;
    }
    return map;
}

// Question 3
namespace std {
    template <>
    struct hash<Position> {
        std::size_t operator()(const Position& pos) const {
            // On cherhce à combiner les hash de chaque coordonnée
            size_t hash_x = std::hash<int>()(pos.x);
            size_t hash_y = std::hash<int>()(pos.y);
            // Opération XOR (eXclusive OR) + multiplication par nombre premier de hash_y
            // Le hash sera unique et différent pour (10, 20) et (20, 10) par exemple
            return hash_x ^ (hash_y * 3);
        }
    };
}

int main() {
    return 0;
}