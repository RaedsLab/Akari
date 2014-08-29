Akari: Game.o Files.o Menu.o
	gcc Game.o Files.o Menu.o -o Akari

Game.o: Game.c
	gcc -c Game.c

Files.o: Files.c
	gcc -c Files.c

Menu.o: Menu.c
	gcc -c Menu.c

rm: 
	rm -fr Akari

execute:
	./Akari
