#pragma once

#include "XenoniumAPI.hpp"

#include <GLFW/glfw3.h>

#include <array>

namespace Xenonium {
	enum class XENONIUM_API KeyState : int {
		NONE, // Key not pressed
		PRESSED, // First frame when key/button is pressed
		REPEAT, // Every frame when the key/button is pressed except first and last
		RELEASED // Last frame when key/button is pressed
	};

	class XENONIUM_API InputManager {
	public:
		void SetViewSize(int width, int height);
		void SetViewOffset(int offsetX, int offsetY);
		void SetMousePos(double mouseX, double mouseY);

		void SetKeyAction(int key, int action);
		void SetMouseButtonAction(int button, int action);

		void ProcessInput();

		bool IsKeyPressed(int key);
		bool IsMouseButtonPressed(int button);

		KeyState GetKeyState(int key);
		KeyState GetMouseButtonState(int button);
	private:
		// Key State
		std::array<KeyState, GLFW_KEY_LAST> m_keyboardKeysStates;
		std::array<KeyState, GLFW_MOUSE_BUTTON_LAST> m_mouseButtonsStates;
		// Key Action
		std::array<int, GLFW_KEY_LAST> m_keyboardKeys;
		std::array<int, GLFW_MOUSE_BUTTON_LAST> m_mouseButtons;

		int m_viewWidth = 0, m_viewHeight = 0;
		int m_offsetX = 0, m_offsetY = 0;

		double m_mouseX = 0.0, m_mouseY = 0.0;
	};
}