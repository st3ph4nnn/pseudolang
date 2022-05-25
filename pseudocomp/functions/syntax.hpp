#include "../includes.hpp"

namespace syntax {
    bool run(std::string &wr, std::vector<std::string> line) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == "incepe" || line[i] == "main") {
                wr = "int main() {\n";
                return true;
            }

            if (line[i] == "executa" || line[i] == "atunci" || line[i] == "start") {
                wr = "{\n";
                return true;
            }

            if (line[i] == "sfarsit" || line[i] == "gata") {
                wr = "}\n";
                return true;
            }

            if (line[i] == "oprire") {
                wr = "return 0";
                return true;
            }

            if (line[i] == "incheie") {
                wr = "return 0;\n}";
                return true;
            }

            if (line[i] == "inapoiaza") {
                wr = "return " + line[i + 1] + ";\n";
                return true;
            }

            if (line[i] == "std") {
                wr = "using namespace std;\n";
                return true;
            }

            if (i == line.size() - 1)
                wr = line[i] + ";\n";
            else
                wr = line[i] + " ";

            return true;
        }
    }
}