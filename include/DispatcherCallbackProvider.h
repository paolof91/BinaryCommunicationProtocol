#pragma once

#include <functional>
#include <memory>
#include "Message.h"

using dispatcherCallback = std::function<void(Message &message)>;

class DispatcherCallbackProvider
{
public:
    DispatcherCallbackProvider() = delete;
    DispatcherCallbackProvider(std::unique_ptr<Message> sMessage,
                                std::unique_ptr<dispatcherCallback> sCallback);
    void dispatch(uint8_t *messageBytes);

private:
    std::unique_ptr<Message> message;
    std::unique_ptr<dispatcherCallback> callback;
};