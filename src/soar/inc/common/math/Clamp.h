#ifndef CLAMP_H
#define CLAMP_H

namespace SOAR
{
    namespace Math
    {
        /**
         * A Class containing lots of static methods for clamping values
         */
        class Clamp
        {
        private:

            Clamp();

        public: 

            /**
             * This method clamps val to make sure it is between min and max, inclusive.
             * @param val The value to clamp
             * @param min The minimum acceptable value
             * @param max The maximum acceptable value
             */
            static void Int(int& val, int min, int max);

        };
    }
}

#endif
