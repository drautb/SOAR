#include <cstdlib>

#include <IL/ilut.h>
#include <GLFW/glfw3.h>

#include "Texture.h"
#include "StringUtils.h"

using namespace SOAR;
using namespace Video;

bool Texture::Load(const char* filename)
{
    char* nonConstName = Util::StringUtils::RemoveConst(filename);
    textureHandle = ilutGLLoadImage(nonConstName);
    free(nonConstName);

    return glIsTexture(textureHandle);
}

bool Texture::Release()
{
    return true;
}

const GLuint& Texture::Handle()const
{
    return textureHandle;
}
