#include "Message.h"

class TiltMotorAngleMessage : public Message
{
public:
    TiltMotorAngleMessage(float data);

    float data;

    void std::serialize(uint8_t* data) override;
    void deserialize(uint8_t* data) override;
}