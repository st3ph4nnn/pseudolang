default:
ifeq ($(OS),LINUX)
	g++ ./main.cpp -o ./build/pseudocomp -w -lxcb
	chmod +x ./build/pseudocomp
else
	g++ ./main.cpp -o ./build/pseudocomp.exe -w
endif
