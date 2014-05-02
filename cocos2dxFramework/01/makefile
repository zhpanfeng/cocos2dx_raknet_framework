BIN := server 
Srcdir = -I /usr/local/include/raknet
CFLAGS := -g -static -Wall 
CC := g++ 
#vpath %.h /D/RakNet/Source
#VPATH = /D/RakNet/Source
SRCFILE := $(wildcard *.cpp) 
OBJFILE := $(patsubst %.cpp,%.o,$(SRCFILE))

$(BIN): $(OBJFILE) 
	$(CC) $(CFLAGS) $(Srcdir) -o $(BIN) $(OBJFILE) 
    
%.o:%.cpp
	$(CC) $(CFLAGS) $(Srcdir)  -c $< -o $@



clean :  
	rm -rf $(OBJFILE) ${BIN}
