#include <iostream>
#include <queue>
#include <map>

#include "TiltMotorAngleMessage.h"
#include "EnableFlashMessage.h"
#include "Dispatcher.h"
#include "CommunicationProtocol.h"

int main()
{
    // Create queues that we are interested in
    std::queue<TiltMotorAngleMessage> tiltQueue;
    std::queue<EnableFlashMessage> flashQueue;

    // Create the dispatcher map from MTIs to queue callbacks
    Dispatcher dispatcher;
    std::map<ProtocolMTI, std::unique_ptr<DispatcherCallbackProvider>> dispatcherMap;
    dispatcherMap[CommunicationProtocol::TiltMotorAngleMessageMTI] =
        dispatcher.createDeserializeOntoQueueCallback<TiltMotorAngleMessage>(&tiltQueue);
    dispatcherMap[CommunicationProtocol::EnableFlashMessageMTI] =
        dispatcher.createDeserializeOntoQueueCallback<EnableFlashMessage>(&flashQueue);

    // Create messages and serialize them
    TiltMotorAngleMessage tilt;
    tilt.data = 1.23;
    EnableFlashMessage flash;
    flash.data = true;
    uint8_t messageBytes__first[8];
    tilt.serialize(messageBytes__first);
    ProtocolMTI mti__first = CommunicationProtocol::TiltMotorAngleMessageMTI;
    uint8_t messageBytes__second[8];
    flash.serialize(messageBytes__second);
    ProtocolMTI mti__second = CommunicationProtocol::EnableFlashMessageMTI;

    // Let it automatically be enqueued onto the right queue
    dispatcherMap.at(mti__first)->dispatch(messageBytes__first);
    dispatcherMap.at(mti__second)->dispatch(messageBytes__second);

    // Show that the messages are indeed correctly dispatched
    std::cout << "Tilt queue: " << tiltQueue.front().data << std::endl;
    std::cout << "Flash queue: " << flashQueue.front().data << std::endl;

}