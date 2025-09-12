#pragma once

#include <string>

class StatusAprovacao {
public:
    virtual std::string avaliarStatus() = 0;
    virtual ~StatusAprovacao() = default;
};