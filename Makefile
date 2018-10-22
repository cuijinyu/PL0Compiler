compiler:main.o laxical_analyzer.o token.o tag.o
	g++ main.o -o laxical_analyzer
laxical_analyzer.o:laxical_analyzer.h
	g++ -c laxical_analyzer.cc
token.o:token.h
	g++ -c token.cc
tag.o:tag.h
	g++ -c tag.h
main.o:main.cc
	g++ -c main.cc
.PHNOY:clean
clean:
	rm *.o
	rm -f laxical_analyzer