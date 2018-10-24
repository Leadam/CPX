//
// Created by lengyel on 2018.10.13..
//

#ifndef CPX_IP_HPP
#define CPX_IP_HPP
#include <string>

namespace cpx {
    namespace net {
        class IpAddress {
        private:
            union{
                char _octet[4];
                unsigned int _addr;
            };

        public:
            IpAddress() = default;

            IpAddress(const char* address); //NOLINT

            IpAddress(const std::string &address); //NOLINT

            explicit IpAddress(unsigned int address);

            IpAddress(char a, char b, char c, char d);

            char operator[](unsigned int idx)const;
        };
    }
}
#endif //CPX_IP_HPP
