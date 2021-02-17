#include <fstream>
#include <iostream>
#include <vector>

#include "hmlogCommands.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    // source file is in argv[1]
    // this creates a file input stream and reads the source code in hmlog from source file
    ifstream fin = ifstream(argv[1]); // file input stream

    // reads file character by character and pushes each command (seperated by ';') into "commands" vector
    vector<string> commands; // stores all commands from the source code
    char currentCharacter;
    string currentCommand; // holds currect command before pushing it to "commands"
    fin >> noskipws; // do not skip whitespaces
    bool qoute = false; // this indicates wheter currentCharacter is between qoutes or not (strings should only be in double qoutes.)
    while (fin >> currentCharacter) {
        if (currentCharacter == ';') {
            commands.push_back(currentCommand);
            currentCommand.clear();
        } else {
            // only push current character if it is not a whitespace or is betweean qoutes
            if (currentCharacter != ' ') {
                currentCommand.push_back(currentCharacter);
            } else if (qoute) {
                currentCommand.push_back(currentCharacter);
            }

            if (currentCharacter == '"') qoute = !qoute;
        }
    }

    // proccesses command one by one and calls apropriate function from "hmlogCommands.cpp"
    for (string command : commands) {
        string commandName;
        vector<string> args;

        // reads command name, breaks when reaches '('
        int i; // holds current character index
        for (i = 0; i < (int) command.size(); i++) {
            if (command[i] == '(') break;
            else commandName.push_back(command[i]);
        }

        // reads command arguments, pushes command when reaches ',' or ')', breaks when reaches ')'
        string currentArg;
        for (i++ ; i < (int) command.size(); i++) {
            if (command[i] == ')' || command[i] == ',') {
                args.push_back(currentArg);
                currentArg.clear();
            } else currentArg.push_back(command[i]);

            if (command[i] == ')') break;
        }

        // output file is in argv[2]
        ofstream fout = ofstream(argv[2]);

        if (commandPtr[commandName]) {
            fout << commandPtr[commandName](args) << endl;
        } else {
            cerr << "Command " << commandName << " not found. Terminating." << endl;
        }
    }

    return 0;
}
