#include "EnableFlashMessage.h"

EnableFlashMessage::EnableFlashMessage(bool msgData)
{
    data = msgData;
}

void EnableFlashMessage::serialize(uint8_t* data)
{
    memcpy(data, (void*)this, sizeof(EnableFlashMessage));
}

void EnableFlashMessage::deserialize(uint8_t* data)
{
    memcpy((void*)this, data, sizeof(EnableFlashMessage));
}

