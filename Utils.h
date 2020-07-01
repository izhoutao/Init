#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "Signal.h"
#include "SimConfig.h"
#include <functional> 
using namespace std;
typedef void (*fptrOperation)(void);
inline string& ltrim(string& str) {
	string::iterator p = find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(isspace)));
	str.erase(str.begin(), p);
	return str;
}

inline string& rtrim(string& str) {
	string::reverse_iterator p = find_if(str.rbegin(), str.rend(), not1(ptr_fun<int, int>(isspace)));
	str.erase(p.base(), str.end());
	return str;
}

inline string& trim(string& str) {
	ltrim(rtrim(str));
	return str;
}

class Utils {
public:
	Utils();
	Utils(SimConfig config);
	~Utils();
    //void readInputConfig();
	void readManeuverFile();
	void readSaveListFile();
	void saveSignalNames(ostream& o);
	void saveSignals(ostream& o);
	void execSimulation(fptrOperation fn, ostream& o);

public:
	map<string, real_T*> paramMap;
	map<string, Signal> signalMap;
	vector<string> signalNames;
	SimConfig config;
	vector<real_T> times;
	vector<Signal> inputSignals;
};



