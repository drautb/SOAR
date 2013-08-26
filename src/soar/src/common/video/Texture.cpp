#include <cstdlib>

#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#include <GLFW/glfw3.h>

#include "Log.h"
#include "Texture.h"
#include "StringUtils.h"

using namespace SOAR;
using namespace Video;

GLenum Texture::currentTarget = GL_TEXTURE_2D;

Texture::Texture()
{
    // Set this individual texture's target to be whatever
    // the current target to use is.
    target = currentTarget;
}

Texture::~Texture()
{

}

void Texture::UseTarget(GLenum target)
{
    currentTarget = target;
}

bool Texture::LoadFile(const char* filename)
{
    ILuint ilTexId = generateILTextureId();

    if (ilLoadImage((const ILstring)filename))
        ilTextureToGL(ilTexId);

    if (glIsTexture(textureHandle))
        return true;

    SOAR_LOG_FATAL << "Failed to load texture: " << filename;
    return false;
}

bool Texture::LoadRaw(const unsigned char* data, int size)
{
    ILuint ilTexId = generateILTextureId();

    if (ilLoadL(0, data, size))
        ilTextureToGL(ilTexId);

    if (glIsTexture(textureHandle))
        return true;

    SOAR_LOG_FATAL << "Failed to load raw texture data: ilGetError: " << iluErrorString(ilGetError());
    return false;
}

bool Texture::Release()
{
    return true;
}

const GLuint& Texture::Handle()const
{
    return textureHandle;
}

ILuint Texture::generateILTextureId()
{
    ILuint ilTexId = 0;

    ilGenImages(1, &ilTexId);
    ilBindImage(ilTexId);

    return ilTexId;
}

void Texture::ilTextureToGL(ILuint ilTexId)
{
    if (ilConvertImage(IL_BGRA, IL_UNSIGNED_BYTE))
    {
        glGenTextures(1, &textureHandle);
        glBindTexture(target, textureHandle);
        
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear interpolation for magnification filter */
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear interpolation for minifying filter */
        
        glTexImage2D(target, 
                     0, 
                     ilGetInteger(IL_IMAGE_BPP), 
                     ilGetInteger(IL_IMAGE_WIDTH),
                     ilGetInteger(IL_IMAGE_HEIGHT), 
                     0, 
                     ilGetInteger(IL_IMAGE_FORMAT), 
                     GL_UNSIGNED_BYTE, 
                     ilGetData()); /* Texture specification */
    }
    
    ilDeleteImages(1, &ilTexId);
}
