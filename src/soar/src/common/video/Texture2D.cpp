#include <GLFW/glfw3.h>

#include "Texture.h"
#include "Texture2D.h"

using namespace SOAR;
using namespace Video;

Texture2D::Texture2D()
{
    
}

Texture2D::~Texture2D()
{

}

bool Texture2D::Load(const char* filename)
{
    if (Texture::Load(filename))
    {
        glBindTexture(target, textureHandle);
        glGetTexLevelParameteriv(target, 0, GL_TEXTURE_WIDTH, &width);
        glGetTexLevelParameteriv(target, 0, GL_TEXTURE_HEIGHT, &height);

        return true;
    }

    return false;
}

void Texture2D::Render(int x, int y)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(target, textureHandle);
    glBegin(GL_QUADS);
        glTexCoord2i(0, 0);                           
        glVertex2i(0, 0);
        glTexCoord2i(width, 0);     
        glVertex2i(width, 0);
        glTexCoord2i(width, height);    
        glVertex2i(width, height);
        glTexCoord2i(0, height);          
        glVertex2i(0, height);
    glEnd();
}
