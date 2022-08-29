#pragma once
#include <string>
#include <vector>

namespace io {
    std::vector<std::string> ln;

    std::string printeaza() {
        if (ln[0] == "afiseaza") {
            if (ln.size() > 2) {
                std::string rtn;
                for (int i = 1; i < ln.size(); i++)
                    rtn += (ln[i] + " ");

                rtn.pop_back();
                return "std::cout<<" + rtn + ";\n";
            }
            return "std::cout<<" + ln[1] + ";\n";
        }

        return " ";
    }

    std::string executa() {
        if (ln[0] == "executa") {
            if (ln.size() > 2) {
                std::string rtn;
                for (int i = 1; i < ln.size(); i++)
                    rtn += (ln[i] + " ");

                rtn.pop_back();
                return "std::system(" + rtn + ");\n";
            }

            return "std::system(" + ln[1] + ");\n";
        }

        return " ";
    }

    bool run(std::string &wr, std::vector<std::string> line) {
        ln = line;

        wr = printeaza();
        if (wr != " ") return true;

        wr = executa();
        if (wr != " ") return true;

        return false;
    }
}