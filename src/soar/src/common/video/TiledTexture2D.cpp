#include <math/Rectangle.h>
#include <video/Texture2D.h>
#include <video/TiledTexture2D.h>

using namespace SOAR;
using namespace Video;

TiledTexture2D::TiledTexture2D()
    :tileRect(0, 0, width, height)
{

}

TiledTexture2D::~TiledTexture2D()
{

}

void TiledTexture2D::SetRowColumnCount(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    tileWidth = width / cols;
    tileHeight = height / rows;

    lastValidTileNumber = (rows * cols) - 1;
}

void TiledTexture2D::RenderTile(int x, int y, int tileNumber)
{
    Render(x, y, getTileRect(tileNumber));
}

const Rectangle<int>& TiledTexture2D::getTileRect(int tileNumber)
{
    if (tileNumber > lastValidTileNumber)
        tileRect = {0, 0, width, height};
    else
    {
        tileRect = {
            (tileNumber % cols) * tileWidth,
            (tileNumber / cols) * tileHeight,
            tileWidth,
            tileHeight
        };
    }   

    return tileRect;
}
