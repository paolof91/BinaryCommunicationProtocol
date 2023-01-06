#pragma once

#include <queue>

#include "DispatcherCallbackProvider.h"

class Dispatcher
{
public:
    Dispatcher() { };

    template <class MessageType>
    std::unique_ptr<DispatcherCallbackProvider> createDeserializeOntoQueueCallback(std::queue<MessageType>* queue)
    {
        std::unique_ptr<MessageType> message = std::make_unique<MessageType>();
        std::unique_ptr<dispatcherCallback> callback = std::make_unique<dispatcherCallback>( [queue] (Message &baseMessage) -> void
        {
            MessageType &specificMessage = dynamic_cast<MessageType&>(baseMessage);
            queue->push(specificMessage);
        });

        return std::make_unique<DispatcherCallbackProvider>(std::move(message), std::move(callback));
    }
};
