BUILDDIR = ./build

hmlog: $(BUILDDIR)/hmlog.o $(BUILDDIR)/hmlogCommands.o
	$(CXX) $(BUILDDIR)/hmlog.o $(BUILDDIR)/hmlogCommands.o -o $(BUILDDIR)/hmlog

$(BUILDDIR)/hmlog.o: hmlog.cpp
	$(CXX) -c hmlog.cpp -o $(BUILDDIR)/hmlog.o

$(BUILDDIR)/hmlogCommands.o: hmlogCommands.cpp
	$(CXX) -c hmlogCommands.cpp -o $(BUILDDIR)/hmlogCommands.o

INSTALLDIR = /usr/bin/

install: $(BUILDDIR)/hmlog
	install -d $(INSTALLDIR)
	install $(BUILDDIR)/hmlog $(INSTALLDIR)hmlog
