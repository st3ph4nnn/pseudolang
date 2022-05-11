#pragma once
#include "defines.hpp"

bool handle_arguments(int argc, char *argv[]) {
    switch (argc) {
    case 1: {
        printf("[ERROR] Nici un argument nu a fost predat.\nUtilizare: pseudocomp (file.pseudo) (output.exe) (compile/trans)\n");
        return 0;
    }
    case 2: {
        printf("[ERROR] Executabilul nu a fost predat ca argument.\nUtilizare: pseudocomp (file.pseudo) (output.exe) (compile/trans)\n");
        return 0;
    }
    case 3: {
        printf("[ERROR] Vrei sa il transformi in cod C++ sau sa il compilezi?\nUtilizare: pseudocomp (file.pseudo) (output.exe) (compile/trans)\n");
        return 0;
    }
    }

    return 1;
}

bool open_source_file(const char *file_to_open, std::ifstream &file) {
    file.open(file_to_open);
    if (!file.is_open()) {
        printf("[ERROR] Nu am putut deschide fisierul: %s\n", file_to_open);
        return 0;
    }
    return 1;
}

bool open_write_file(const char *file_to_open, std::ofstream &file) {
    file.open(file_to_open);
    if (!file.is_open()) {
        printf("[FATAL ERROR] Nu am putut deschide fisierul: %s\n", file_to_open);
        return 0;
    }
    return 1;
}

std::string trim(const std::string &s) {
    size_t start = s.find_first_not_of(" \n\r\t\f\v");
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::vector<std::string> split(std::string s) {
    std::vector<std::string> str;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, ' ')) {
        trim(item);
        if (item == "") continue;
        str.push_back(item);
    }

    return str;
}

void translate(std::ifstream &file, std::ofstream &write_file) {
    printf("Traducerea are loc...\n");
    std::string line;
    while (std::getline(file, line)) {
        cuv = split(line);
        check(write_file);
    }

    write_file.close();
    file.close();
    printf("Traducerea a fost finalizata cu succes.\n");
}

void compile(const char *file, const char *out) {
    std::stringstream compile;
    compile << "g++ "
            << file
            << " -o " << out << " -w ";

    system(compile.str().c_str());
}