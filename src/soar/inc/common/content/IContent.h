#ifndef I_CONTENT_H
#define I_CONTENT_H

namespace SOAR
{
    namespace Content
    {
        class IContent
        {
        public:
            virtual ~IContent(){}

            virtual bool LoadFile(const char* filename)=0;
            virtual bool LoadRaw(const unsigned char* data, int size)=0;
            virtual bool Release()=0;       
        };
    }
}

#endif