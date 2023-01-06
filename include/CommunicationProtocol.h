#pragma once

#include <stdint.h>

using ProtocolMTI = uint8_t; // Protocol Message Type Identifier

namespace CommunicationProtocol
{
    static constexpr ProtocolMTI EnableFlashMessageMTI = 0x01;
    static constexpr ProtocolMTI TiltMotorAngleMessageMTI = 0x02;
}