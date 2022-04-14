#pragma once

#include "ShaderInterface.h"
#include "Core.h"

namespace TDE
{
	class TDE_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		void UploadUniformInt3(const std::string& name, int xval, int yval, int zval);
		void UploadUniformInt2(const std::string& name, int xval, int yval);
		void Bind();
	private:
		ShaderInterface *mShader;
	};
}

