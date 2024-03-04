#pragma once
#include <iostream>

class iUser{
public:
	virtual void Show() = 0; 
	virtual std::string userName() = 0;
	virtual ~iUser() = default;
};
