#include "pch.h"
#include "OpenGLRenderer.h"
#include "GameWindow.h"
#include "glad/glad.h"

namespace TDE
{
	void OpenGLRenderer::Draw(Sprite& image, int xPos, int yPos, int zPos, Shader shader)
	{
		int width{ GameWindow::GetWindow()->GetWidth() };
		int height{ GameWindow::GetWindow()->GetHeight() };

		shader.Bind();
		image.Bind();

		shader.UploadUniformInt2("windowSize", width, height);
		shader.UploadUniformInt3("spriteCoord", xPos, yPos, zPos);
		
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

}