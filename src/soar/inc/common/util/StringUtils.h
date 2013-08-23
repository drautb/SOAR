#ifndef STRING_UTILS_H
#define STRING_UTILS_H

namespace SOAR
{
    namespace Util
    {
        class StringUtils
        {
        private:
            StringUtils();
        
        public:

            /**
             * This method create a copy of the string passed in,
             * and return a non-const char* to it. 
             * The char* returned DOES NEED TO BE FREE()'D TO PREVENT MEMORY LEAKS
             * @param  str The string to de-const-ify
             * @return     A pointer to the copied string, non-const
             */
            static char* RemoveConst(const char* str);

        };  
    }
}

#endif
