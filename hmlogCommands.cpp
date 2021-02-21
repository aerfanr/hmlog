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
    mlog += "read ASSIGNCON " + memoryCell + ' ' + position + '\n';

    return mlog;
}

// write writes data "data" to "memoryCell" at "position"
string write(vector<string> args) {
    string memoryCell = args[0];
    string position = args[1];
    string data = args[2];

    string mlog;
    mlog += "write " + data + ' ' + memoryCell + ' ' + position + '\n';

    return mlog;
}

// sets a variable with name "variableName" to "value"
string set(vector<string> args) {
    string variableName = args[0];
    string value = args[1];

    string mlog;
    mlog += "set " + variableName + " " + value + '\n';

    return mlog;
}

// gets drawing type and creates aprotpriate draw command
string draw(vector<string> args) {
    string type = args[0];

    string mlog;
    mlog += "draw";
    for (string s : args) {
        mlog += ' ' + s;
    }
    mlog += '\n';

    return mlog;
}

// flushes draw buffer to "display"
string drawFlush(vector<string> args) {
    string display = args[0];

    string mlog;
    mlog += "drawflush " + display + '\n';

    return mlog;
}

// gets "n"th link and returns the result to ASSIGNCON
string getLink(vector<string> args) {
    string n = args[0];

    string mlog;
    mlog += "getlink ASSIGNCON " + n + '\n';

    return mlog;
}

typedef string (*fnPtr)(vector<string>);

map<string, fnPtr> commandPtr = {
    {"pout", pout},
    {"read", read},
    {"write", write},
    {"draw", draw},
    {"drawFlush", drawFlush},
    {"getLink", getLink},
    {"set", set}
};
