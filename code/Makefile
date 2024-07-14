CC := g++
CFLAG := -Wall
STD := c++17

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := simulation_base
EXECUTABLE  := main.exe

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
#	$(CC) -std=$(STD) $(CFLAG) -I $(INCLUDE) $^ -o $@ $(LIBRARIES)
	$(CC) -std=$(STD) $(CFLAG) -I./$(INCLUDE) $^ -o $@ -L./$(INCLUDE)/lib/ -l$(LIBRARIES)
run : $(BIN)/$(EXECUTABLE)
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/$(EXECUTABLE)
# 	-rm output.dat
#	-rm drag_coefficient.dat


#$(TARGET) : $(OBJ)
#	$(CC) -o $(TARGET).exe $(OBJ) $(CFLAG) -std=$(STD)
	
#%.o: %.cpp
#	$(CC) -c $^ -o $@ $(CFLAG) -std=$(STD)

