#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include "Texture.h"

namespace SOAR
{
    namespace Video
    {
        /**
         * This class represents an OpenGL texture that 
         * will be used for 2D rendering.
         */
        class Texture2D : public Texture
        {
        protected:

            /**
             * Width (pixels) of the texture
             */
            int     width;

            /**
             * Height (pixels) of the texture
             */
            int     height;

        public:

            /**
             * Constructor
             */
            Texture2D();

            /**
             * Destructor
             */
            ~Texture2D();
        
            /**
             * Loads the texture. It invokes the parent load method, 
             * and then populates the width and height members.
             * @param  filename The texture file to load
             * @return          True if successful, false otherwise.
             */
            virtual bool Load(const char* filename);

            /**
             * Renders this texture at the specified coordinate.
             * @param x The x-coordinate
             * @param y The y-coordinate
             */
            void Render(int x, int y);
        };
    }
}

#endif

