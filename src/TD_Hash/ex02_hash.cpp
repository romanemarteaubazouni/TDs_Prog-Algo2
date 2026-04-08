#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <istream>
#include <fstream>
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
Position operator+(Position & p, Direction const& d) {
    if (d == Direction::Up) {
        p.y -= 1;
    }
    if (d == Direction::Down) {
        p.y += 1;
    }
    if (d == Direction::Right) {
        p.x += 1;
    }
    if (d == Direction::Left) {
        p.x -= 1;
    }
    return p;
}
Position operator+=(Position & p, Direction const& d) {
    if (d == Direction::Up) {
        p.y -= 1;
    }
    if (d == Direction::Down) {
        p.y += 1;
    }
    if (d == Direction::Right) {
        p.x += 1;
    }
    if (d == Direction::Left) {
        p.x -= 1;
    }
    return p;
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
    int width;
    int height;
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
                map.pos_init = {i, nb_line};
                map.dir_init = Direction::Up;
            }
            else if (line[i] == '<') {
                map.pos_init = {i, nb_line};
                map.dir_init = Direction::Left;
            }
            else if (line[i] == '>') {
                map.pos_init = {i, nb_line};
                map.dir_init = Direction::Right;
            }
            else if (line[i] == 'v') {
                map.pos_init = {i, nb_line};
                map.dir_init = Direction::Down;
            }
        }
        nb_line++;
        map.width = line.size();
    }
    map.height = nb_line;
    return map;
}

// Question 3.1
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

struct WalkResult {
    Position final_position;
    size_t steps_taken;
    std::unordered_set<Position> visited_positions;
};
// Question 3.2
WalkResult guard_walk(Map const& map) {
    Position current_pos {map.pos_init};
    Direction current_dir {map.dir_init};
    WalkResult movement {};
    // On ajoute la positon intiale au set
    movement.visited_positions.insert(current_pos);
    // Tant qu'on ne sort pas de la carte
    while (current_pos.x >= 0 && current_pos.x < map.width
            && current_pos.y >= 0 && current_pos.y < map.height) {
        // On copie la position actuelle
        Position next_position = current_pos;
        // On avance suivant la direction actuelle
        next_position += current_dir;
        // On vérifie si on ne sort pas du cadre avec ce mouvement
        if (next_position.x < 0 || next_position.x >= map.width
            || next_position.y < 0 || next_position.y >= map.height) {
            break;
        }
        // On vérifier si on n'est pas sur un obstacle en faisant ce déplacement
        auto iter = std::find(map.obstacles.begin(), map.obstacles.end(), next_position);
        if (iter != map.obstacles.end()) {
            // Si on a trouvé un obstacle, on tourne à droite
            turn_right(current_dir);
        }
        else {
            // On avance
            current_pos = next_position;
            movement.visited_positions.insert(current_pos);
            movement.steps_taken++;
        }
    }
    movement.final_position = current_pos;
    return movement;
}

int main() {
    std::ifstream file("C:/Users/roman/Desktop/Mes dossiers/IMAC/Prog et Algo/TDs_Prog-Algo2/src/TD_Hash/first_patrol.txt");
    Map input_structure = read_input(file);
    WalkResult walk = guard_walk(input_structure);
    
    std::cout << "Le garde a parcouru " << walk.steps_taken << " cases.\n";
    std::cout << "Il a fini sur la case " << walk.final_position << std::endl;
    return 0;
}