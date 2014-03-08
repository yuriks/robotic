#include <cstdint>
#include <memory>
#include <iostream>

#include "game.hpp"
#include "graphics/SpriteBuffer.hpp"
#include "graphics/gl/gl_1_5.h"

class TestState : public GameState {
public:
	SpriteBuffer spr_buffer;
	SpriteBufferIndices spr_buffer_indices;

	TestState() {

	}

	virtual std::tuple<StateAction, std::unique_ptr<GameState>> update() {
		spr_buffer.clear();

		return std::make_tuple(StateAction::KEEP, nullptr);
	}

	virtual void draw() {

	}
};

#include <SDL2/SDL.h>

int main(int, char* []) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* sdl_window = SDL_CreateWindow("Robotic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
	if (sdl_window == nullptr) {
		return 1;
	}
	SDL_GLContext gl_context = SDL_GL_CreateContext(sdl_window);
	if (gl_context == nullptr) {
		return 1;
	}

	if (ogl_LoadFunctions() != ogl_LOAD_SUCCEEDED) {
		return 1;
	}

	Game game(std::make_unique<TestState>());

	for (;;) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {

		}

		if (!game.update()) {
			break;
		}
		game.draw();

		SDL_GL_SwapWindow(sdl_window);
	}

	SDL_Quit();

	return 0;
}
