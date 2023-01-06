#include <iostream>
#include <queue>
#include <map>

#include "TiltMotorAngleMessage.h"
#include "Dispatcher.h"
#include "CommunicationProtocol.h"

int main()
{
    // Create queues that we are interested in
    std::queue<TiltMotorAngleMessage> tiltQueue;

    // Create the dispatcher map from MTIs to queue callbacks
    Dispatcher dispatcher;
    std::map<ProtocolMTI, std::unique_ptr<DispatcherCallbackProvider>> dispatcherMap;
    dispatcherMap[CommunicationProtocol::TiltMotorAngleMessageMTI] =
        dispatcher.createDeserializeOntoQueueCallback<TiltMotorAngleMessage>(&tiltQueue);

    // Create a message and serialize it
    TiltMotorAngleMessage tilt;
    tilt.data = 1.23;
    uint8_t messageBytes[8];
    tilt.serialize(messageBytes);
    ProtocolMTI mti = CommunicationProtocol::TiltMotorAngleMessageMTI;

    // Let it automatically be enqueued onto the right queue
    dispatcherMap.at(mti)->dispatch(messageBytes);

    // Show that the message indeed appears here
    std::cout << tiltQueue.front().data << std::endl;


    

    
}