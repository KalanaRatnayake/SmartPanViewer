#include "settings.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <iostream>

settings::settings()
{
}

void settings::writeINI(int leftPort, int middlePort, int rightPort){
	boost::property_tree::ptree camPortSettings;
	
	try {
		camPortSettings.put("leftport", leftPort);
		camPortSettings.put("middleport", middlePort);
		camPortSettings.put("rightport", rightPort);

		write_ini("config.ini", camPortSettings);
	} catch ( const std::exception& e) {
		std::cout << e.what();
	}
}

int settings::readINI_left() {
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("config.ini", pt);
	return pt.get<int>("leftport");
}

int settings::readINI_middle() {
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("config.ini", pt);
	return pt.get<int>("middleport");
}

int settings::readINI_right() {
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("config.ini", pt);
	return pt.get<int>("rightport");
}

settings::~settings()
{
}
