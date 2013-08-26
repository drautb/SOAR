#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include "Texture.h"
#include <math/Rectangle.h>

using namespace SOAR;
using namespace Math;

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

            /**
             * The method renders just a subset of the texture to
             * x, y, as specified by srcRect.
             * @param x       Where to render in x
             * @param y       Where to render in y
             * @param srcRect The subset of the whole texture to render.
             */
            void Render(int x, int y, const Rectangle<int>& srcRect);
        };
    }
}

#endif

