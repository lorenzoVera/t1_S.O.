# Nombre del compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Nombre del ejecutable
TARGET = program

# Archivos fuente
SOURCES = main.cpp operations.cpp

# Archivos objeto (se generarán a partir de los archivos fuente)
OBJECTS = $(SOURCES:.cpp=.o)

# Regla por defecto: compila el ejecutable
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Regla para compilar los archivos .cpp en archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) $(OBJECTS)

# Regla para forzar la recompilación
rebuild: clean all
