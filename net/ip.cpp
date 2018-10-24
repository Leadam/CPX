//
// Created by lengyel on 2018.10.13..
//

#include <arpa/inet.h>
#include "ip.hpp"
namespace cpx {
    namespace net {
        IpAddress::IpAddress(const char* address) {
            _addr = inet_addr(address);
        }

        IpAddress::IpAddress(const std::string &address) {
            _addr = inet_addr(address.c_str());
        }

        IpAddress::IpAddress(unsigned int address) : _addr(address){

        }

        IpAddress::IpAddress(char a, char b, char c, char d) {
            _octet[0] = a;
            _octet[1] = b;
            _octet[2] = c;
            _octet[3] = d;
        }

        char IpAddress::operator[](unsigned int idx)const{
            return _octet[idx];
        }
    }
}