/**
 * @file main.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.ey)
 * @brief The entry point
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac < 5) {
        std::cout << av[0] << " <server_host> <server_port> <public_ip> <public_port>" << std::endl;
        return 84;
    }
    rt::core::Core core(av[1], std::stoi(av[2]), av[3], std::stoi(av[4]));
    core.run();
    return 0;
}
