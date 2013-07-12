#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace SOAR
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
	};

}

#endif
