#pragma once

#include "XenoniumAPI.hpp"

#include <string>

namespace Xenonium {
	class XENONIUM_API Window {
	public:
		void Initialize(std::string title, int width, int height);
		void Poll();
		void Exit();
	private:
		std::string m_title = "";
		int width = 0, height = 0;
	};
}