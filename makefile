BUILDDIR = ./build
BUILDTARGET = hmlog

build: $(BUILDDIR)/hmlog.o $(BUILDDIR)/hmlogCommands.o
	mkdir -p $(BUILDDIR)
	$(CXX) $(BUILDDIR)/hmlog.o $(BUILDDIR)/hmlogCommands.o -o $(BUILDDIR)/$(BUILDTARGET)

$(BUILDDIR)/hmlog.o: hmlog.cpp
	mkdir -p $(BUILDDIR)
	$(CXX) -c hmlog.cpp -o $(BUILDDIR)/hmlog.o

$(BUILDDIR)/hmlogCommands.o: hmlogCommands.cpp
	mkdir -p $(BUILDDIR)
	$(CXX) -c hmlogCommands.cpp -o $(BUILDDIR)/hmlogCommands.o

clean: 
	rm -rf $(BUILDDIR)

INSTALLDIR = /usr/bin/

install: $(BUILDDIR)/hmlog
	install -d $(INSTALLDIR)
	install $(BUILDDIR)/$(BUILDTARGET) $(INSTALLDIR)hmlog
