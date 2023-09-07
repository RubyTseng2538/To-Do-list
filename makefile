CC = g++
CFLAGS = -Wall -g

# App: App.o MainFrame.o Task.o
# 	$(CC) $(CFLAGS) -0 App App.o MAinFrame.o Task.o

# App.o: App.cpp App.h MainFrame.h
# 	$(CC) $(CFLAGS) -c App.cpp

# MainFrame.o: MainFrame.cpp MainFrame.h Task.h
# 	$(CC) $(CFLAGS) -c MainFrame.cpp

main: main.o Task.o
	$(CC) $(CFLAGS) -o main main.o Task.o

main.o: main.cpp Task.h
	$(CC) $(CFLAGS) -c main.cpp

Task.o: Task.cpp Task.h
	$(CC) $(CFLAGS) -c Task.cpp

clean:
	-rm main.o task.o main
