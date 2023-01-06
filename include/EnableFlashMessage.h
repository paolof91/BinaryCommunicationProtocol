#pragma once

#include "Message.h"

class EnableFlashMessage : public Message
{
public:
    EnableFlashMessage() { };

    float data;

    void serialize(uint8_t* data) override {
        memcpy(data, (void*)this, sizeof(EnableFlashMessage));
    }

    void deserialize(uint8_t* data) override {
        memcpy((void*)this, data, sizeof(EnableFlashMessage));
    }
};