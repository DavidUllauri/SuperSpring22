#pragma once

namespace TDE
{
	class ShaderInterface
	{
	public:
		virtual void UploadUniformInt3(const std::string& name, int xval, int yval, int zval) = 0;
		virtual void UploadUniformInt2(const std::string& name, int xval, int yval) = 0;
		virtual void Bind() = 0;
	};
}