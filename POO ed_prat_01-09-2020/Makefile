All: Agenda.o Horario.o Data.o main.o
	g++ Agenda.o Horario.o Data.o main.o -o agenda

Horario.o: Horario.cpp Horario.h
	g++ Horario.cpp -c

Data.o: Data.cpp Data.h
	g++ Data.cpp -c

Agenda.o: Agenda.cpp Agenda.h Horario.h Data.h
	g++ Agenda.cpp -c

main.o: main.cpp Agenda.h
	g++ main.cpp -c