#define __XENONIUM_ENTRY_POINT
#include <Xenonium.hpp>

#include <iostream>

class Sandbox : public Xenonium::Game {
private:
	void GameInit(const Xenonium::GameData& data) {
		std::cout << "Init\n";
	}

	void GameProcess(const Xenonium::GameData& data) {
		
	}

	void GameExit(const Xenonium::GameData& data) {
		std::cout << "Exit\n";
	}
};

Xenonium::Game* Xenonium::CreateGame() {
	return new Sandbox;
}