All: Circulo.o FigBase.o Retangulo.o Segmento.o TesteFiguras3.o 
	g++ Circulo.o FigBase.o Retangulo.o Segmento.o TesteFiguras3.o -o testeFig

FigBase.o: FigBase.h FigBase.cpp
	g++ FigBase.cpp -c

Circulo.o: FigBase.h Circulo.h Circulo.cpp
	g++ Circulo.cpp -c

Retangulo.o: FigBase.h Retangulo.h Retangulo.cpp
	g++ Retangulo.cpp -c

Segmento.o: FigBase.h Segmento.h Segmento.cpp
	g++ Segmento.cpp -c