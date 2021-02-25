#ifndef HMLOG_COMMANDS_H
#define HMLOG_COMMANDS_H

#include <map>
#include <string>
#include <vector>

using namespace std;

string runMlog(vector<string> args);

string pout(vector<string> args);

string read(vector<string> args);
string write(vector<string> args);
string draw(vector<string> args);
string drawFlush(vector<string> args);
string getLink(vector<string> args);
string control(vector<string> args);
string set(vector<string> args);

typedef string (*fnPtr)(vector<string>);
extern map<string, fnPtr> commandPtr;

#endif
