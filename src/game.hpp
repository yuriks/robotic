#pragma once
#include <vector>
#include <memory>
#include <tuple>

enum class StateAction {
	/// Keep the current state on the stack.
	KEEP,
	/// Pop the current state from the stack.
	POP,
};

class GameState {
public:
	virtual ~GameState() {}

	/// Runs a game update step. Returns whether to keep the current state for the next update and a new state to push.
	virtual std::tuple<StateAction, std::unique_ptr<GameState>> update() = 0;
	/// Updates the screen. This must not modify the state.
	virtual void draw() const = 0;
};

class Game {
public:
	Game(std::unique_ptr<GameState>&& initial_state);

	bool update();
	void draw() const;

private:
	std::vector<std::unique_ptr<GameState>> state_stack;
};
