# hmlog
hmlog (high level mlog) is a programming language with c-like syntax and generates mlog (Mindustry logic) code.

## Features
This is currently in early development stage. Here is a list of implemented features:
* pout commant (print and flush)
* some of basic mlog commands (read and set)

And here is a list of features to be implemented:

* basic mlog commands
* if statements
* while loops
* for loops
* functions
* module support

## Usage
First, compile the compiler (I use g++ for this):

``` g++ hmlog.cpp -o hmlog ```

Then compile your hmlog code and copy contents of output file to a processor in Mindustry.

``` hmlog MyAwesomeAI.hmlog ```
