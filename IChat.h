#pragma once
#include <iostream>
using namespace std;

class IChat
{
public:
    virtual void Show() = 0;
    virtual ~IChat() = default;
};