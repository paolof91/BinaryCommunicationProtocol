#pragma once

#include "Message.h"

class TiltMotorAngleMessage : public Message
{
public:
    TiltMotorAngleMessage() { };

    float data;

    void serialize(uint8_t* data) override {
        memcpy(data, (void*)this, sizeof(TiltMotorAngleMessage));
    }

    void deserialize(uint8_t* data) override {
        memcpy((void*)this, data, sizeof(TiltMotorAngleMessage));
    }
};