#include <cstdlib>

#include <IL/ilut.h>
#include <GLFW/glfw3.h>

#include "Texture.h"
#include "StringUtils.h"

using namespace SOAR;
using namespace Video;

Texture::Texture()
{

}

GLuint Texture::Load(const char* filename)
{
    char* nonConstName = Util::StringUtils::RemoveConst(filename);
    GLuint textureHandle = ilutGLLoadImage(nonConstName);
    free(nonConstName);

    return textureHandle;
}

