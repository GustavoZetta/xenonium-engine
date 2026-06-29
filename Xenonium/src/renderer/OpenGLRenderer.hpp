#pragma once

#include "renderer/Renderer.hpp"

namespace Xenonium {
	class OpenGLRenderer : public I_Renderer {
		void Initialize() override;
		void CleanUp() override;

		void BindTexture(TextureAtlas* atlas) override;
		void RenderSprite() override;

		void SetBackgroundColor(float r, float g, float b, float a) override;
	};
}