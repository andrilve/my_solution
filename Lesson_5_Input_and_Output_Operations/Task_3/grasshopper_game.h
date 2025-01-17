#pragma once

#include <algorithm>
#include <iostream>
#include <random>

class Grasshopper {
public:
    Grasshopper(size_t seed, const int size = 10) :
        random_gen_(seed),
        board_size_(size),
        pos_grasshopper_(0) {
        SetFlyPosition();
    }

    // ���������� ������� ���� � ���������� � ������.
    void PrintBoard() {
        using namespace std::literals;
        for (int i = 0; i < board_size_; i++) {
            if (i == pos_grasshopper_) {
                std::cout << "k"s;
            }
            else if (i == pos_fly_) {
                std::cout << "o"s;
            }
            else {
                std::cout << "-"s;
            }
        }
        std::cout << std::endl;
    }

    // ���������, ������ �� �������� �����.
    bool UpdateFly() {
        if (pos_grasshopper_ == pos_fly_) {
            SetFlyPosition(); // ���� ��, ����� ������������ �� ����� �����.
            return true;
        }
        return false;
    }

    // ���������� ����� ������� ���������.
    int GetHopperPosition() {
        return pos_grasshopper_;
    }

    // �������� ����� �� ��������� �������.
    void SetFlyPosition() {
        std::uniform_int_distribution<> distrib(0, board_size_ - 1);
        pos_fly_ = distrib(random_gen_);
        while (pos_fly_ == pos_grasshopper_) {
            pos_fly_ = distrib(random_gen_);
        }
    }
    friend Grasshopper& operator>>(Grasshopper& k, int hops);
    friend Grasshopper& operator<<(Grasshopper& k, int hops);

private:
    std::mt19937 random_gen_;
    int board_size_;
    int pos_grasshopper_;
    int pos_fly_;
};

inline Grasshopper& operator>>(Grasshopper& k, int hops) {
    k.pos_grasshopper_ = std::clamp(k.pos_grasshopper_+hops, 0, k.board_size_);
    return k;
}

inline Grasshopper& operator<<(Grasshopper& k, int hops) {
    k.pos_grasshopper_ = std::clamp(k.pos_grasshopper_ - hops, 0, k.board_size_);
    return k;
}