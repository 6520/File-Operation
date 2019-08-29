object=main.o FileOperation.o MatrixOperation.o MatrixConstruct.o MatrixComputation.o
a:$(object)
	g++ -o a $(object) -lmkl_rt
main.o:main.cpp 
	g++ -c main.cpp -lmkl_rt
FileOperation.o:FileOperation.cpp
	g++ -c FileOperation.cpp -lmkl_rt
MatrixOperation.o:MatrixOperation.cpp
	g++ -c MatrixOperation.cpp -lmkl_rt
MatrixConstruct.o:MatrixConstruct.cpp
	g++ -c MatrixConstruct.cpp -lmkl_rt
MatrixComputation.o:MatrixComputation.cpp
	g++ -c MatrixComputation.cpp -lmkl_rt
.PHONY:clean
clean:
	-rm a $(object)
