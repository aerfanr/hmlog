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

// read reads data from "memoryCell" to "result"
string read(vector<string> args) {
    string memoryCell = args[0];
    string result = args[1];

    string mlog;
    mlog += "read " + result + " " + memoryCell + '\n';

    return mlog;
}

typedef string (*fnPtr)(vector<string>);

map<string, fnPtr> commandPtr = {
    {"pout", pout},
    {"read", read}
};
