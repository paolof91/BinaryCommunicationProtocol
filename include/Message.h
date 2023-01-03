#include <stdint.h>
#include <stdio.h>

class Message
{
public:
    Message() { };

    virtual void std::serialize(uint8_t* data) = 0;
    virtual void deserialize(uint8_t* data) = 0;
}