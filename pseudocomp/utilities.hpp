#pragma once
#include "defines.hpp"

namespace arguments {
    bool compile = false;
    std::string translate = " ";
    bool copy = false;
    std::string input_file;
    std::string output_file;
    bool info;
}

void handle_arguments(int argc, char *argv[]) {
    const std::vector<std::string> args(argv + 1, argv + argc);

    if (args.size() == 0)
        goto utilizare_incorecta;

    arguments::input_file = args[0];

    if (args.size() > 1) {
        for (int i = 1; i < args.size(); i++) {
            if (args[i] == "-o") {
                if (i + 1 > args.size() - 1)
                    goto utilizare_incorecta;

                arguments::compile = true;
                arguments::output_file = args[i + 1];
                i++;
                continue;
            }

            if (args[i] == "-c")
                arguments::copy = true;

            if (args[i] == "-i")
                arguments::info = true;
        }
    }

    return;

utilizare_incorecta:
    printf("\nUtilizare incorecta.\n");
    printf("Utilizare: pseudoc (fisier.pseudo) {args...}\n");
    printf("args: -o (output.exe); -c, -s\n\n");
    exit(0);
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

    printf("Traducerea a fost finalizata cu succes.\n");
    write_file.close();
    file.close();
}

void compile(const char *file, const char *out) {
    std::stringstream compile;
    compile << "g++ "
            << file
            << " -o " << out << " -w ";

    system(compile.str().c_str());
}

void title_ascii() {
    printf("                              _                                     \n");
    printf("                             | |                                     \n");
    printf(" _ __   ___   ___  _   _   __| |  ___    ___  ___   _ __ ___   _ __  \n");
    printf(R"(| '_ \ / __| / _ \| | | | / _` | / _ \  / __|/ _ \ | '_ ` _ \ | '_ \ )");
    printf("\n");
    printf(R"(| |_) |\__ \|  __/| |_| || (_| || (_) || (__| (_) || | | | | || |_) |)");
    printf("\n");
    printf(R"(| .__/ |___/ \___| \__,_| \__,_| \___/  \___|\___/ |_| |_| |_|| .__/ )");
    printf("\n");
    printf("| |                                                           | |    \n");
    printf("|_|                                                           |_|    \n");
}