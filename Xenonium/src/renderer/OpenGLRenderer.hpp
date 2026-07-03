#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer/Renderer.hpp"

namespace Xenonium {
	class OpenGLRenderer : public I_Renderer {
	public:
		void Initialize() override;
		void CleanUp() override;

		void BindTexture(TextureAtlas* atlas) override;
		void DrawSprite() override;

		void SetBackgroundColor(float r, float g, float b, float a) override;
	private:
		bool m_initialized = false;
		
		GLuint ScreenVAO = 0;
	};
}