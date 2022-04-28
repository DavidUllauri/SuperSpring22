#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
namespace TDE
{
	OpenGLShader::OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// FILE READING //
		std::string sourceCode = ReadFile(vertexFile);

		const char* cSource = sourceCode.c_str();

		glShaderSource(vertexShader, 1, &cSource, NULL);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// FILE READING //
		sourceCode.clear();
		sourceCode = ReadFile(fragmentFile);

		const char* fragSource = sourceCode.c_str();
		glShaderSource(fragmentShader, 1, &fragSource, NULL);
		glCompileShader(fragmentShader);

		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// Link shaders
		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);
		// check for linking errors
		glValidateProgram(mShaderProgram);
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	std::string OpenGLShader::ReadFile(const std::string& shaderfile)
	{
		std::string sourceCode;
		std::ifstream ifs(shaderfile, std::ios::in | std::ios::binary);

		if (!ifs)
		{
			std::cout << "Could not open file '{0}'" << shaderfile << std::endl;
			return sourceCode;
		}

		ifs.seekg(0, std::ios::end);
		size_t size = ifs.tellg();

		if (size == -1)
		{
			std::cout << "Could not read from file '{0}'" << shaderfile << std::endl;
			return sourceCode;
		}

		sourceCode.resize(size);
		ifs.seekg(0, std::ios::beg);
		ifs.read(&sourceCode[0], size);

		return sourceCode;
	}

	void OpenGLShader::UploadUniformInt3(const std::string& name, int xval, int yval, int zval)
	{
		int uniformLocation{ glGetUniformLocation(mShaderProgram, name.c_str()) };
		Bind();
		glUniform3i(uniformLocation, xval, yval, zval);
	}

	void OpenGLShader::UploadUniformInt2(const std::string& name, int xval, int yval)
	{
		int uniformLocation{ glGetUniformLocation(mShaderProgram, name.c_str()) };
		Bind();
		glUniform2i(uniformLocation, xval, yval);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(mShaderProgram);
	}

}
