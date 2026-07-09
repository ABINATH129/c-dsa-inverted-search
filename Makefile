Database.out :  Main.o General.o Create_Database.o Display_Database.o Save_Database.o Search_Word.o Update_Database.o
	gcc -o $@ $^
Main.o : Main.c Header.h
	gcc -c Main.c -o $@
Create_Database.o : Create_Database.c Header.h
	gcc -c Create_Database.c -o $@
Display_Database.o : Display_Database.c Header.h
	gcc -c Display_Database.c -o $@
Search_Word.o : Search_Word.c Header.h
	gcc -c Search_Word.c -o $@
Save_Database.o : Save_Database.c Header.h
	gcc -c Save_Database.c -o $@
Update_Database.o : Update_Database.c Header.h
	gcc -c Update_Database.c -o $@
General.o : General.c Header.h
	gcc -c General.c -o $@
clean:
	rm *.o *.out
