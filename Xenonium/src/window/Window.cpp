#include "window/Window.hpp"

#include "core/Logger.hpp"

#include <stdexcept>

namespace Xenonium {
	void Window::Initialize(std::string title, int width, int height) {
		if (m_initialized) {
			Logger::Warn("<Xenonium> Called Window::Initialize().");
			Logger::Warn("<Xenonium> Window is already initialized!");
			return;
		}
		m_initialized = true;
		Logger::Info("<Xenonium> Initializing window...");

		m_title = title;
		m_width = width;
		m_height = height;

		if (!glfwInit()) {
			Logger::Fatal("<Xenonium> Could not initialize GLFW!");
			throw std::runtime_error("GLFW could not be initialized. \nin line 23 of Window::Initialize(std::string title, int width, int height)");
			return;
		}
		Logger::Info("<Xenonium> Initialized GLFW!");

		glfwDefaultWindowHints();

		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

		#ifdef __APPLE__
		//This is only needed in macOS
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		#endif

		Logger::Info("<Xenonium> Creating GLFW window...");
		m_win = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
		if (!m_win) {
			Logger::Fatal("<Xenonium> Failed to create GLFW window!");
			throw std::runtime_error("Could not create GLFW window. \nin line 45 of Window::Initialize(std::string title, int width, int height)");
			return;
		}

		// Context must come before initializing glad
		glfwMakeContextCurrent(m_win);

		Logger::Info("<Xenonium> GLFW window created!");

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			Logger::Fatal("<Xenonium> Could not initialize GLAD!");
			throw std::runtime_error("GLAD could not be initialized. \nin line 56 of Window::Initialize(std::string title, int width, int height)");
			return;
		}
		Logger::Info("<Xenonium> Initialized GLAD!");

		glfwSetWindowUserPointer(m_win, this);

		glfwSetFramebufferSizeCallback(m_win, s_FramebufferSizeCallback);
		glfwSetCursorPosCallback(m_win, s_CursorPosCallback);
		glfwSetKeyCallback(m_win, s_KeyCallback);
		glfwSetMouseButtonCallback(m_win, s_MouseButtonCallback);

		s_FramebufferSizeCallback(m_win, m_width, m_height);

		Logger::Success("<Xenonium> Sucessfully initialized window!");
	}

	void Window::Poll() {
		if (!m_initialized) {
			return;
		}
		glfwSwapBuffers(m_win);
		glfwPollEvents();
		m_input.ProcessInput();
	}

	void Window::CleanUp() {
		if (!m_initialized) {
			Logger::Warn("<Xenonium> Called Window::CleanUp().");
			Logger::Warn("<Xenonium> Cannot clean up window before initializing!");
			return;
		}
		Logger::Info("<Xenonium> Cleanning up window...");
		m_initialized = false;
		Logger::Info("<Xenonium> Destroying GLFW window...");
		glfwDestroyWindow(m_win);
		Logger::Success("<Xenonium> Sucessfully cleaned up window!");
	}

	GLFWwindow* Window::ID() const {
		return m_win;
	}

	bool Window::ShouldClose() {
		return glfwWindowShouldClose(m_win);
	}

	void Window::SetTitle(const std::string& title) {
		if (!m_initialized) {
			return;
		}
		if (m_title == title) {
			return;
		}
		m_title = title;
		glfwSetWindowTitle(m_win, m_title.c_str());
	}

	std::string Window::GetTitle() const {
		return m_title;
	}

	void Window::SetVisible(bool visible) {
		if (!m_initialized) {
			return;
		}

		m_visible = visible;
		if (m_visible) {
			glfwShowWindow(m_win);
		}
		else {
			glfwHideWindow(m_win);
		}
	}

	bool Window::IsVisible() const {
		return m_visible;
	}

	void Window::SetFullscreen(bool fullscreen) {
		if (!m_initialized) {
			return;
		}

		GLFWmonitor* monitor = GetWindowMonitor();

		m_fullscreen = fullscreen;
		if (m_fullscreen) {
			glfwGetWindowPos(m_win, &m_previousX, &m_previousY);
			glfwGetWindowSize(m_win, (int*)&m_previousWidth, (int*)&m_previousHeight);
			m_previousMonitor = monitor;

			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			glfwSetWindowMonitor(m_win, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		}
		else {
			glfwSetWindowMonitor(m_win, nullptr, m_previousX, m_previousY, m_previousWidth, m_previousHeight, 0);
		}
	}

	bool Window::IsFullscreen() const {
		return m_fullscreen;
	}

	InputManager* Window::GetInputManager() {
		return &m_input;
	}

	GLFWmonitor* Window::GetWindowMonitor() {
		GLFWmonitor* nativeMonitor = glfwGetWindowMonitor(m_win);
		if (nativeMonitor != nullptr) {
			return nativeMonitor;
		}

		int wx, wy, ww, wh;
		glfwGetWindowPos(m_win, &wx, &wy);
		glfwGetWindowSize(m_win, &ww, &wh);

		int monitorCount;
		GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);

		GLFWmonitor* bestMonitor = nullptr;
		int maxOverlapArea = 0;

		for (int i = 0; i < monitorCount; ++i) {
			GLFWmonitor* monitor = monitors[i];
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			if (!mode) continue;

			int mx, my;
			glfwGetMonitorPos(monitor, &mx, &my);
			int mw = mode->width;
			int mh = mode->height;

			// Calculate overlap intersection rectangle boundaries
			int overlapX = std::max(wx, mx);
			int overlapY = std::max(wy, my);
			int overlapW = std::min(wx + ww, mx + mw) - overlapX;
			int overlapH = std::min(wy + wh, my + mh) - overlapY;

			// Check if there is a valid overlap area
			if (overlapW > 0 && overlapH > 0) {
				int overlapArea = overlapW * overlapH;
				if (overlapArea > maxOverlapArea) {
					maxOverlapArea = overlapArea;
					bestMonitor = monitor;
				}
			}
		}

		// Fallback if window is completely off-screen
		if (!bestMonitor) {
			bestMonitor = glfwGetPrimaryMonitor();
		}

		return bestMonitor;
	}

	void Window::s_FramebufferSizeCallback(GLFWwindow* win, int w, int h) {
		// Window User Pointer is a way in GLFW to store a pointer,
		// in this case, the Window class pointer.
		Window* winObj = static_cast<Window*>(glfwGetWindowUserPointer(win));

		winObj->m_height = static_cast<unsigned int>(h);
		winObj->m_width = static_cast<unsigned int>(w);

		// Math to setting up the glViewport to the center of the screen
		const float targetRatio = 16.0f / 9.0f;

		int viewW, viewH;

		viewW = w;
		viewH = (int)(w / targetRatio);

		if (viewH > h) {
			viewH = h;
			viewW = (int)(h * targetRatio);
		}

		int offsetX = (w - viewW) / 2;
		int offsetY = (h - viewH) / 2;

		winObj->m_input.SetViewSize(viewW, viewH);
		winObj->m_input.SetViewOffset(offsetX, offsetY);

		glViewport(offsetX, offsetY, viewW, viewH);
	}

	void Window::s_CursorPosCallback(GLFWwindow* win, double x, double y) {
		Window* winObj = static_cast<Window*>(glfwGetWindowUserPointer(win));

		winObj->m_input.SetMousePos(x, y);
	}

	void Window::s_KeyCallback(GLFWwindow* win, int key, int scancode, int action, int mods) {
		if (key < 0 || key > GLFW_KEY_LAST) return;

		Window* winObj = static_cast<Window*>(glfwGetWindowUserPointer(win));

		winObj->m_input.SetKeyAction(key, action);
	}

	void Window::s_MouseButtonCallback(GLFWwindow* win, int button, int action, int mods) {
		Window* winObj = static_cast<Window*>(glfwGetWindowUserPointer(win));

		winObj->m_input.SetMouseButtonAction(button, action);
	}
}