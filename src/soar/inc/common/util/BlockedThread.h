#ifndef BLOCKED_THREAD_H
#define BLOCKED_THREAD_H

namespace SOAR
{
    namespace Util
    {
        class BlockedThread
        {
        private:

            /**
             * Private constructor, can't be instantiated
             */
            BlockedThread();

        public:

            /**
             * Used to determine if this class can be used
             * to spawn a blocked thread on the current system.
             * @return True or False
             */
            static bool CanSpawn();

            /**
             * This method will launch a thread that runs 'command'
             * blocking the calling thread until execution has finished.
             * @param  command The command to execute. Can be system commands,
             *                 or an executable program.
             * @return         The return code of command
             */ 
            static int Spawn(const char* command);

        };
    }
}

#endif
