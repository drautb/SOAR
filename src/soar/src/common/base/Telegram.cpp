#include <iostream>

#include <base/Telegram.h>

using namespace std;
using namespace SOAR;
using namespace Base;

Telegram::Telegram(int senderId, int receiverId, int message,
                   double dispatchTime, void* extraInfo):
                   senderId(senderId),
                   receiverId(receiverId),
                   message(message),
                   dispatchTime(dispatchTime),
                   extraInfo(extraInfo)
{

}

Telegram::~Telegram()
{

}
