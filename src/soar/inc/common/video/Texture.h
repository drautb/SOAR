#ifndef TEXTURE_H
#define TEXTURE_H

#include <GLFW/glfw3.h>

#include <content/IContent.h>

namespace SOAR
{
    namespace Video
    {
        class Texture : public SOAR::Content::IContent
        {
        private:

            /**
             * The OpenGL texture handle
             */
            GLuint      textureHandle;

        public:
            
            /**
             * This method simply loads the texture specified, and returns
             * a GLuint handle to it. It automatically tries to load it as nicely
             * as possible. (Using DevIL)
             * @param  filename The name/path of the texture to load
             * @return          A GLuint handle to the loaded texture
             */
            bool Load(const char* filename);

            /**
             * Nothing needs to be released for textures right now, 
             * but this method must be defined to implement the IContent interface.
             */
            bool Release();

            /**
             * This method just returns a const reference to the 
             * textureHandle used to reference the texture.
             * @return textureHandle
             */
            const GLuint& Handle()const;
        };
    }
}

#endif