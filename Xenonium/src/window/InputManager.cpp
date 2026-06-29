#include "window/InputManager.hpp"

namespace Xenonium {
	void InputManager::SetViewSize(int width, int height) {
		m_viewWidth = width;
		m_viewHeight = height;
	}
	void InputManager::SetViewOffset(int offsetX, int offsetY) {
		m_offsetX = offsetX;
		m_offsetY = offsetY;
	}
	void InputManager::SetMousePos(double mouseX, double mouseY) {
		m_mouseX = mouseX;
		m_mouseY = mouseY;
	}

	void InputManager::SetKeyAction(int key, int action) {
		m_keyboardKeys[key] = action;
	}

	void InputManager::SetMouseButtonAction(int button, int action) {
		m_mouseButtons[button] = action;
	}

	void InputManager::ProcessInput() {
		for (int i = 0; i <= GLFW_KEY_LAST; i++) {
			int action = m_keyboardKeys[i];
			KeyState& s = m_keyboardKeysStates[i];

			if (action == GLFW_PRESS || action == GLFW_REPEAT) {
				s = (s == KeyState::NONE || s == KeyState::RELEASED)
					? KeyState::PRESSED   // first frame
					: KeyState::REPEAT;     // next frames
			}
			else {
				s = (s == KeyState::PRESSED || s == KeyState::REPEAT)
					? KeyState::RELEASED  // first frame released
					: KeyState::NONE;     // next frames
			}
		}

		for (int i = 0; i <= GLFW_MOUSE_BUTTON_LAST; i++) {
			int action = m_keyboardKeys[i];
			KeyState& s = m_keyboardKeysStates[i];

			if (action == GLFW_PRESS || action == GLFW_REPEAT) {
				s = (s == KeyState::NONE || s == KeyState::RELEASED)
					? KeyState::PRESSED   // first frame
					: KeyState::REPEAT;     // next frames
			}
			else {
				s = (s == KeyState::PRESSED || s == KeyState::REPEAT)
					? KeyState::RELEASED  // first frame released
					: KeyState::NONE;     // next frames
			}
		}
	}

	bool InputManager::IsKeyPressed(int key) {
		return m_keyboardKeys[key] != 0;
	}

	bool InputManager::IsMouseButtonPressed(int button) {
		return m_mouseButtons[button] != 0;
	}

	KeyState InputManager::GetKeyState(int key) {
		return m_keyboardKeysStates[key];
	}

	KeyState InputManager::GetMouseButtonState(int button) {
		return m_mouseButtonsStates[button];
	}
}