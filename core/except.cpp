//
// Created by lengyel on 2018.10.24..
//

#include "except.hpp"

namespace cpx{

    CPX_DEFINE_EXCEPT(network_error, std::runtime_error);
    CPX_DEFINE_EXCEPT(timeout, std::runtime_error);

    CPX_DEFINE_EXCEPT(syntax_error, std::invalid_argument);
}