#pragma once

#include "XenoniumAPI.hpp"

#include <string>

namespace Xenonium {
	struct XENONIUM_API GameData {
		float deltaTime = 0.0f;
	};

	class XENONIUM_API Game {
	public:
		void Initialize();
		void Run();

		void Exit();
		void Crash(std::string reason);

		int GetReturnCode();
	protected:
		// Window and Renderer are done when calling GameInit()
		virtual void GameInit(const GameData& data);
		// Process is called every frame
		virtual void GameProcess(const GameData& data);
		// The first function called when game is exiting
		virtual void GameExit(const GameData& data);
	private:
		bool m_initialized;
	};

	Game* CreateGame();
}