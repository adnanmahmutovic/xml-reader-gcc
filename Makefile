# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I/opt/homebrew/Cellar/tinyxml2/10.0.0/include
LDFLAGS = -L/opt/homebrew/Cellar/tinyxml2/10.0.0/lib -ltinyxml2

# Targets
TARGET = xml_reader
SOURCES = xml_reader.cpp

# Rules
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(TARGET)
