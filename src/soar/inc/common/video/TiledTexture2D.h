#ifndef TILED_TEXTURE_2D
#define TILED_TEXTURE_2D

#include <math/Rectangle.h>
#include <video/Texture2D.h>

using namespace SOAR;
using namespace Math;

namespace SOAR
{
    namespace Video
    {
        class TiledTexture2D : public Texture2D
        {
        private:

            /**
             * The number of rows of tiles in this texture
             */
            int         rows;

            /**
             * The number of columns of tiles in this texture
             */
            int         cols;

            /**
             * The width of each tile in this texture
             */
            int         tileWidth;

            /**
             * The height of each tile in this texture
             */
            int         tileHeight;

            /**
             * The highest valid tile number
             */
            int        lastValidTileNumber;

            /**
             * Rectangle used for tile calculations
             */
            Rectangle<int>      tileRect;

        public:

            /**
             * Constructor
             */
            TiledTexture2D();
            
            /**
             * Destructor
             */
            ~TiledTexture2D();
        
            /**
             * This must be called to initialize the tile dimensions. It 
             * takes the row and column count, and calculates the width and 
             * height of each tile.
             * @param rows The number of rows of tiles in the texture
             * @param cols The number of columns of tiles in the texture
             */
            void SetRowColumnCount(int rows, int cols);            

            /**
             * This method will render the specified tile at the given
             * x/y coordinates on screen.
             * @param x          The x-location
             * @param y          The y-location
             * @param tileNumber The tile number to render. 0 corresponds
             *                   to the upper left tile in the texture. They 
             *                   count left to right, top to bottom.
             */
            void RenderTile(int x, int y, int tileNumber);
            
        private:

            /**
             * Given a valid tile number, this method will return
             * a rectangle that describes this tile's location
             * within the texture
             * @param  tileNumber The tile number
             * @return            A rectangle describing it's coordinates
             */
            const Rectangle<int>& getTileRect(int tileNumber);

        };
    }
}

#endif
