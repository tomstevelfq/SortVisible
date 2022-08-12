CC=g++ -g
IDIR=-IC:\Users\tomst\Desktop\sfml\SFML-2.5.1\include
LDIR=-LC:\Users\tomst\Desktop\sfml\SFML-2.5.1\lib
LIB=-lsfml-graphics -lsfml-window -lsfml-system
RM=del -r -f
ofile= sort.o QuickSort.o BubbleSort.o SortVisible.o
target=sort.exe
lfile=$(IDIR) $(LDIR) $(LIB)
$(target):$(ofile)
	$(CC)  $(ofile) $(LDIR) $(LIB) -o $(target)
sort.o:sort.cpp
	$(CC) sort.cpp $(IDIR) -c -o sort.o
QuickSort.o:QuickSort.cpp
	$(CC) QuickSort.cpp $(IDIR) -c -o QuickSort.o
BubbleSort.o:BubbleSort.cpp
	$(CC) BubbleSort.cpp $(IDIR) -c -o BubbleSort.o
SortVisible.o:SortVisible.cpp
	$(CC) SortVisible.cpp $(IDIR) -c -o SortVisible.o
clean:
	$(RM) sort.exe $(ofile)
