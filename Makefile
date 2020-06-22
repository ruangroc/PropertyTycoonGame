CC = g++
exe_file = tycoon
$(exe_file): driver.o Apartment.o Business.o Game.o House.o Property.o helper.o
	$(CC) driver.o Apartment.o Business.o Game.o House.o Property.o helper.o                    -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
Apartment.o: Apartment.cpp
	$(CC) -c Apartment.cpp
Business.o: Business.cpp
	$(CC) -c Business.cpp
Game.o: Game.cpp
	$(CC) -c Game.cpp
House.o: House.cpp
	$(CC) -c House.cpp
Property.o: Property.cpp
	$(CC) -c Property.cpp
helper.o: helper.cpp
	$(CC) -c helper.cpp
clean:
	rm -rf *.out *.o $(exe_file)
