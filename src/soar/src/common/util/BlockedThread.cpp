#include <cstdlib>

#include "BlockedThread.h"

using namespace SOAR;
using namespace Util;

BlockedThread::BlockedThread()
{

}

bool BlockedThread::CanSpawn()
{
    return std::system(0);
}

int BlockedThread::Spawn(const char* command)
{
    return std::system(command);
}
