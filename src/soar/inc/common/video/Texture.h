#ifndef TEXTURE_H
#define TEXTURE_H

#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
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
             * This method simply loads the texture specified.
             * It automatically tries to load it as nicely as possible. (Using DevIL)
             * @param  filename     The name/path of the texture to load
             * @return              A GLuint handle to the loaded texture
             */
            virtual bool LoadFile(const char* filename);

            /**
             * This method simply loads a texture from a raw c array of data,
             * and returns true if it was successful.
             * @param  data The data array to load
             * @return      true on success, false otherwise
             */
            virtual bool LoadRaw(const unsigned char* data, int size);

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

        private:

            /**
             * Just a subroutine to generate an ILuint texture id
             * @return  The generated il Txture id
             */
            ILuint generateILTextureId();

            /**
             * Another subroutine that takes a loaded ILuint texture,
             * and creates an OpenGL texture from it, storing the result
             * in this->textureHandle
             * @param   ilTexId The ilTexture to clean up with when done.
             */
            void ilTextureToGL(ILuint ilTexId);

        };
    }
}

#endif