#include "game.h"

using namespace std::literals;

int main() {
    int board_size, scores;
    std::cout << "������ ����: "s << std::endl;
    std::cin >> board_size;
    std::cout << "������� ����� ����� ��� ������: "s << std::endl;
    std::cin >> scores;

    std::random_device rd;

    Game game{ rd(), board_size, scores };
    game.Start();
}