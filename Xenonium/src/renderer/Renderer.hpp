#pragma once

#include "XenoniumAPI.hpp"

#include "TextureAtlas.hpp"

#include <memory>

namespace Xenonium {
	class XENONIUM_API I_Renderer {
	public:
		virtual void Initialize() = 0;
		virtual void CleanUp() = 0;

		virtual void BindTexture(TextureAtlas* atlas) = 0;
		virtual void DrawSprite() = 0; 

		virtual void SetBackgroundColor(float r, float g, float b, float a) = 0;
	};

	std::unique_ptr<I_Renderer> CreateRenderer();
}