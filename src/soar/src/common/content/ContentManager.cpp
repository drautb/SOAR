#include <map>

#include "ContentManager.h"

using namespace SOAR;
using namespace Content;

ContentManager::ContentManager()
{

}

ContentManager::~ContentManager()
{

}

ContentManager& ContentManager::GetInstance()
{
    static ContentManager instance;

    return instance;
}

void ContentManager::clear()
{
    for (unsigned int i=0; i<contentIndex.size(); i++)
    {
        contentIndex[i]->Release();
        delete contentIndex[i];
    }

    contentIndex.clear();
}

bool ContentManager::hasKey(int id)
{
    if (contentIndex.find(id) != contentIndex.end())
        return contentIndex[id] != nullptr;

    return false;
}
