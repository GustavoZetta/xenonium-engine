#include "renderer/Renderer.hpp"

#include "renderer/OpenGLRenderer.hpp"

namespace Xenonium {
	std::unique_ptr<I_Renderer> CreateRenderer() {
		return std::make_unique<OpenGLRenderer>();
	};
}