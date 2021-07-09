#include "pch.h"
#include "OpenGL/OpenGLImplementation.h"
#include "HunterApp.h"

namespace Hunter
{
	OpenGLImplementation::OpenGLImplementation()
	{
		Init();
	}

	void OpenGLImplementation::Init()
	{
		mShaderDefault.Load(
			"../Hunter/assets/shaders/VertexShaderDefault.glsl",
			"../Hunter/assets/shaders/FragmentShaderDefault.glsl"
		);

		mShaderDefault.Use();

		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}

	void OpenGLImplementation::Draw(const Sprite& image, int x_pos, int y_pos, int width, int height)
	{
		float vertices[] = {
			(float)x_pos,			(float)y_pos,			 0.0f, 0.0f,
			(float)x_pos,			(float)(y_pos + height), 0.0f, 1.0f,
			(float)(x_pos + width), (float)y_pos,			 1.0f, 0.0f,
			(float)(x_pos + width), (float)(y_pos + height), 1.0f, 1.0f,
		};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int picture;
		glGenTextures(1, &picture);
		glBindTexture(GL_TEXTURE_2D, picture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetImagePointer());

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		mShaderDefault.SetVec2Int("windowSize", HunterApp::GetWindowWidth(), HunterApp::GetWindowHeight());

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		glDeleteTextures(1, &picture);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);
	}

	void OpenGLImplementation::ClearFrame()
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	OpenGLImplementation::~OpenGLImplementation()
	{

	}
}