#include <iostream>

#include "EnableFlashMessage.h"

int main()
{
    EnableFlashMessage flash(true);
    std::cout << flash.data << std::endl;
}