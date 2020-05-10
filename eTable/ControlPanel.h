#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H
#include "StringUtils.h"
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <cassert>

class ControlPanel
{
public:
	std::string errorMsg;
	bool hasFile = false;


	void executeCommand(std::string command) {

		if (command.size() < 4)
			return;

		if (!hasFile) {
			if (command.size() >= 10 || command.substr(0, 5) == "open ") {
				std::string file = command.substr(5);
				if (isValidFileName(file)) {
					open(file);
					hasFile = true;
				}
			}
		}

		else if (commandsMap.find(command) != commandsMap.end())
			commandsMap.at(command)();


		else if (command.substr(0, 7) == "saveas ") {
			std::string file = command.substr(7);
			if (isValidFileName(file)) {
				saveTo(file);
			}
		}

		else if (command.substr(0, 7) == "edit ") {
			std::string args = command.substr(5);
			if (validateEdit(args)) {

			}


		}
	};

	bool validateEdit(std::string str) {
		int pos1 = -1, pos2 = -1;

		for (int i = 0; i < str.size() - 1; ++i) {
			if (str.at(i) == ' ')
				if (pos1 == -1)
					pos1 = i;
				else {
					pos2 = i;
					break;
				}
		}

		if (pos1 == -1 || pos2 == -1) {
			std::cout << "Invalid arguments for edit command! Command should be: edit <row> <col> <value>";
			return false;
		}

		std::string row = str.substr(0, pos1), col = str.substr(pos1 + 1, pos2 - pos1 - 1), value = str.substr(pos2 + 1);

		if (!(StringUtils::isInteger(row) && StringUtils::isInteger(col))) {
			std::cout << "Invalid row or column! Command should be: edit <row> <col> <value>" << std::endl;
			return false;
		}

		f(std::stoi(row), std::stoi(col), value);
	}

	bool isValidFileName(std::string file) {
		assert(file.size() >= 5);

		std::string extension = file.substr(file.size() - 4, 4);
		std::string forbiddenSymbols = "/\?%*:|\"<>.";

		if (extension != ".txt") {
			std::cout << "Invalid file extension! (Hint: File should be '.txt')" << std::endl;
			return false;
		}

		std::string name = file.substr(0, file.size() - 4);
		std::size_t badCharacters = name.find_first_of(forbiddenSymbols);

		if (badCharacters != std::string::npos) {
			errorMsg = "Invalid file name! (Hint: Check forbidden filename characters in Windows OS)";
			return false;
		}

		errorMsg = "";
		return true;
	};

	void start() {
		std::string userInput;
		std::cout << "Open a text file (.txt) to read: (open <file>.txt)" << std::endl;

		while (true) {
			std::getline(std::cin, userInput);
			StringUtils::trim(userInput);
			executeCommand(userInput);
		};
	}

	void open(std::string) {

	};

	void init() {


	};

	void saveTo(std::string file) {


	}

	void f(int, int, std::string);


	void reset();

	void save() {
		writeFile("");
		std::cout << "Changes successfully saved!" << std::endl;
	};



	void close() {
		reset();
		init();
	};

	void saveAs(std::string) {
		writeFile("");
		std::cout << "Changes successfully saved in new file!" << std::endl;
	};

	void help() {
		std::cout << "open <file>                  opens <file>\n"
			<< "close                        closes currently opened file\n"
			<< "save                         saves the currently open file\n"
			<< "saveas <file>                saves the currently open file in <file>\n"
			<< "help                         prints this information\n"
			<< "print                        print the current table\n"
			<< "edit <row> <col> <value>     print the current table\n"
			<< "exit                         exists the program" << std::endl;

	};

	void writeFile(std::string);

	void print();

	void edit();

	void exit() {
		std::exit(0);
	}

	std::map<std::string, std::function<void(void)>>  commandsMap = {
	   { "save", std::bind(&ControlPanel::save, this)},
	   { "print", std::bind(&ControlPanel::print, this)},
	   { "help", std::bind(&ControlPanel::help, this)},
	   { "close", std::bind(&ControlPanel::close, this)},
	   { "exit", std::bind(&ControlPanel::exit, this)}
	};

};


#endif