#include "Signal.h"
#include <iostream>
#include <string>

Signal::Signal()
{
}

Signal::~Signal()
{
}


Signal::Signal(string name, real_T* addr)
{
	this->name = name;
	this->addr = addr;
	vec.clear();
}


void Signal::addValue()
{
	vec.push_back(*addr);
}

void Signal::printName(ostream& o)
{
	o << "\t" << name;
}

void Signal::print(ostream& o)
{
	o << "\t" << *addr;
}

void Signal::print(ostream& o, vector<real_T>::size_type index)
{
		o << "\t" << vec.at(index);
}

void Signal::printAll(ostream& o)
{
	for (auto const& value : vec)
	{
		o << "\t" << value;
	}

}