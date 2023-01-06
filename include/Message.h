#pragma once

#include <cstdint>
#include <cstdio>
#include <cstring>

class Message
{
public:
    Message() { };

    virtual void serialize(uint8_t* data) { };
    virtual void deserialize(uint8_t* data) { };
};