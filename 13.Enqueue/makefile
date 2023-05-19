#OBJS specifies which files to compile as part of the project
OBJS= main.cpp

#CC specifies which compiler we're using
CC= g++

#INCLUDE_PATH specifies included directory path
INCLUDE_PATH= -I/usr/include/SDL2

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS= -w -g

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS= -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME= ./a.out

#This is the target that compiles our executable
all: $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATH) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: $(OBJ_NAME)
	./$(OBJ_NAME)	
