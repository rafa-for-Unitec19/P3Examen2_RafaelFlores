salida: main.cpp Relacion.hpp Tupla.hpp
	g++ -o salida $^
	./salida

clean:
	rm -f salida core
