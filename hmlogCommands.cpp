#include "hmlogCommands.hpp"

using namespace std;

// runMlog does nothing. just returns the exact string as compiled mlog.
string runMlog(vector<string> args) {
    string mlog;
    for (string s : args) {
        mlog += s + ' ';
    }
    mlog.push_back('\n');

    return mlog;
}

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

// sets "property" of "block" to given arguments
string control(vector<string> args) {
    string mlog;
    mlog += "control";
    for (string s : args) {
        mlog += ' ' + s;
    }
    mlog += '\n';

    return mlog;
}

// radar returns first enemey sorted by "sorting" in "order" order 
// from "turret" wich is "type1" and "type2" and "type3"
string radar(vector<string> args) {
    string turret = args[0];
    string type1 = args[1];
    string type2 = args[2];
    string type3 = args[3];
    string sorting = args[4];
    string order = args[5];

    string mlog;
    mlog += "radar " + type1 + ' ' + type2 + ' ' + type3 + ' ' + sorting + ' ' + turret + ' ' + order + " ASSIGNCON\n";

   return mlog; 
}

// returns "property" from "block" to ASSIGNCON
string sensor(vector<string> args) {
    string property = args[0];
    string block = args[1];

    string mlog;
    mlog = "sensor ASSIGNCON " + block + ' ' + property + '\n';

    return mlog;
}

// performs a single operation from type "type" on "parm1" and "parm2" and returns the result to ASSIGNCON
string op(vector<string> args) {
    string type = args[0];
    string parm1 = args[1];
    string parm2 = (args.size() >= 3) ? args[2] : "";

    string mlog;
    mlog = "op " + type + " ASSIGNCON " + parm1 + ' ' + parm2 + '\n';

    return mlog;
}

// end
string end(vector<string> args) {
    string mlog;
    mlog += "end\n";

    return mlog;
}

typedef string (*fnPtr)(vector<string>);

map<string, fnPtr> commandPtr = {
    {"runMlog", runMlog},
    {"pout", pout},
    {"read", read},
    {"write", write},
    {"draw", draw},
    {"drawFlush", drawFlush},
    {"getLink", getLink},
    {"control", control},
    {"set", set},
    {"radar", radar},
    {"sensor", sensor},
    {"op", op},
    {"end", end}
};
