INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin

CXX = g++
CXXFLAG = -I $(INCDIR)
TARGET = $(BINDIR)/pl0

_OBJS = main.o laxical_analyzer.o token.o

OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJS))

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CXX) -g -o $@ $(OBJS)

$(OBJDIR)/%.o:$(SRCDIR)/%.cc
	$(CXX) -g -c -o $@ $< $(CXXFLAG)
.PHNOY:clean
clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*