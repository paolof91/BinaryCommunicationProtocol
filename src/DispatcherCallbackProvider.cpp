#pragma once

#include "DispatcherCallbackProvider.h"

DispatcherCallbackProvider::DispatcherCallbackProvider(std::unique_ptr<Message> sMessage,
                                                        std::unique_ptr<dispatcherCallback> sCallback)
    :
    message(std::move(sMessage)),
    callback(std::move(sCallback))
{
}

void DispatcherCallbackProvider::dispatch(uint8_t *messageBytes)
{
    message->deserialize(messageBytes);
    (*callback)(*message);
}