# BinaryCommunicationProtocol

This code provides the bare-bone structure of a Binary Communication Protocol and a cool dispatcher that automatically enqueues messages on the right queue, based on the messsage identifier. This is the standard in robotics where we typically make two devices - for instance, an STM32 and a Jetson - communicate by following a Binary Communication Protocol.

# Build

Just create a build folder and call cmake, then make.