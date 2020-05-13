#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H
#include "StringUtils.h"
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <cassert>
#include "Table.h"

class ControlPanel
{
public:
	ControlPanel();
	~ControlPanel();

	void start();

private:
	Table* table;
	std::string file;

	const std::map<std::string, std::function<void(void)>>  functions = {
		{ "save", std::bind(&ControlPanel::save, this)},
		{ "print", std::bind(&ControlPanel::print, this)},
		{ "help", std::bind(&ControlPanel::help, this)},
		{ "close", std::bind(&ControlPanel::close, this)},
		{ "exit", std::bind(&ControlPanel::exit, this)}
	};

	void help() const;
	void exit();
	void close();
	void print() const;
	void open(const std::string&);
	void readFile(const std::string&);
	void populateTable(const std::string&, char);
	void save();
	void saveAs(const std::string&);
	bool validateFile(const std::string&);
	void edit(const std::string&);
	void executeCommand(std::string&);

};


#endif