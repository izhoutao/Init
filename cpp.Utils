#include "Utils.h"
#include<windows.h>
#include "ARJ21_init.h"                /* Model's header file */
#include <regex>
#define SIGNAL_MAP_ASSIGNMENT(STRUCT,KEY) signalMap[#KEY] = Signal(#KEY, &##STRUCT.##KEY)
#define PARAM_MAP_ASSIGNMENT_INPUT(STRUCT,KEY) paramMap[#KEY] =  &##STRUCT.##KEY
#define PARAM_MAP_ASSIGNMENT(KEY) paramMap[#KEY] = &##KEY

Utils::Utils(SimConfig config)
{
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, owe_lb);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, payload_lb);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, lw_tank_fuel_lb);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, rw_tank_fuel_lb);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, conf_weight);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, DotProduct1);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, DotProduct1_o);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, DotProduct1_g);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, SumofElements);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, SumofElements_g);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, SumofElements_d);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, IxxLbsInch2);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, IyyLbsInch2);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, IzzLbsInch2);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, IxzLbsInch2);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, IxyLbsInch2);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, IyzLbsInch2);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, WeightLb);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, fuel_lb);
	SIGNAL_MAP_ASSIGNMENT(ARJ21_init_B, Filter_Reset);

	PARAM_MAP_ASSIGNMENT_INPUT(ARJ21_init_U, FuelFlowLbSec);

	PARAM_MAP_ASSIGNMENT(Flight_InertiaSelect);
	PARAM_MAP_ASSIGNMENT(Flight_Trimming);
	PARAM_MAP_ASSIGNMENT(Flight_ixx);
	PARAM_MAP_ASSIGNMENT(Flight_ixz);
	PARAM_MAP_ASSIGNMENT(Flight_iyy);
	PARAM_MAP_ASSIGNMENT(Flight_izz);
	PARAM_MAP_ASSIGNMENT(Flight_lgdown);
	PARAM_MAP_ASSIGNMENT(Flight_lw_fuel);
	PARAM_MAP_ASSIGNMENT(Flight_rw_fuel);
	PARAM_MAP_ASSIGNMENT(Flight_weight);
	PARAM_MAP_ASSIGNMENT(Flight_xcg);
	PARAM_MAP_ASSIGNMENT(Flight_ycg);
	PARAM_MAP_ASSIGNMENT(Flight_zcg);



	this->config = config;
	try
	{
		for (auto& it : config.configMap["Setup"]) {
			*paramMap[it.first] = stof(it.second);
		}
		for (auto& it : config.configMap["Parameter"]) {
			*paramMap[it.first] = stof(it.second);
		}
		for (auto& it : config.configMap["Input"]) {
			*paramMap[it.first] = stof(it.second);
		}
	}
	catch (...)
	{
		cout << "config file error!";
	}

}
Utils::Utils()
{
}
Utils::~Utils()
{
}

void Utils::readManeuverFile()
{
	map<string, vector<real_T>> map;
	string maneuverFile = config.maneuverFile;
	ifstream file(maneuverFile);
	if (!file.is_open())
	{
		cout << "open file" << maneuverFile << "has failed!" << endl;
		return;
	}
	string line;
	regex ws_re("\\s+");
	bool isHead = true;
	while (getline(file, line))
	{
		trim(line);
		if ("" == line)continue;
		vector<string> vec(sregex_token_iterator(line.begin(), line.end(), ws_re, -1), sregex_token_iterator());
		if (isHead)
		{
			for (auto name : vec)
			{
				if ("T" == name) {
					continue;
				}
				auto iter = paramMap.find(name);
				if (iter != paramMap.end())
				{
					auto signal = Signal(name, iter->second);
					inputSignals.push_back(signal);
				}
			}
			isHead = false;
		}
		else
		{
			times.push_back(stof(vec[0]));
			for (size_t i = 0; i < inputSignals.size(); i++)
			{
				auto iter = paramMap.find(inputSignals[i].name);
				if (iter != paramMap.end())
				{
					auto temp = *iter->second;
					real_T val = stof(vec[i + 1]) + *iter->second;
					*inputSignals[i].addr = val;
					inputSignals[i].addValue();
					*iter->second = temp;
				}
			}
		}
	}
	file.close();
}




void Utils::readSaveListFile()
{
	string savelistFile = config.savelistFile;
	ifstream file(savelistFile);
	if (!file.is_open())
	{
		cout << "open file" << savelistFile << "has failed!" << endl;
		return;
	}
	string line;
	while (getline(file, line))
	{
		trim(line);
		map<string, Signal>::iterator iter = signalMap.find(line);
		if (iter != signalMap.end())
		{
			signalNames.push_back(line);
			//cout << iter->first << " : ";
			//iter->second.print(cout);
			//cout << endl;
		}
	}
	file.close();
}

void Utils::saveSignalNames(ostream& o)
{
	for (auto& signal : signalNames)
	{
		signalMap[signal].printName(o);
	}
	o << endl;
}

void Utils::saveSignals(ostream& o)
{

	for (auto signal : signalNames)
	{
		signalMap[signal].print(o);
	}
	o << endl;
}

void Utils::execSimulation(fptrOperation fn, ostream& o)
{
	for (size_t i = 0; i < times.size(); i++)
	{
		for (size_t j = 0; j < inputSignals.size(); j++)
		{
			*inputSignals[j].addr = inputSignals[j].vec[i];
			cout << *inputSignals[j].addr << endl;
		}
		fn();
		o << times[i];
		saveSignals(o);
	}

}

