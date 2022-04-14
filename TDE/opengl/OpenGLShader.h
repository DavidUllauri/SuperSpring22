#pragma once
#include "ShaderInterface.h"

namespace TDE
{
	class OpenGLShader : public ShaderInterface
	{
		public:
			OpenGLShader(const std::string & vertexFile, const std::string & fragmentFile);

			virtual void UploadUniformInt3(const std::string& name, int xval, int yval, int zval) override;
			virtual void UploadUniformInt2(const std::string& name, int xval, int yval) override;
			virtual void Bind() override;

		private:
			unsigned int mShaderProgram;
	};
}

