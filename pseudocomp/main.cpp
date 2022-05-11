#include "defines.hpp"
#include "utilities.hpp"

int main(int argc, char *argv[]) {
    bool compilez = false;

    if (!handle_arguments(argc, argv))
        return 0;

    printf("\n- PSEUDO-COMPILER ---------------------------\n");
    printf("https://github.com/st3ph4nnn/pseudolang\n");
    printf("Versiunea curenta: 1.1\n");
    printf("Ultima versiune disponibila: https://bit.ly/3L0QyXD\n\n");

    printf("[ATENTIE] Unele erori sunt semnalate de translatorul nostru, dar nu TOATE.\n\n");

    printf("Traduc fisierul: %s\n", argv[1]);
    if (!strcmp(argv[3], "compile")) {
        compilez = true;
        printf("In executabilul: %s\n", argv[2]);
    }

    printf("\n- OUTPUT ------------------------------------\n");

    std::ifstream file;
    if (!open_source_file(argv[1], file)) return 0;

    std::ofstream out;
    if (!open_write_file("trans.cpp", out)) return 0;

    translate(file, out);

    if (compilez)
        compile("trans.cpp", argv[2]);

    return 0;
}