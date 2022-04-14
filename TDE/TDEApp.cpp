#include "pch.h"

#include "TDEApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "Sprite.h"
#include "Shader.h"

namespace TDE
{
	void TDEApp::Run()
	{
		TDE_LOG("TDE running...");

		TDE::GameWindow::Init();

		TDE::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		

		TDE::Shader shader{ "../TDE/assets/shaders/VertexShaderDefault.glsl", "../TDE/assets/shaders/FragShaderDefault.glsl" };
		shader.UploadUniformInt2("windowSize", 800, 600);
		shader.UploadUniformInt3("spriteCoord", 100, 200, 1.0);

		//TDE::Sprite star{ "../TDE/assets/container.jpg" };
		TDE::Sprite star{"../TDE/assets/img/Star.png"};

		while (true)
		{
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();

			star.Bind();

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			
			TDE::GameWindow::GetWindow()->SwapBuffers();
			TDE::GameWindow::GetWindow()->PollEvents();
		}
	}
	void TDEApp::OnUpdate()
	{
	}
}
