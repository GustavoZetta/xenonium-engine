#define _XENONIUM_ENTRY_POINT
#include <Xenonium.hpp>

class Sandbox : public Xenonium::Game {
private:
	void GameInit(const Xenonium::GameData& data) {

	}

	void GameProcess(const Xenonium::GameData& data) {
		
	}

	void GameExit(const Xenonium::GameData& data) {

	}
};

Xenonium::Game* Xenonium::CreateGame() {
	return new Sandbox;
}