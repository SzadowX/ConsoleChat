#pragma once
#include <iostream>
using namespace std;

class IUser
{
public:
    virtual void Show() = 0;
    virtual ~IUser() = default;
};