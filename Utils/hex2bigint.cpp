//
// Created by 钏茗喜 on 2022/10/5.
//
#include "hex2bigint.h"

BigInt FromHex(std::string str)
{
    BigInt ret = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        ret *= 16;
        if (str[i] >= '0' && str[i] <= '9')
            ret += str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            ret += (str[i] - 'a') + 10;
        else
            throw std::out_of_range(str);
    }
    return ret;
}