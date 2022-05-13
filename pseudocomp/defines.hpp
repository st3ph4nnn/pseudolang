#pragma once
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

#include "clip/clipboardxx.hpp"

bool variabila(std::string x) {
    std::vector<std::string> variables = {
        "int",
        "intv",
        "bool",
        "boolv",
        "double",
        "doublev",
        "float",
        "floatv",
        "string",
        "stringv",
        "char",
        "charv"};
    return std::count(variables.begin(), variables.end(), x);
}

std::vector<std::string> cuv;

std::string foloseste() {
    if (cuv[0] == "foloseste") {
        if (cuv.size() > 2) {
            std::string rtn;
            for (int i = 1; i < cuv.size(); i++)
                rtn += "#include <" + cuv[i] + ">\n";
            return rtn;
        }
        return "#include <" + cuv[1] + ">\n";
    }

    return " ";
}

std::string declara() {
    if (cuv[0] == "declara") {
        if (cuv.size() == 1 || variabila(cuv[1]) || !variabila(cuv[cuv.size() - 1])) {
            printf("[EROARE] 'declara' nu a fost folosit corect: ");
            for (auto i : cuv)
                printf("%s ", i.c_str());
            printf("\nUtilizare: declara {nume} {tip} \n");
            exit(0);
        }

        std::string rtn = "";

        for (int i = 1; i < cuv.size() - 1; i++)
            if (cuv[cuv.size() - 2].at(cuv[cuv.size() - 2].length() - 1) == 'v') {
                cuv[cuv.size() - 2].pop_back();
                if (cuv.size() == 3) {
                    printf("[EROARE] 'declara' nu a fost folosit corect: ");
                    for (auto i : cuv)
                        printf("%s ", i.c_str());
                    printf("\nUtilizare: declara {nume} {tip} {marimea vectorului}\n");
                    exit(0);
                }
                rtn += (cuv[cuv.size() - 2] + " " + cuv[i] + "[" + cuv[cuv.size() - 1] + "];\n");
            } else {
                rtn += (cuv[cuv.size() - 1] + " " + cuv[i] + ";\n");
            }

        return rtn;
    }

    return " ";
}

std::string citestev() {
    if (cuv[0] == "citeste") {
        if (cuv.size() == 1) {
            printf("[EROARE] 'citeste' nu a fost folosit corect: ");
            for (auto i : cuv)
                printf("%s ", i.c_str());
            printf("\nUtilizare: citeste {var_1} {var_2} ...\n");
            exit(0);
        }

        std::string rtn;
        for (int i = 1; i < cuv.size(); i++)
            rtn += cuv[i] + ">>";
        rtn.pop_back();
        rtn.pop_back();

        return "std::cin>>" + rtn + ";\n";
    }

    return " ";
}

std::string printeaza() {
    if (cuv[0] == "afiseaza") {
        if (cuv.size() > 2) {
            std::string rtn;
            for (int i = 1; i < cuv.size(); i++)
                rtn += (std::string(cuv[i]) + " ");

            rtn.pop_back();
            return "std::cout<<" + std::string(rtn) + ";\n";
        }
        return "std::cout<<" + cuv[1] + ";\n";
    }

    return " ";
}

std::string ifstatement() {
    if (cuv[0] == "daca") {
        if (cuv.size() >= 3 && cuv[cuv.size() - 1] == "atunci") {
            std::string rtn;
            for (int i = 1; i < cuv.size() - 1; i++)
                rtn += cuv[i] + " ";

            rtn.pop_back();
            return "if (" + rtn + ") {\n";
        } else {
            printf("[EROARE] 'daca' nu a fost folosit corect: ");
            for (auto i : cuv)
                printf("%s ", i.c_str());
            printf("\nUtilizare: daca {parametri} atunci ... sfarsit\n");
            exit(0);
        }
    }

    if (cuv[0] == "altfel")
        return "} else {\n";

    return " ";
}

std::string whilestatement() {
    if (cuv[0] == "cat" && cuv[1] == "timp") {
        if (cuv.size() >= 3 && cuv[cuv.size() - 1] == "atunci") {
            std::string rtn;
            for (int i = 2; i < cuv.size() - 1; i++)
                rtn += cuv[i] + " ";

            rtn.pop_back();
            return "while (" + rtn + ") {\n";
        } else {
            printf("[EROARE] 'cat timp' nu a fost folosit corect: ");
            for (auto i : cuv)
                printf("%s ", i.c_str());
            printf("\nUtilizare: cat timp {parametri} atunci ... sfarsit\n");
            exit(0);
        }
    }

    return " ";
}

std::string dowhilestatement() {
    if (cuv[0] == "repeta") {
        return "do \n{\n";
    }

    if (cuv[0] == "pana" && cuv[1] == "cand") {
        if (cuv.size() <= 2) {
            printf("[EROARE] 'repeta ... pana cand' nu a fost folosit corect: ");
            for (auto i : cuv)
                printf("%s ", i.c_str());
            printf("\nUtilizare: repeta {parametri} ... pana cand {conditie} sfarsit\n");
            exit(0);
        }

        std::string rtn;
        for (int i = 2; i < cuv.size(); i++)
            rtn += cuv[i] + " ";

        rtn.pop_back();
        return "} while (" + rtn + ");\n";
    }

    return " ";
}

std::string forstatement() {
    if (cuv[0] == "pentru") {
        if (cuv[cuv.size() - 1] == "executa") {
            std::string start;
            int pos = 1;
            for (int i = 1; i < cuv.size(); i++) {
                pos = i;
                if (cuv[i].at(cuv[i].length() - 1) == ',') {
                    cuv[i].pop_back();
                    start += cuv[i];
                    break;
                }

                start += cuv[i] + " ";
            }

            pos++;

            std::string condition;
            for (int i = pos; i < cuv.size(); i++) {
                pos = i;
                if (cuv[i].at(cuv[i].length() - 1) == ',') {
                    cuv[i].pop_back();
                    condition += cuv[i];
                    break;
                }

                condition += cuv[i] + " ";
            }

            pos++;

            std::string increment;
            for (int i = pos; cuv[i].at(0) != 'e'; i++)
                increment += cuv[i] + " ";

            increment.pop_back();

            return "for (" + start + "; " + condition + "; " + increment + ") {\n";
        } else {
            printf("[EROARE] 'pentru' nu a fost folosit corect: ");
            for (auto i : cuv)
                printf("%s ", i.c_str());
            printf("\nUtilizare: pentru {val. initiala}, {conditie}, {crestere}, executa ... sfarsit\n");
            exit(0);
        }
    }

    return " ";
}

void check(std::ofstream &write) {
    for (int i = 0; i < cuv.size(); i++) {
        if (cuv[i] == "//")
            break;

        std::string printing = printeaza();
        if (printing != " ") {
            write << printing;
            break;
        }

        std::string citeste = citestev();
        if (citeste != " ") {
            write << citeste;
            break;
        }

        std::string folosit = foloseste();
        if (folosit != " ") {
            write << folosit;
            break;
        }

        std::string declare = declara();
        if (declare != " ") {
            write << declare;
            break;
        }

        std::string ifstate = ifstatement();
        if (ifstate != " ") {
            write << ifstate;
            break;
        }

        std::string whilestate = whilestatement();
        if (whilestate != " ") {
            write << whilestate;
            break;
        }

        std::string forstate = forstatement();
        if (forstate != " ") {
            write << forstate;
            break;
        }

        std::string dostate = dowhilestatement();
        if (dostate != " ") {
            write << dostate;
            break;
        }

        if (cuv[i] == "main") {
            write << "int main()\n{\n";
            break;
        }

        if (cuv[i] == "executa" || cuv[i] == "atunci" || cuv[i] == "start") {
            write << "{\n";
            break;
        }

        if (cuv[i] == "sfarsit" || cuv[i] == "gata") {
            write << "}\n";
            break;
        }

        if (cuv[i] == "oprire") {
            write << "return 0";
            break;
        }

        if (cuv[i] == "incheie") {
            write << "return 0;\n}";
            break;
        }

        if (cuv[i] == "inapoiaza") {
            write << "return " + cuv[i + 1] + ";\n";
            break;
        }

        if (cuv[i] == "std") {
            write << "using namespace std;\n";
            break;
        }

        if (i == cuv.size() - 1)
            write << cuv[i] << ";\n";
        else
            write << cuv[i] << " ";
    }
}