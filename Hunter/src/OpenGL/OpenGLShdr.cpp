#include "pch.h"
#include "OpenGL/OpenGLShdr.h"
#include "HunterCentral.h"

#include <cassert>
#include <fstream>
#include <sstream>

namespace Hunter
{
	bool OpenGLShdr::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		std::ifstream vertexSource{ vertexFile };
		std::ifstream fragmentSource{ fragmentFile };

		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertexSource.rdbuf();
		fShaderStream << fragmentSource.rdbuf();

		vertexSource.close();
		fragmentSource.close();

		std::string vertexCode{ vShaderStream.str() };
		std::string fragmentCode{ fShaderStream.str() };

		unsigned int vShader{ CompileVertexShader(vertexCode) };
		if (!vShader)
		{
			glDeleteShader(vShader);
			return false;
		}

		unsigned int fShader{ CompileFragmentShader(fragmentCode) };
		if (!fShader)
		{
			glDeleteShader(vShader);
			glDeleteShader(fShader);
			return false;
		}

		if (mShaderProgram)
			glDeleteProgram(mShaderProgram);

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vShader);
		glAttachShader(mShaderProgram, fShader);
		glLinkProgram(mShaderProgram);

		int success{ 0 };
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			char infoLog[512];
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			HLOG("ERROR LINKING SHADER PROGRAM:");
			HLOG(infoLog);
			glDeleteShader(vShader);
			glDeleteShader(fShader);
			return false;
		}

		glDeleteShader(vShader);
		glDeleteShader(fShader);

		return true;
	}

	void OpenGLShdr::Use()
	{
		assert(mShaderProgram);

		glUseProgram(mShaderProgram);
	}

	void OpenGLShdr::SetVec2Int(const std::string& uniformName, int val1, int val2)
	{
		assert(mShaderProgram);

		int uniformID{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(uniformID, val1, val2);
	}

	OpenGLShdr::~OpenGLShdr()
	{
		if (mShaderProgram)
			glDeleteProgram(mShaderProgram);
	}

	unsigned int OpenGLShdr::CompileVertexShader(const std::string& vertexCode)
	{
		unsigned int vShader;
		vShader = glCreateShader(GL_VERTEX_SHADER);

		const char* cstring{ vertexCode.c_str() };
		glShaderSource(vShader, 1, &cstring, 0);
		glCompileShader(vShader);

		int success{ 0 };
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char infoLog[512];
			glGetShaderInfoLog(vShader, 512, NULL, infoLog);
			HLOG("ERROR COMPILING VERTEX SHADER:");
			HLOG(infoLog);
		}

		return vShader;
	}

	unsigned int OpenGLShdr::CompileFragmentShader(const std::string& fragmentCode)
	{
		unsigned int fShader;
		fShader = glCreateShader(GL_FRAGMENT_SHADER);

		const char* cstring{ fragmentCode.c_str() };
		glShaderSource(fShader, 1, &cstring, 0);
		glCompileShader(fShader);

		int success{ 0 };
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char infoLog[512];
			glGetShaderInfoLog(fShader, 512, NULL, infoLog);
			HLOG("ERROR COMPILING FRAGMENT SHADER:");
			HLOG(infoLog);
		}

		return fShader;
	}
}