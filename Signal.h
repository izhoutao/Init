#pragma once
#include "rtwtypes.h"
#include <string>
#include <vector>

using namespace std;
class Signal
{
public:
	Signal();
	~Signal();
	Signal(string name, real_T* addr);
public:
	string name;
	real_T* addr;
	vector<real_T> vec;
public:
	void addValue();
	void printName(ostream& o);
	void print(ostream& o);
	void print(ostream& o, vector<real_T>::size_type index);
	void printAll(ostream& o);
};
