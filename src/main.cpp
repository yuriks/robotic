#include "game.hpp"

#include <cstdint>
#include <memory>
#include <iostream>

int main() {
	Game game(nullptr);

	while (game.update()) {
		game.draw();
	}
}
