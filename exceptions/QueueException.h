#ifndef QUEUEEXCEPTION
#define QUEUEEXCEPTION

#include "base.h"

namespace algorithms {

namespace exceptions {

    class QueueException: public Exception
    {
    public:
        QueueException(const char* message): Exception(message){}
    };

}

}

#endif // QUEUEEXCEPTION

