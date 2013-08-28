#include <set>

#include <base/BaseEntity.h>
#include <base/EntityManager.h>
#include <base/Telegram.h>
#include <base/MessageDispatcher.h>
#include <time/Timer.h>
#include <util/Log.h>

using namespace std;
using namespace SOAR;
using namespace Base;
using namespace Time;
using namespace Util;

MessageDispatcher::MessageDispatcher()
{
    msgQueue.clear();
}

MessageDispatcher::~MessageDispatcher()
{
    msgQueue.clear();
}

MessageDispatcher& MessageDispatcher::GetInstance()
{
    static MessageDispatcher instance;

    return instance;
}

void MessageDispatcher::DispatchMsg(int senderId, int receiverId, int msg,
                                    double delay, void* extraInfo)
{
    BaseEntity* receiver = EM.GetById(receiverId);

    Telegram packet(senderId, receiverId, msg, GetTime() + delay, extraInfo);

    if (delay < 0.0)
        discharge(receiver, packet);
    else
        msgQueue.insert(packet);
}   

void MessageDispatcher::DispatchDelayedMessages()
{
    double currentTime = GetTime();

    while (msgQueue.begin()->dispatchTime < currentTime &&
           msgQueue.begin()->dispatchTime > 0.0)
    {
        Telegram packet = *msgQueue.begin();
        
        BaseEntity* receiver = EM.GetById(packet.receiverId);

        discharge(receiver, packet);

        msgQueue.erase(msgQueue.begin());
    }
}   

void MessageDispatcher::discharge(BaseEntity* receiver, const Telegram& msg)
{
    if (!receiver->HandleMessage(msg))
        SOAR_LOG_WARNING << "Message not handled: " << msg;
}                       

