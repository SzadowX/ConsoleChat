#pragma once
#include <iostream>

class iUser{
public:
	virtual void Show() = 0; 
	virtual ~iUser() = default;
};
