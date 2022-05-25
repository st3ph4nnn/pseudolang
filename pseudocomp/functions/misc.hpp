#include "../includes.hpp"

namespace misc {
    std::vector<std::string> ln;

    std::string foloseste() {
        if (ln[0] == "foloseste") {
            if (ln.size() > 2) {
                std::string rtn;
                for (int i = 1; i < ln.size(); i++)
                    rtn += "#include <" + ln[i] + ">\n";
                return rtn;
            }
            return "#include <" + ln[1] + ">\n";
        }

        return " ";
    }

    bool run(std::string &wr, std::vector<std::string> line) {
        ln = line;

        wr = foloseste();
        if (wr != " ")
            return true;
        
        return false;
    }
}