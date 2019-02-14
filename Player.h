//
// Created by A BCDe on 2019-01-20.
//

#ifndef OFCT_MMR_PLAYER_H
#define OFCT_MMR_PLAYER_H


#include <string>
#include <ostream>

class Player {
    std::string name;
    //std::size_t rank;
    //double pp;
    double mmr;

public:
    Player() : name(""), /*rank(0), pp(0), */mmr(0) {}
    Player(std::string name, /*size_t rank, double pp, */double mmr) : name(std::move(name)), /*rank(rank), pp(pp), */mmr(mmr) {}
    Player(const Player &) = default;
    Player(Player &&) noexcept = default;
    Player &operator=(const Player &) = default;
    Player &operator=(Player &&) = default;
    ~Player() = default;

    const double &get_mmr() const { return mmr; }

    // comparisons
    bool operator==(const Player &rhs) const {
        return mmr == rhs.mmr;
    }
    bool operator!=(const Player &rhs) const {
        return !(rhs == *this);
    }
    bool operator<(const Player &rhs) const {
        return mmr < rhs.mmr;
    }
    bool operator>(const Player &rhs) const {
        return rhs < *this;
    }
    bool operator<=(const Player &rhs) const {
        return !(rhs < *this);
    }
    bool operator>=(const Player &rhs) const {
        return !(*this < rhs);
    }

    // arithmetics
    friend double operator-(double x, const Player &player) {
        return x - player.mmr;
    }
    friend double operator-(const Player &player1, const Player &player2) {
        return player1.mmr - player2.mmr;
    }

    // stream out
    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << player.name; // << ", " << player.mmr;
        return os;
    }
};


#endif //OFCT_MMR_PLAYER_H
