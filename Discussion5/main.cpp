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

class CommandProcessor {
public:
	CommandProcessor(CommandProcessor* aNext) : next(aNext) {}

	virtual bool recognizes(const std::string& aCommand)=0;
protected:
	CommandProcessor* next;
};

int main() {
	runTemplateExample();
	return 0;
}


/* Agenda:
 * Midterm Discussion
 * Parsing Strings as Commands
 * Chain of Responsibility + Factory Pattern
 */

class Command {
public:
	virtual void executeCommand(CommandQuery& aCommandQuery)=0;
};

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