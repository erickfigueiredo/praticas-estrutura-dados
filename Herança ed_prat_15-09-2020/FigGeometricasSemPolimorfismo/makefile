Bll: B.o FigBase.o Circulo.o Retangulo.o Segmento.o 
	g++ B.o FigBase.o Circulo\.o Retangulo.o Segmento.o -o teste

FigBase.o: FigBase.h FigBase.cpp
	g++ FigBase.cpp -c

Circulo.o: FigBase.h Circulo.h Circulo.cpp
	g++ Circulo.cpp -c

Retangulo.o: FigBase.h Retangulo.h Retangulo.cpp
	g++ Retangulo.cpp -c

Segmento.o: FigBase.h Segmento.h Segmento.cpp
	g++ Segmento.cpp -c

B.o: B.cpp Circulo.h Retangulo.h Segmento.h 
	g++ B.cpp -c
