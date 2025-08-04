CC=gcc


# Source files
SRCFILES=admin.c user.c main.c 

# Header files
HEADERS=datatype.h admin.h user.h  

TARGET=main

$(TARGET): $(SRCFILES) $(HEADERS) 
	$(CC) -o $(TARGET) $(SRCFILES)

