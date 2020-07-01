#include "SimConfig.h"
#include <fstream>
#include <regex>
//#include <boost/algorithm/string.hpp>
//#include <algorithm>
//#include <cctype>
//using namespace boost;


SimConfig::SimConfig()
{
	configMap.insert(make_pair("Setup", map<string, string>()));
	configMap.insert(make_pair("Input", map<string, string>()));
	configMap.insert(make_pair("Parameter", map<string, string>()));
}

void SimConfig::readConfig(string configFile)
{
	ifstream file(configFile);
	if (!file.is_open())
	{
		cout << "open file" << configFile << "has failed!" << endl;
		return;
	}
	string line;
	regex r("(\\w+)(\\s*=?\\s*)((\\-|\\+)?\\d+(\\.\\d+)?$)", regex::ECMAScript);
	cmatch results;
	string seg;
	while (getline(file, line))
	{
		trim(line);
		if ("" == line)continue;
		if ("[Include]" == line)
		{
			seg = "Include";
			cout << "Read " << seg << ":" << endl;
			continue;
		}
		else if ("[Setup]" == line)
		{
			seg = "Setup";
			cout << "Read " << seg << ":" << endl;
			continue;
		}
		else if ("[Input]" == line)
		{
			seg = "Input";
			cout << "Read " << seg << ":" << endl;
			continue;
		}
		else if ("[Parameter]" == line)
		{
			seg = "Parameter";
			cout << "Read " << seg << ":" << endl;
			continue;
		}
		if ("Include" == seg)
		{
			if (".maneuver" == line.substr(line.length() - 9))
			{
				maneuverFile = line;
				cout << "\t" << "maneuver file is " << line << endl;
			}
			if (".txt" == line.substr(line.length() - 4))
			{
				savelistFile = line;
				cout << "\t" << "savelist file is " << line << endl;
			}
		}
		else if ("Setup" == seg || "Input" == seg || "Parameter" == seg)
		{
			if (regex_search(line.c_str(), results, r))
			{
				configMap[seg].insert(make_pair(results.str(1), results.str(3)));
				cout << "\t"<< results.str(1) << " " << trim(results.str(2)) << " " << results.str(3) << endl;
			}
		}
	}
	file.close();
}
