# Definirea variabilelor
CXX = g++
CXXFLAGS = -std=c++11
SRC = main.cpp src/employee.cpp src/operator.cpp src/assistant.cpp src/manager.cpp src/tests.cpp src/product.cpp src/clothes.cpp src/vintage_disk.cpp src/disk.cpp src/order.cpp src/stock_gestion.cpp src/employees_gestion.cpp src/requests.cpp src/reports.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

# Ținta implicită
all: $(EXEC)

# Cum să se construiască executabilul
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Cum să se construiască fișierele obiect
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Curățarea fișierelor intermediare și a executabilului
clean:
	rm -f $(OBJ) $(EXEC)

# Ținta care face atât compilare, cât și curățare
run: clean all
	./$(EXEC)
