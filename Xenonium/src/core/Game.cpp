#include "core/Game.hpp"

#include "core/Logger.hpp"

#include <exception>

namespace Xenonium {
	void Game::Initialize() {
		if (m_initialized) {
			Logger::Warn("<Xenonium> Game::Initialize() called.");
			Logger::Warn("<Xenonium> Game already initialized!");
			return;
		}
		m_initialized = true;

		try {
			Logger::Info("<Xenonium> Initializing engine...");
			m_window = std::make_unique<Window>();
			m_window->Initialize("Game", 640, 360);
			Logger::Info("<Xenonium> Engine initialized!");

			Logger::Info("<Xenonium> Initializing game...");
			this->GameInit(m_data);
			Logger::Info("<Xenonium> Game initialized!");

			Logger::Info("<Xenonium> Showing window...");
			m_window->SetVisible(true);
		}
		catch (std::exception& e) {
			Logger::Error("<Xenonium> Exception found while initializing engine!");
			Crash(std::string(e.what()));
		}
	}

	void Game::Run() {
		if (m_crashed) {
			HandleCrash();
			return;
		}
		try {
			Logger::Info("<Xenonium> Starting game loop...");

			std::string windowTitle = m_window->GetTitle();

			auto lastTime = std::chrono::steady_clock::now();

			auto accumulator = std::chrono::nanoseconds(0);
			auto frameAccumulator = std::chrono::nanoseconds(0);

			auto delta = std::chrono::nanoseconds(0);

			int frames = 0;
			bool canRender = false;

			m_running = true;
			Logger::Info("----------------- Game is running! -----------------");
			while (m_running) {
				canRender = false;

				auto currentTime = std::chrono::steady_clock::now();
				auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime);
				lastTime = currentTime;

				frameAccumulator += elapsedTime;

				if (m_frametime > std::chrono::nanoseconds(1)) { // If frametime > 1 nano seconds, that means that the framerate isn't unlimited
					accumulator += elapsedTime;

					if (accumulator >= m_frametime) {
						delta = accumulator;

						long long remove = accumulator / m_frametime; // Gets the amount of frames that should've passed
						accumulator -= m_frametime * remove;
						canRender = true;
					}
				}
				else {
					delta = elapsedTime;
					canRender = true;
				}

				if (frameAccumulator >= std::chrono::nanoseconds(1000000000LL)) {
					fps = frames;
					frames = 0;
					frameAccumulator = std::chrono::nanoseconds(0);
				}

				if (canRender) {
					float deltaTime = std::chrono::duration<float>(delta).count();

					m_window->Poll();

					const std::string title = windowTitle + std::string(" - FPS: ") + std::to_string(fps);
					m_window->SetTitle(title);

					m_data.deltaTime = deltaTime;
					this->GameProcess(m_data);

					frames++;
				}

				// m_window->ShouldClose()
				if (m_shouldExit || m_crashed) {
					this->Exit();
				}
			}
			Logger::Info("<Xenonium> Game finished running.");
		}
		catch (const std::exception& e) {
			Logger::Error("<Xenonium> Exception found while running game!");
			Crash(std::string(e.what()));
		}
	}

	void Game::Exit() {
		if (m_crashed) {
			m_running = false;
			HandleCrash();
			return;
		}

		if (!m_running) {
			Logger::Warn("<Xenonium> Game::Exit() called.");
			Logger::Warn("<Xenonium> Game is not running!");
			return;
		}
		m_running = false;

		try {
			Logger::Info("<Xenonium> Stopping game...");
			this->GameExit(m_data);
			Logger::Info("<Xenonium> Game stopped!");
		}
		catch (std::exception& e) {
			Logger::Error("<Xenonium> Exception found while exiting game!");
			Crash(std::string(e.what()));
		}

		HandleCrash();
	}

	void Game::Stop() {
		m_shouldExit = true;
	}

	void Game::Crash(const std::string& reason) {
		m_crashed = true;
		m_crashReason = reason;
		m_returnCode = -1;
	}

	void Stall(std::chrono::milliseconds duration) {
		auto lastTime = std::chrono::steady_clock::now();
		auto accumulator = std::chrono::nanoseconds(0);

		// "accumulator < duration" casts accumulator to milliseconds and loses precision due to truncation
		// "duration > accumulator" implicit casts s to nanoseconds
		while (duration > accumulator) {
			auto currentTime = std::chrono::steady_clock::now();
			auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime);
			lastTime = currentTime;
			accumulator += elapsedTime;
		}
	}

	void Game::SetFramerate(int fps) {
		if (fps > 0) {
			m_frametime = std::chrono::nanoseconds(1000000000LL) / fps;
		}
		else {
			m_frametime = std::chrono::nanoseconds(1);
		}
	}

	void Game::HandleCrash() {
		if (!m_crashed) {
			return;
		}

		Logger::Fatal("<Xenonium> FATAL ERROR!!! GAME CRASHED!!!");
		Logger::Fatal("<Xenonium> Crash reason: ");
		Logger::Fatal(m_crashReason);

		this->Stall(std::chrono::milliseconds(15000));
	}

	int Game::GetReturnCode() {
		return m_returnCode;
	}

	void Game::GameInit(const GameData& data) {}
	void Game::GameProcess(const GameData& data) {}
	void Game::GameExit(const GameData& data) {}
}