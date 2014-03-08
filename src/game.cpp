#include "game.hpp"
#include <cassert>

Game::Game(std::unique_ptr<GameState>&& initial_state) {
	if (initial_state != nullptr) {
		state_stack.push_back(std::move(initial_state));
	}
}

bool Game::update() {
	for(;;) {
		if (state_stack.empty()) {
			return false;
		}

		StateAction action;
		std::unique_ptr<GameState> argument;
		std::tie(action, argument) = state_stack.back()->update();

		switch (action) {
		case StateAction::KEEP:
			if (argument == nullptr) {
				return true;
			}
			break;
		case StateAction::POP:
			state_stack.pop_back();
			break;
		}

		if (argument != nullptr) {
			state_stack.push_back(std::move(argument));
		}
	}
}

void Game::draw() const {
	assert(!state_stack.empty());
	state_stack.back()->draw();
}
