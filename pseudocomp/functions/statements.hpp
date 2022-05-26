#pragma once
#include "../includes.hpp"

namespace statements {
    std::vector<std::string> ln;

    std::string ifstatement() {
        if (ln[0] == "daca") {
            if (ln.size() >= 3 && ln[ln.size() - 1] == "atunci") {
                std::string rtn;
                for (int i = 1; i < ln.size() - 1; i++)
                    rtn += ln[i] + " ";

                rtn.pop_back();
                return "if (" + rtn + ") {\n";
            } else {
                printf("[EROARE] 'daca' nu a fost folosit corect: ");
                for (auto i : ln)
                    printf("%s ", i.c_str());
                printf("\nUtilizare: daca {parametri} atunci ... sfarsit\n");
                exit(0);
            }
        }

        if (ln[0] == "altfel")
            return "} else {\n";

        return " ";
    }

    std::string whileloop() {
        if (ln[0] == "cat" && ln[1] == "timp") {
            if (ln.size() >= 3 && ln[ln.size() - 1] == "atunci") {
                std::string rtn;
                for (int i = 2; i < ln.size() - 1; i++)
                    rtn += ln[i] + " ";

                rtn.pop_back();
                return "while (" + rtn + ") {\n";
            } else {
                printf("[EROARE] 'cat timp' nu a fost folosit corect: ");
                for (auto i : ln)
                    printf("%s ", i.c_str());
                printf("\nUtilizare: cat timp {parametri} atunci ... sfarsit\n");
                exit(0);
            }
        }

        return " ";
    }

    std::string dowhilestatement() {
        if (ln[0] == "repeta") {
            return "do \n{\n";
        }

        if (ln[0] == "pana" && ln[1] == "cand") {
            if (ln.size() <= 2) {
                printf("[EROARE] 'repeta ... pana cand' nu a fost folosit corect: ");
                for (auto i : ln)
                    printf("%s ", i.c_str());
                printf("\nUtilizare: repeta (instructiuni) ... pana cand {conditie} sfarsit\n");
                exit(0);
            }

            std::string rtn;
            for (int i = 2; i < ln.size(); i++)
                rtn += ln[i] + " ";

            rtn.pop_back();
            return "} while (" + rtn + ");\n";
        }

        return " ";
    }

    std::string forstatement() {
        if (ln[0] == "pentru") {
            if (ln[ln.size() - 1] == "executa") {
                std::string start;
                int pos = 1;
                for (int i = 1; i < ln.size(); i++) {
                    pos = i;
                    if (ln[i].at(ln[i].length() - 1) == ',') {
                        ln[i].pop_back();
                        start += ln[i];
                        break;
                    }

                    start += ln[i] + " ";
                }

                pos++;

                std::string condition;
                for (int i = pos; i < ln.size(); i++) {
                    pos = i;
                    if (ln[i].at(ln[i].length() - 1) == ',') {
                        ln[i].pop_back();
                        condition += ln[i];
                        break;
                    }

                    condition += ln[i] + " ";
                }

                pos++;

                std::string increment;
                for (int i = pos; ln[i].at(0) != 'e'; i++)
                    increment += ln[i] + " ";

                increment.pop_back();

                return "for (" + start + "; " + condition + "; " + increment + ") {\n";
            } else {
                printf("[EROARE] 'pentru' nu a fost folosit corect: ");
                for (auto i : ln)
                    printf("%s ", i.c_str());
                printf("\nUtilizare: pentru {val. initiala}, {conditie}, {crestere}, "
                       "executa ... sfarsit\n");
                exit(0);
            }
        }

        return " ";
    }

    bool run(std::string &wr, std::vector<std::string> line) {
        ln = line;

        wr = ifstatement();
        if (wr != " ") {
            return true;
        }

        wr = whileloop();
        if (wr != " ") {
            return true;
        }

        wr = forstatement();
        if (wr != " ") {
            return true;
        }

        wr = dowhilestatement();
        if (wr != " ") {
            return true;
        }

        return false;
    }

} // namespace statements