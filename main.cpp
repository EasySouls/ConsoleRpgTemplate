#include <random>
#include "Game.h"

int main() {
    std::random_device rd;  // Seed the generator
    std::mt19937 rng(rd()); // Mersenne Twister PRNG
    // Define a random number distribution
    std::uniform_int_distribution<int> distribution(1, 100);

    Game game;
    game.initGame();

    while (game.getIsRunning()) {
        game.mainMenu();
    }

    return 0;
}
