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
		std::string sourceCode;
		std::ifstream vertexInput{ vertexFile };

		while (vertexInput)
		{
			std::string line;
			std::getline(vertexInput, line);
			sourceCode += line;
		}

		vertexInput.close();

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
		std::ifstream fragmentInput{ fragmentFile };

		while (fragmentInput)
		{
			std::string line;
			std::getline(fragmentInput, line);
			sourceCode += line;
		}

		fragmentInput.close();

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
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
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
