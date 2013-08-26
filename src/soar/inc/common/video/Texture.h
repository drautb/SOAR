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
        protected:

            /**
             * The OpenGL texture handle
             */
            GLuint          textureHandle;

            /**
             * The OpenGL texture target
             */
            GLenum          target;

            /**
             * Static member, represents the current texture target to use
             */
            static GLenum   currentTarget;

        public:
            
            /**
             * The constructor sets the target to be the current target
             */
            Texture();

            /**
             * Destructor
             */
            ~Texture();

            /**
             * Sets the currentTarget variable to target.
             * @param target The new target to use when loading textures
             */
            static void UseTarget(GLenum target);

            /**
             * This method simply loads the texture specified, and returns
             * a GLuint handle to it. It automatically tries to load it as nicely
             * as possible. (Using DevIL)
             * @param  filename     The name/path of the texture to load
             * @return              A GLuint handle to the loaded texture
             */
            virtual bool Load(const char* filename);

            /**
             * Nothing needs to be released for textures right now, 
             * but this method must be defined to implement the IContent interface.
             */
            virtual bool Release();

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