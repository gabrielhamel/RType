/**
 * @file main.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Game.hpp"

int main(int ac, char **av)
{
    if (ac < 3) {
        std::cout << av[0] << " <public_ip> <port>" << std::endl;
        return 84;
    }
    rt::game::Game game(av[1], std::stoi(av[2]));
    game.run();
    return 0;
}
