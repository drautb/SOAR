#ifndef TEXTURE_H
#define TEXTURE_H

#include <GLFW/glfw3.h>

namespace SOAR
{
    namespace Video
    {
        class Texture
        {
        private:
            Texture();

        public:

            /**
             * This static method simply loads the texture specified, and returns
             * a GLuint handle to it. It automatically tries to load it as nicely
             * as possible. (Using DevIL)
             * @param  filename The name/path of the texture to load
             * @return          A GLuint handle to the loaded texture
             */
            static GLuint Load(const char* filename);
        };
    }
}

#endif