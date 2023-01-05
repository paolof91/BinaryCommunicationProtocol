#include <stdint.h>
#include <stdio.h>
#include <string.h>

class Message
{
public:
    Message() { };

    virtual void serialize(uint8_t* data) { };
    virtual void deserialize(uint8_t* data) { };
};