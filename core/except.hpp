//
// Created by lengyel on 2018.10.24..
//

#ifndef CPX_EXCEPT_HPP
#define CPX_EXCEPT_HPP
#include <cerrno>
#include <cstring>
#include <string>
#include <stdexcept>
#include "rules.hpp"

#define CPX_DECLARE_EXCEPT(name, base)\
class name : public base { public: explicit name(const std::string& msg); }
#define CPX_DEFINE_EXCEPT(name, base)\
name :: name(const std::string& msg) : base(msg){}


namespace cpx{
    template<typename T>
    CPX_NO_RETURN void throwErrno(int no = errno){
        throw T(std::strerror(no));
    }

    template<typename T>
    void throwErrnoIfNeed(int no = errno){
        if(no != 0)
            throwErrno<T>(no);
    }

    CPX_DECLARE_EXCEPT(network_error, std::runtime_error);
    CPX_DECLARE_EXCEPT(timeout, std::runtime_error);

    CPX_DECLARE_EXCEPT(syntax_error, std::invalid_argument);
}


#endif //CPX_EXCEPT_HPP
