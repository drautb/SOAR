#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace SOAR
{
	namespace Math
	{
		/**
		 * A two dimensional flat rectangle in a flat coordinate system.
		 */
		class Rectangle
		{
		public: 

			/**
			 * The top left corner of this rectangle
			 */ 
			float x, y;

			/**
			 * Size of this rectangle.
			 */
			float width, height;

			/**
			 * Basic constructor
			 */
			Rectangle(float _x, float _y, float _width, float _height):
				x(_x), y(_y), width(_width), height(_height)
			{}

			/**
			 * Destructor
			 */
			~Rectangle()
			{}

			/**
			 * Determines if this rectangle intersects other
			 */
			bool intersects(Rectangle const&other)const;

			/**
			 * Determines if this rectangle contains a certain point, including 
			 * the edges of this rectangle.
			 * @param px The X-coordinate of the point to test
			 * @param py The Y-coordinate of the point to test
			 * @return   True if this rectangle contains x,y, false otherwise.
			 */
			bool Contains(float px, float py)const;

		};
	}
}

#endif
