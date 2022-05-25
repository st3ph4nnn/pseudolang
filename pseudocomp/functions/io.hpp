#pragma once
#include "../includes.hpp"

namespace io {
    std::vector<std::string> ln;

    std::string printeaza() {
        if (ln[0] == "afiseaza") {
            if (ln.size() > 2) {
                std::string rtn;
                for (int i = 1; i < ln.size(); i++)
                    rtn += (std::string(ln[i]) + " ");

                rtn.pop_back();
                return "std::cout<<" + std::string(rtn) + ";\n";
            }
            return "std::cout<<" + ln[1] + ";\n";
        }

        return " ";
    }

    bool run(std::string &wr, std::vector<std::string> line) {
        ln = line;
        wr = printeaza();
        
        if (wr != " ")
            return true;
        
        return false;
    }
}