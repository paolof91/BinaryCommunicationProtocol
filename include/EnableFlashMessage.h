#pragma once

#include "Message.h"

class EnableFlashMessage : public Message
{
public:
    EnableFlashMessage() { };

    bool data;

    void serialize(uint8_t* dataBytes) override {
        std::memcpy(dataBytes, (void*)&data, sizeof(bool));
    }

    void deserialize(uint8_t* dataBytes) override {
        std::memcpy((void*)&data, dataBytes, sizeof(bool));
    }
};