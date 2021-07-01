#pragma once

#include <string>
#include "HunterCentral.h"

namespace Hunter
{
	class HUNTER_API Shader
	{
	public:
		virtual bool Load(const std::string& vertexFile, const std::string& fragmentFile) = 0;
		virtual void Use() = 0;

		virtual void SetVec2Int(const std::string& uniformName, int val1, int val2) = 0;
		virtual ~Shader() = 0 {};
	};

}