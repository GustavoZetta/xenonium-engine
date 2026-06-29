#pragma once

#include "XenoniumAPI.hpp"

#include "window/Window.hpp"
#include "renderer/Renderer.hpp"

#include <string>
#include <memory>
#include <chrono>

namespace Xenonium {
	struct XENONIUM_API GameData {
		float deltaTime = 0.0f;
		Window* window = nullptr;
	};

	class XENONIUM_API Game {
	public:
		int fps = 0;
	public:
		void Initialize();
		void Run();

		// m_shouldclose = true;
		void Stop();
		void Crash(const std::string& reason);
		void Stall(std::chrono::milliseconds duration);

		void SetFramerate(int fps);

		int GetReturnCode();
	protected:
		// Window and Renderer are done when calling GameInit()
		virtual void GameInit(const GameData& data);
		// Process is called every frame
		virtual void GameProcess(const GameData& data);
		// The first function called when game is exiting
		virtual void GameExit(const GameData& data);
	private:
		void Exit();

		void HandleCrash();
	private:
		std::unique_ptr<Window> m_window = nullptr;
		std::unique_ptr<I_Renderer> m_renderer = nullptr;

		GameData m_data = {
			0.0f,
			nullptr
		};

		bool m_initialized = false;

		std::chrono::nanoseconds m_frametime = std::chrono::nanoseconds(1000000000LL) / 60;

		bool m_running = false;
		bool m_shouldExit = false;

		bool m_crashed = false;
		std::string m_crashReason = "";

		int m_returnCode = 0;
	};

	Game* CreateGame();
}