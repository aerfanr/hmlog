#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "hmlogCommands.cpp"

using namespace std;

// reads command string and returns command name and command arguments
pair<string, vector<string>> readCommand(string command) {
    string commandName;
    vector<string> arguments;

    // pushes characters to commandName, stops when reaches '('
    int i;
    for (i = 0; i < (int) command.size(); i++) {
        if (command[i] == '(') break; 
        commandName.push_back(command[i]);
    }

    // pushes charachers to arguments, pushes arguments when reaches ',' or ')', stops wher reaches ')'
    string currentArg;
    for (i++; i < (int) command.size(); i++) {
        if (command[i] == ',' || command[i] == ')') {
            arguments.push_back(currentArg);
            currentArg.clear();
        } else {
            currentArg.push_back(command[i]);
        }

        if (command[i] == ')') break;
    }

    return {commandName, arguments};
}

string compileCommand(string commandName, vector<string> arguments) {
    if (commandPtr[commandName]) {
        return commandPtr[commandName](arguments);
    } else {
        cout << commandName << " not found. Terminating.";
        return "";
    }
}

int main(int argc, char *argv[]) {
    // source file is in argv[1]
    // this creates a file input stream and reads the source code in hmlog from source file
    ifstream fin = ifstream(argv[1]); // file input stream

    // reads file character by character and pushes each command (seperated by ';') into "commands" vector
    vector<string> commands; // stores all commands from the source code
    char currentCharacter;
    string currentCommand; // holds currect command before pushing it to "commands"
    bool qoute = false; // this indicates wheter currentCharacter is between qoutes or not (strings should only be in double qoutes.)
    const vector<char> skipChars = {' ', '\n'};
    fin >> noskipws; // do not skip whitespaces
    while (fin >> currentCharacter) {
        if (currentCharacter == ';') {
            commands.push_back(currentCommand);
            currentCommand.clear();
        } else {
            // only push current character if it is not a whitespace or is betweean qoutes
            if (find(skipChars.begin(), skipChars.end(), currentCharacter) == skipChars.end()) {
                currentCommand.push_back(currentCharacter);
            } else if (qoute) {
                currentCommand.push_back(currentCharacter);
            }

            if (currentCharacter == '"') qoute = !qoute;
        }
    }
    // output file is in argv[2]
    ofstream fout = ofstream(argv[2]);

    // proccesses command one by one and calls apropriate function from "hmlogCommands.cpp"
    for (string command : commands) {

        // for each command, if the first '=' is before the first '(', compiles assignment, else compiles function call
        for (int i = 0; i < (int) command.size(); i++) {
            if (command[i] == '=') {
                // compiles the right part of the assignment like a normall call
                pair<string, vector<string>> commandPair = readCommand(command.substr(i + 1));
                string compiled = compileCommand(commandPair.first, commandPair.second);
                if (compiled.size()) fout << compiled;
                else return 1;

                // gets the variable name on the left of the assignment
                string assignName;
                for (int j = 0; j < i; j++) {
                    if (command[j] != ' ') {
                        assignName.push_back(command[j]);
                    }
                }

                // compiles set operation of the assignment. sets assignName to "ASSIGNCON".
                // "ASSIGNCON" is a temporary variable used for assignments.
                compiled = compileCommand("set", {assignName, "ASSIGNCON"});
                if (compiled.size()) fout << compiled;
                else return 1;

                break;
            } else if (command[i] == '(') {
                // reads the command and compiles it. then prints the result to the output file
                pair<string, vector<string>> commandPair = readCommand(command);
                string compiled = compileCommand(commandPair.first, commandPair.second);
                if (compiled.size()) fout << compiled;
                else return 1;

                break;
            }
        }
    }

    return 0;
}
