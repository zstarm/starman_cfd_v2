CC := g++
CFLAG := -Wall
STD := c++17

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := simulation
EXECUTABLE  := main.exe

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CC) -std=$(STD) $(CFLAG) -I./$(INCLUDE) $^ -o $@ -L./$(INCLUDE)/lib/ -l$(LIBRARIES)

run : $(BIN)/$(EXECUTABLE)
	clear
	./$(BIN)/$(EXECUTABLE)

run\ v : $(BIN)/$(EXECUTABLE)
	clear
	./$(BIN)/$(EXECUTABLE) -v true

run\ l :
	./$(BIN)/$(EXECUTABLE) -v true | cat > log.txt

clean:
	-rm $(BIN)/$(EXECUTABLE) log.txt 
