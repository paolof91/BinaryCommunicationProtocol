#pragma once

#include "Message.h"

class EnableFlashMessage : public Message
{
public:
    EnableFlashMessage() { };

    bool data;

    void serialize(uint8_t* dataBytes) override {
        memcpy(dataBytes, (void*)&data, sizeof(bool));
    }

    void deserialize(uint8_t* dataBytes) override {
        memcpy((void*)&data, dataBytes, sizeof(bool));
    }
};