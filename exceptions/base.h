#ifndef BASE
#define BASE

#include <exception>
#include "algorithms.h"

namespace algorithms {

namespace exceptions {

    class Exception: public std::exception
    {
    private:
        const char* message;

    public:
        Exception(const char* message)
        {
            this->message = message;
        }

        const char* what() const
        {
            return this->message;
        }
    };
}
}

#endif // BASE

