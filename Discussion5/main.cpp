#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <functional>
#include <vector>

#include "Templates.hpp"

using std::cout,
	std::string,
	std::stringstream,
	std::map,
	std::function,
	std::vector;

class Number;
class Command;
class CommandQuery;

using Numbers = map<string, Number*>;
using CommandFactory = function<Command*(const string& aCommand)>;
using StringVector = vector<string>;

const string COMMAND_CREATE_1 = R"(CREATE NUMBER name="num1" type=complex VALUE a=1 b=1;)";
const string COMMAND_CREATE_2 = R"(CREATE NUMBER name="num2" type=real VALUE a=2;)";
const string COMMAND_ADD = R"(ADD STORE name="num3" NUMBER name="num1" NUMBER name="num2";)";
const string COMMAND_SHOW = R"(SHOW name="num3")";
const string COMMAND_QUIT = R"(QUIT;)";

// Creational Commands
class Command {
public:
    virtual void executeCommand(CommandQuery& aCommandQuery)=0;
};

class CreateCommand : public Command {
public:
    virtual void executeCommand(CommandQuery& aCommandQuery) {}
};
// Modification Commands

class CommandProcessor {
public:
	CommandProcessor(CommandProcessor* aNext) : next(aNext) {}

	virtual bool recognizes(const std::string& aCommand)=0;
protected:
	CommandProcessor* next;
};

// Tokenizer - parse strings/commands (tokens)
enum CommandTokens  {
        create, add, show, quit, unknown
};

Command* createCreateCommand(const string& aCommand) {
    return new CreateCommand();
}

CommandTokens getTokenForKey(string aKey) {
    static map<string, CommandTokens> tokenMap = {
            {"CREATE", CommandTokens::create},
    };
    if (tokenMap.find(aKey) == tokenMap.end()) {
        return CommandTokens::unknown;
    }
    return tokenMap[aKey];
}

// Factory pattern takes away flexibility from client => give the factory instructions
// Factory pattern does all the work
Command* dispatch(CommandTokens aToken, std::string& aCommand) {
    // Smaller Factory Pattern
    static map<CommandTokens, CommandFactory> commandMap = {
            {CommandTokens::create, createCreateCommand},
    };
    if (commandMap.find(aToken) == commandMap.end()) {
        return nullptr;
    }
    return commandMap[aToken](aCommand);
}

/*
 * Datadase (data)
 *  Change data
 *    delete data
 * UI (screen) shows the data
 *  move data on screen
 * Application : single input (terminal)
 */

int main() {
//	runTemplateExample();
    stringstream theStream(COMMAND_CREATE_1);
    string temp;
    while (theStream >> temp) {
        cout << temp << "\n";
    }
	return 0;
}


/* Agenda:
 * Midterm Discussion
 * 33% Written Quiz (MC, FRQ, Matching)
 * 33% Coding Part (Take code assignment 2 make changes || option if your class doesn't work
 *  {will provide additional class to modify})
*  34% "Interview" 10-15minutes TA or Prof will code review (Assignment 2 code review)
 *      Coding style (professionalism)
 *      Design
 * Parsing Strings as Commands
 * Chain of Responsibility + Factory Pattern
 */



class CommandQuery {
public:
	CommandQuery& executeCommand(Command& aCommand) {
		return *this;
	}

	void addCommand(const std::string& aCommand) {
		commands.push_back(aCommand);
	}

protected:
	StringVector commands;

	Numbers numbers;
};