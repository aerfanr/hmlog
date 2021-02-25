# hmlog
hmlog (high level mlog) is a programming language with c-like syntax and generates mlog (Mindustry logic) code.

## Features
This is currently in early development stage. Here is a list of implemented features:
* pout commant (print and flush)
* some of basic mlog commands (read, write, draw, drawflush, getlink and set)

And here is a list of features to be implemented:

* basic mlog commands
* if statements
* while loops
* for loops
* functions
* module support

## Download
You can download Linux and Widnows executable versions from [releases page](https://github.com/aerfanr/hmlog/releases) in this repository.

## Building
To build on Linux, clone the repository:

```
git clone https://github.com/aerfanr/hmlog
```

Then run make to build the executable:

```
cd hmlog
make
```

Finally you can install the program with:

```
sudo make install
```

If you want to build on windows, you probably need to use MinGW for windows or WSL. But I have no idea how you could actually build the software.
