//
// Created by pavel on 23.03.17.
//

#ifndef ALGORITHMS_GRAPHEXCEPTION_H
#define ALGORITHMS_GRAPHEXCEPTION_H

#include "base.h"

namespace algorithms {

    namespace exceptions {

        class GraphException: public Exception
        {
        public:
            GraphException(const char* message): Exception(message){}
        };

    }

}

#endif //ALGORITHMS_GRAPHEXCEPTION_H
