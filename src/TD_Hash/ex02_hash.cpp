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
// Comment fonctionner avec une map ?
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
struct Input_Map {
    std::map<Position, char> map;
    Position pos_init;
    Direction dir_init;
};

Input_Map read_input (std::istream& input_stream) {
    
}

int main() {
    return 0;
}