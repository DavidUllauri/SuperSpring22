#include "pch.h"
#include "Shader.h"
#include "opengl/OpenGLShader.h"

namespace TDE
{
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef TDE_OPENGL
		mShader = new OpenGLShader{ vertexFile, fragmentFile };
#else
		#Only_OpenGL_is_supported;
#endif // TDE OPENGL
	}

	void Shader::UploadUniformInt3(const std::string& name, int xval, int yval, int zval)
	{
		mShader->UploadUniformInt3(name, xval, yval, zval);
	}

	void Shader::UploadUniformInt2(const std::string& name, int xval, int yval)
	{
		mShader->UploadUniformInt2(name, xval, yval);
	}

	void Shader::Bind()
	{
		mShader->Bind();
	}

}