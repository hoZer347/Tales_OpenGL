// Polygun uwu

#include "Battle.h"

int main() {
    if (!glfwInit())
        exit(EXIT_FAILURE);

    Battle game;
    game.init();
    
    glfwTerminate();
    exit(EXIT_SUCCESS);

    return 0;
}