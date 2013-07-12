
#include "Rectangle.h"

using namespace SOAR;

bool Rectangle::intersects(Rectangle const&other)const
{
	// This basically checks to see if any of the four corners of other
	// are inside of this rectangle.
	if ((other.x > x && other.x < x + width && other.y > y && other.y < y + height) ||
		(other.x + other.width > x && other.x + other.width < x + width && other.y > y && other.y < y + height) ||
		(other.x + other.width > x && other.x + other.width < x + width && other.y + other.height > y && other.y + other.height < y + height) ||
		(other.x > x && other.x < x + width && other.y + other.height > y && other.y + other.height < y + height))
		return true;

	return false;
}