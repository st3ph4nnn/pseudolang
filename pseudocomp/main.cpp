#include "defines.hpp"
#include "utilities.hpp"

int main(int argc, char *argv[]) {
    if (!handle_arguments(argc, argv))
        return 0;

    printf("\n- PSEUDO-COMPILER ---------------------------\n");
    printf("[ATENTIE] Erorile pe fisierele de cod pseudolang vor fi atentionate de g++.\n\n");
    printf("Traduc fisierul: %s\n", argv[1]);
    printf("In executabilul: %s\n", argv[2]);

    printf("\n- OUTPUT ------------------------------------\n");

    std::ifstream file;
    if (!open_source_file(argv[1], file)) return 0;

    std::ofstream out;
    if (!open_write_file("trans.cpp", out)) return 0;

    translate(file, out);

    if (!strcmp(argv[3], "compile"))
        compile("trans.cpp", argv[2], true);

    return 0;
}