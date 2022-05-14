#include "defines.hpp"
#include "utilities.hpp"

clipboardxx::clipboard cb;

int main(int argc, char *argv[]) {
    handle_arguments(argc, argv);

    title_ascii();

    printf("\n- PSEUDO-COMPILER ---------------------------\n");
    printf("https://github.com/st3ph4nnn/pseudolang\n");
    printf("Versiunea curenta: 1.2\n");
    printf("Ultima versiune disponibila: https://bit.ly/3L0QyXD\n\n");

    printf("Traduc fisierul: %s\n", argv[1]);
    if (arguments::compile)
        printf("In executabilul: %s\n", argv[3]);

    printf("\nCopiaza in clipboard (-c): %s\n", arguments::copy == 0 ? "NU" : "DA");
    printf("Arata rezultatul (-i): %s\n", arguments::info == 0 ? "NU" : "DA");
    printf("Compileaza (-o {fisier.exe}): %s\n", arguments::compile == 0 ? "NU" : "DA");
    printf("Locatia rezultatului: %s (-t {fisier.cpp}):\n", arguments::write_file.c_str());

    printf("\n- LOGS --------------------------------------\n");

    std::ifstream file;
    if (!open_source_file(argv[1], file)) return 0;

    std::ofstream out;
    if (!open_write_file(arguments::write_file.c_str(), out)) return 0;

    translate(file, out);

    std::stringstream output;

    std::ifstream outr(arguments::write_file);

    if (arguments::info) {
        printf("\n- OUTPUT ------------------------------------\n");

        printf("\nAm reusit sa traducem fisierul: %s\nRezultat:\n\n", argv[1]);

        output << outr.rdbuf();
        printf("%s\n\n", output.str().c_str());
    }

    if (arguments::copy) {
        output.clear();
        output << outr.rdbuf();
        std::string f = output.str();
        cb.copy(f);
        printf("Am copiat rezultatul in clipboard.\n");
    }

    outr.close();
    file.close();

    if (arguments::compile) {
        printf("\n- COMPILE -----------------------------------\n\n");
        printf("[ATENTIE] Unele erori sunt semnalate de translatorul nostru, dar nu TOATE.\n\n");
        compile(arguments::write_file.c_str(), arguments::output_file.c_str());
    }

    return 0;
}