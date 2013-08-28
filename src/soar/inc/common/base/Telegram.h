#ifndef MESSAGE_H
#define MESSAGE_H

#include <cmath>
#include <iostream>

using namespace std;

namespace SOAR
{
    namespace Base
    {
        class Telegram
        {
        public:

            /**
             * The minimum time difference to distinguish between
             * otherwise identical messages
             */
            constexpr static double         TIME_EPSILON     = 0.1;

        public:

            /**
             * The entity id of the sender
             */
            int             senderId;

            /**
             * The entity id of the receiver
             */
            int             receiverId;

            /**
             * The message itself, just an integer
             */
            int             message;

            /**
             * The time that the message should be dispatched
             */
            double          dispatchTime;

            /**
             * A pointer to any extra info needed to hanlde this Telegram
             */
            void*           extraInfo;

        public:

            /**
             * Constructor just fills in fields
             */
            Telegram(int senderId=-1, int receiverId=-1, int message=-1, 
                    double dispatchTime=-1, void* extraInfo=nullptr);
            
            /**
             * Destructor
             */
            ~Telegram();

            /**
             * This method returns extraInfo casted to the template parameter type
             */
            template <typename T>
            T* ExtraInfo()
            {
                return static_cast<T*>(extraInfo);
            }
        };

        /**
         * Overloaded operators for comparisons and printing.
         *
         * For some reason, the compiler threw some "ambiguous operator"
         * errors when I tried to put the definitions in the cpp file...weird.
         */
        inline bool operator==(const Telegram& lhs, const Telegram& rhs)
        {
            return lhs.senderId == rhs.senderId &&
                   lhs.receiverId == rhs.receiverId &&
                   lhs.message == rhs.message &&
                   fabs(lhs.dispatchTime - rhs.dispatchTime) < Telegram::TIME_EPSILON;
        }

        inline bool operator<(const Telegram& lhs, const Telegram& rhs)
        {
            if (lhs == rhs)
                return false;

            return lhs.dispatchTime < rhs.dispatchTime;
        }

        inline ostream& operator<<(ostream& os, const Telegram& t)
        {
            os << "[SID: " << t.senderId << ", RID: " << t.receiverId << ", MSG: " << t.message
               << ", D.T.: " << t.dispatchTime << ", E.I.: " << t.extraInfo << "]";

            return os;
        }

    }
}

#endif
