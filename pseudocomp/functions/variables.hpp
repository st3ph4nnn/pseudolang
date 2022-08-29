#pragma once
#include <vector>
#include <string>
#include <algorithm>

namespace variables {
    std::vector<std::string> ln;

    bool variabila(std::string x) {
        std::vector<std::string> variables = {
            "int",
            "bool",
            "double",
            "float",
            "string",
            "char",
        };

        return std::count(variables.begin(), variables.end(), x);
    }

    std::string declara() {
        if (ln[0] == "declara") {
            if (ln.size() == 1 || variabila(ln[1]) || !variabila(ln[ln.size() - 1])) {
                printf("[EROARE] 'declara' nu a fost folosit corect: ");
                for (auto i : ln) printf("%s ", i.c_str());
                printf("\nUtilizare: declara {...} {tip} \n");
                exit(0);
            }

            std::string rtn = (ln[ln.size()-1] + " ");

            if (ln.size() == 3)
                return (ln[2] + " " + ln[1] + ";\n");

            for (int i = 1; i < ln.size() - 1; i++)
                rtn += ln[i] + ", ";
            
            rtn.pop_back();
            rtn.pop_back();
            rtn += ";\n";

            return rtn;
        }

        return " ";
    }

    std::string citestev() {
        if (ln[0] == "citeste") {
            if (ln.size() == 1) {
                printf("[EROARE] 'citeste' nu a fost folosit corect: ");
                for (auto i : ln) printf("%s ", i.c_str());
                printf("\nUtilizare: citeste {var_1} {var_2} ...\n");
                exit(0);
            }

            std::string rtn;
            for (int i = 1; i < ln.size(); i++) rtn += ln[i] + ">>";
            rtn.pop_back();
            rtn.pop_back();

            return "std::cin>>" + rtn + ";\n";
        }

        return " ";
    }

    bool run(std::string &wr, std::vector<std::string> line) {
        ln = line;

        wr = declara();
        if (wr != " ") return true;

        wr = citestev();
        if (wr != " ") return true;
        
        return false;
    }
}