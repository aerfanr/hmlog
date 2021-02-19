#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// pout prints string "s" and flushes the print buffer to "messageBlock"
string pout(vector<string> args) {
    string s = args[0];
    string messageBlock = args[1];

    string mlog; // compiled command in mlog
    mlog += "print " + s + '\n';
    mlog += "printflush " + messageBlock + '\n';

    return mlog;
}

// read reads data from "memoryCell" at "position" to "ASSIGNCON"
string read(vector<string> args) {
    string memoryCell = args[0];
    string position = args[1];

    string mlog;
    mlog += "read ASSIGNCON " + memoryCell + " " + position + '\n';

    return mlog;
}

string set(vector<string> args) {
    string variableName = args[0];
    string value = args[1];

    string mlog;
    mlog += "set " + variableName + " " + value + '\n';

    return mlog;
}

typedef string (*fnPtr)(vector<string>);

map<string, fnPtr> commandPtr = {
    {"pout", pout},
    {"read", read},
    {"set", set}
};
