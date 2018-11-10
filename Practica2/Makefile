SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

# ************ Compilación de módulos ************
all: bin/test_ciudades bin/kciudades_cercanas

bin/test_ciudades: obj/test_ciudades.o obj/Posicion.o obj/Ciudad.o obj/Ciudades.o
	@g++ -o bin/test_ciudades obj/test_ciudades.o obj/Posicion.o obj/Ciudad.o obj/Ciudades.o
	@echo 'Generando test_ciudades'
bin/kciudades_cercanas: obj/kciudades_cercanas.o obj/Posicion.o obj/Ciudad.o obj/Ciudades.o
	@g++ -o bin/kciudades_cercanas obj/kciudades_cercanas.o obj/Posicion.o obj/Ciudad.o obj/Ciudades.o
	@echo 'Gerando kciudades_cercanas'
obj/Ciudades.o: src/Ciudades.cpp include/ciudades.h  include/VD.h include/Ciudad.h include/Posicion.h
	@g++ -c --std=c++11 src/Ciudades.cpp -o obj/Ciudades.o -Iinclude/
	@echo 'Objeto Ciudades listo'
obj/Ciudad.o: src/Ciudad.cpp include/Ciudad.h include/Posicion.h
	@g++ -c --std=c++11 src/Ciudad.cpp -o obj/Ciudad.o  -Iinclude/
	@echo 'Objeto Ciudad listo'
obj/Posicion.o: src/Posicion.cpp include/Posicion.h
	@g++ -c  --std=c++11 src/Posicion.cpp -o obj/Posicion.o -Iinclude/
	@echo 'Objeto Posicion listo'


obj/test_ciudades.o: src/test_ciudades.cpp include/Posicion.h include/ciudades.h
	@g++ -c  --std=c++11 src/test_ciudades.cpp -o obj/test_ciudades.o -Iinclude/
	@echo 'Objeto test_ciudades listo'
obj/kciudades_cercanas.o: src/kciudades_cercanas.cpp include/Posicion.h include/ciudades.h
	@g++ -c  --std=c++11 src/kciudades_cercanas.cpp -o obj/kciudades_cercanas.o -Iinclude/
	@echo 'Objeto kciudades_cercanas listo'
documentacion:
	doxygen doc/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
