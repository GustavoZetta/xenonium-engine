#pragma once

#include "XenoniumAPI.hpp"

#include <GLFW/glfw3.h>

#include <string>

#include "window/InputManager.hpp"

namespace Xenonium {
	class XENONIUM_API Window {
	public:
		void Initialize(std::string title, int width, int height);

		void Poll();
		void CleanUp();

		GLFWwindow* ID() const;

		bool ShouldClose();

		void SetTitle(const std::string& title);
		std::string GetTitle() const;

		void SetVisible(bool visible);
		bool IsVisible() const;
		void SetFullscreen(bool fullscreen);
		bool IsFullscreen() const;

		InputManager* GetInputManager();
		GLFWmonitor* GetWindowMonitor();

		// GLFW event callbacks
		static void s_FramebufferSizeCallback(GLFWwindow* win, int width, int height);
		static void s_CursorPosCallback(GLFWwindow* win, double x, double y);
		static void s_KeyCallback(GLFWwindow* win, int key, int scancode, int action, int mods);
		static void s_MouseButtonCallback(GLFWwindow* win, int button, int action, int mods);
	private:
		bool m_initialized = false;
	
		GLFWwindow* m_win;

		std::string m_title = "";
		int m_width = 0, m_height = 0;

		bool m_visible = false, m_fullscreen = false;

		int m_previousWidth = 0, m_previousHeight = 0;
		int m_previousX = 0, m_previousY = 0;
		GLFWmonitor* m_previousMonitor = nullptr;

		InputManager m_input;
	};
}