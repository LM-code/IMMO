CC=gcc -Wall
CC_win=i586-mingw32msvc-gcc
GTK=`pkg-config --libs --cflags gtk+-2.0`
NOM_PROG_LINUX=immo.x
NOM_PROG_WIN=immo.exe

immo.x :  
	@echo "/**********************************/";
	@echo "/     Compilation du programme     /";
	@echo "/    Création des fichiers objet   /";
	@echo "/**********************************/\n";
	$(CC) $(GTK) -c  fenetre_principale.c  main.c ;
	@echo "/**********************************/";
	@echo "/    Linkage des fichiers objet    /";
	@echo "/   pour création de l'éxecutable  /";
	@echo "/**********************************/\n";
	$(CC) $(GTK) -o $(NOM_PROG_LINUX) fenetre_principale.o main.o;

clean :
	@echo "Efface les fichiers de compilation et d'éxécution";
	rm -f *.o *core* $(NOM_PROG_LINUX) $(NOM_PROG_WIN);
    
win :
	@echo "/**********************************/";
	@echo "/     Compilation du programme     /";
	@echo "/           pour windows           /";
	@echo "/**********************************/\n";
	export PKG_CONFIG_PATH=/home/laurent/gtk_win32/lib/pkgconfig;$(CC_win) *.c -o $(NOM_PROG_WIN) $(GTK) -lm
