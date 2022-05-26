#pragma once
#include "includes.hpp"

namespace arguments {
    bool compile = false;
    std::string input_file;
    std::string output_file;
    std::string write_file = "trans.cpp";
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

            if (args[i] == "-t") {
                if (i + 1 > args.size() - 1)
                    goto utilizare_incorecta;

                arguments::write_file = args[i + 1];
                i++;
                continue;
            }

            if (args[i] == "-i")
                arguments::info = true;
        }
    }

    return;

utilizare_incorecta:
    printf("\n[EROARE] Utilizare incorecta.\n");
    printf("Utilizare: pseudoc (fisier.pseudo) {args...}\n");
    printf("args (OPTIONAL): -o (output.exe); -c, -s, -i\n\n");
    exit(0);
}

bool open_source_file(const char *file_to_open, std::ifstream &file) {
    file.open(file_to_open);
    if (!file.is_open()) {
        printf("[EROARE] Nu am putut deschide fisierul: %s\n", file_to_open);
        return 0;
    }
    return 1;
}

bool open_write_file(const char *file_to_open, std::ofstream &file) {
    file.open(file_to_open);
    if (!file.is_open()) {
        printf("[EROARE] Nu am putut deschide fisierul: %s\n", file_to_open);
        return 0;
    }
    return 1;
}

std::vector<std::string> split(std::string s) {
    std::vector<std::string> str;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, ' ')) {
        if (item != "" || item != " " || item != "\t")
            str.push_back(item);
    }

    return str;
}

void translate(std::ifstream &file, std::ofstream &write_file) {
    printf("[INFO] Traducerea are loc...\n");
    std::string line;

    while (std::getline(file, line)) {
        if (line.length() == 0) {
            write_file << '\n';
            continue;
        }

        line.erase(0, line.find_first_not_of(" \t\n"));

        std::string line_temp;
        std::unique_copy(line.begin(), line.end(), std::back_insert_iterator<std::string>(line_temp),
                         [](char a, char b) { return isspace(a) && isspace(b); });

        if (line_temp.length() == 0) {
            write_file << '\n';
            continue;
        }

        parse(write_file, split(line_temp));
    }

    printf("[SUCCES] Traducerea a fost finalizata cu succes.\n\n");
    write_file.close();
    file.close();
}

void compile(const char *file, const char *out) {
    std::stringstream compile;
    compile << "g++ "
            << file
            << " -o " << out << " -w ";

    bool compiled = !(system(compile.str().c_str()));

    printf((!compiled ? "[COMPILE] Nu am reusit sa compilam fisierul." : "[COMPILE] Fisierul a fost compilat cu succes."));
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