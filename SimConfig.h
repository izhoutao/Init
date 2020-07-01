#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;
extern inline string& trim(string& str);
class SimConfig
{
public:
	SimConfig();
public:
	string maneuverFile;
	string savelistFile = "savelist.txt";
	map<string, map<string, string>> configMap;
public:
	void readConfig(string configFile);
};

