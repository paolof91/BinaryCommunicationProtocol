#pragma once

#include <iostream>
#include "Message.h"

class TiltMotorAngleMessage : public Message
{
public:
    TiltMotorAngleMessage() { };

    float data;

    void serialize(uint8_t* dataBytes) override {
        memcpy(dataBytes, (void*)&data, sizeof(float));
    }

    void deserialize(uint8_t* dataBytes) override {
        memcpy((void*)&data, dataBytes, sizeof(float));
    }
};