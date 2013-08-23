#ifndef CONTENT_MANAGER_H
#define CONTENT_MANAGER_H

#include <map>

#include "IContent.h"

using namespace std;

namespace SOAR
{
    namespace Content
    {
        class ContentManager
        {
        private:

            /**
             * This is the core of the manager. It maps user
             * supplied IDs to pointers to content.
             */
            map<int, IContent*>     contentIndex;

        private:
            /**
             * Private Constructor for Singleton
             * clears out content.
             */
            ContentManager();

        public:

            /**
             * Destructor, clears out all content
             */
            ~ContentManager();
        
            /**
             * Singleton Access Method
             */
            static ContentManager& GetInstance();
            
            /**
             * This method loads a new piece of content into the
             * manager. You must specify the type of content you 
             * are trying to load as a template parameter, and it
             * must implement the IContent interface.
             * @param  id       The ID to use to refer to this content
             * @param  filename The filename to load the content from
             * @return          True of the load was successful, false otherwise
             */
            template<typename T>
            bool Load(int id, const char* filename)
            {
                T* content = new T();
                contentIndex[id] = content;

                if (content->Load(filename))
                    return true;

                delete content;
                contentIndex[id] = nullptr;
                return false;
            }

            template<typename T>
            T* Handle(int id)
            {
                if (hasKey(id))
                    return contentIndex[id];
            }

        private:

            /**
             * This method releases all resources and then
             * clears the index.
             */
            void clear();

            /**
             * This method is used to determine if the manager 
             * has a piece of content attached to the given id
             * @param  id The key in question
             * @return    True if contentIndex[id] has something.
             */
            bool hasKey(int id);

        };
    }
}

#endif
