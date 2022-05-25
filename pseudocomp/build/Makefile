default:
ifeq ($(OS),LINUX)
	g++ ../main.cpp -o ./pseudocomp -w -O2
	chmod +x ./pseudocomp
else
ifeq ($(DEV), 1) 
	x86_64-w64-mingw32-g++ ../main.cpp -o ./pseudocomp.exe -w -O2
else
	g++ ../main.cpp -o ./pseudocomp.exe -w -O2
endif
endif
