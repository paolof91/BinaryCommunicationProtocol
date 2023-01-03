#include "Message.h"

class EnableFlashMessage : public Message
{
public:
    EnableFlashMessage(bool data);

    bool data;

    void std::serialize(uint8_t* data) override;
    void deserialize(uint8_t* data) override;
}