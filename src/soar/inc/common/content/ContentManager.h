#ifndef CONTENT_MANAGER_H
#define CONTENT_MANAGER_H

#include <map>

#include "IContent.h"

using namespace std;

#define CM SOAR::Content::ContentManager::GetInstance()

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
            bool LoadFile(int id, const char* filename)
            {
                T* content = createIndexEntry<T>(id);

                if (content->LoadFile(filename))
                    return true;

                destroyIndexEntry(id);
                return false;
            }

            /**
             * This method loads a new piece of content into the 
             * manager from a raw c array of data.
             * @param  id   The ID to use to refer to this content
             * @param  data The data array to load the content from
             * @return      True if the load was successful, flase otherwise.
             */
            template<typename T>
            bool LoadRaw(int id, const unsigned char* data, int size)
            {
                T* content = createIndexEntry<T>(id);

                if (content->LoadRaw(data, size))
                    return true;

                destroyIndexEntry(id);
                return false;
            }

            /**
             * This method returns a handle to a piece of content
             * @param  id The id of the content to get a handle for
             * @return    A handle to the content if id is valid, nullptr if not
             */
            template<typename T>
            T* Handle(int id)
            {
                if (hasKey(id))
                    return static_cast<T*>(contentIndex[id]);

                return nullptr;
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

            /**
             * This method takes care of putting a new entry in the index.
             * If an entry already exists, it destroys it properly.
             * @param  id The id of the new entry
             * @return    A pointer to the new entry's content
             */
            template <typename T>
            T* createIndexEntry(int id)
            {
                if (hasKey(id))
                    destroyIndexEntry(id);

                T* content = new T();
                contentIndex[id] = content;

                return content;
            }

            /**
             * This method properly destroys an entry in the index,
             * taking care to release the resources properly.
             * @param id The id of the content to destroy
             */
            void destroyIndexEntry(int id);

        };
    }
}

#endif
