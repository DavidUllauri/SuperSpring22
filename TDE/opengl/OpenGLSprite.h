#pragma once

#include "SpriteInterface.h"

namespace TDE
{
    class OpenGLSprite : public SpriteInterface
    {
    public:
        OpenGLSprite(const std::string& file);
        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual void Bind() override;
        virtual bool IsBound() const override;
    private:
        unsigned int mVBO;  // Vertex Buffer Object
        unsigned int mVAO;  // Vertex Array Object
        unsigned int mEBO;  // Element Buffer Object
        unsigned int mTexture;  // Holds the ID of the texture object
        int mWidth{ 0 };    // Width of loaded image in pixels
        int mHeight{ 0 };   // Height of loaded image in pixels
    };
}
