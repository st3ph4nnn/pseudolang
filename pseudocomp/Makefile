default:
ifeq ($(OS),LINUX)
	g++ ./main.cpp -o ./build/pseudocomp-LINUX -w -lxcb
	chmod +x ./build/pseudocomp-LINUX
else
	g++ ./main.cpp -o ./build/pseudocomp.exe -w
endif
