#!/bin/make
SHELL=/bin/bash

#Define the virtual paths
vpath %.cpp src/
vpath %.hpp include/
vpath %.o obj/

#Set some paths to install the shared objects to
SO_INSTALL_PATH = /home/vincent/programs/libFiles
HEADER_INSTALL_PATH = /home/vincent/programs/headerFiles

#Set some of the compile options
CXX = g++
CXXFLAGS = -fPIC -g -Wall $(CINCLUDEDIRS)
LDLIBS = -ldl -lpthread
CINCLUDEDIRS = -Iinclude
c++SrcSuf = cpp

#Set the name of the program to be compiled
PROGRAM = example
VERSION = $(shell git describe --abbrev=0 --tags)

#Define Objects
MAINO = main.o
DFTO = DiscreteFourierAnalysis.o

#DefineSharedObject
SO_NAME = $(subst .o,.so,lib$(DFTO))
SO_NAME_W_VERSION = $(addsuffix .$(VERSION),$(SO_NAME))
SO_NAME_FULL=$(addprefix $(OBJDIR)/,$(SO_NAME_W_VERSION))

#Define the name of the header for the SO
HEADER_NAME = $(subst .o,.hpp,$(DFTO))

#Make the object list and prefix the object directory
OBJS = $(MAINO) $(DFTO)
OBJDIR = obj
OBJS_W_DIR = $(addprefix $(OBJDIR)/,$(OBJS))

.SUFFIXES: .$(c++SrcSuf)

all: $(OBJS_W_DIR) $(PROGRAM)

$(OBJS_W_DIR): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(PROGRAM): $(OBJS_W_DIR)
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $@

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean so
clean: 
	@echo "Cleaning..."
	@rm -f $(OBJDIR)/* $(PROGRAM) *~ src/*~ include/*~

so: $(HEADER_NAME)
	g++ -shared $(OBJDIR)/$(DFTO)  -o $(SO_NAME_FULL)
	cp $(SO_NAME_FULL) $(SO_INSTALL_PATH)
	ln -sf $(SO_INSTALL_PATH)/$(SO_NAME_W_VERSION) $(SO_INSTALL_PATH)/dft.so
	cp $^ $(HEADER_INSTALL_PATH)
