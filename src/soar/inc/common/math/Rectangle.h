#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace SOAR
{
	namespace Math
	{
		/**
		 * A two dimensional flat rectangle in a flat coordinate system.
		 */
		template <typename T>
		class Rectangle
		{
		public: 

			/**
			 * The top left corner of this rectangle
			 */ 
			T x, y;

			/**
			 * Size of this rectangle.
			 */
			T width, height;

			/**
			 * Basic constructor
			 */
			Rectangle(T _x, T _y, T _width, T _height):
				x(_x), y(_y), width(_width), height(_height)
			{

			}

			/**
			 * Destructor
			 */
			~Rectangle()
			{

			}

			/**
			 * Determines if this rectangle intersects other
			 */
			bool intersects(Rectangle const&other)const
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

			/**
			 * Determines if this rectangle contains a certain point, including 
			 * the edges of this rectangle.
			 * @param px The X-coordinate of the point to test
			 * @param py The Y-coordinate of the point to test
			 * @return   True if this rectangle contains x,y, false otherwise.
			 */
			bool Contains(T px, T py)const
			{
				if (px >= x && 
				    px <= (x + width) && 
				    py >= y && 
				    py <= (y + height))
				    return true;

				return false;
			}

		};
	}
}

#endif
