#include "functions/io.hpp"
#include "functions/misc.hpp"
#include "functions/statements.hpp"
#include "functions/syntax.hpp"
#include "functions/variables.hpp"

#include <fstream>
#include <string>
#include <vector>

void parse(std::ofstream &write, std::vector<std::string> ln) {
    std::string str = "";

    if (statements::run(str, ln)) {
        write << str;
        return;
    }

    if (variables::run(str, ln)) {
        write << str;
        return;
    }

    if (misc::run(str, ln)) {
        write << str;
        return;
    }

    if (io::run(str, ln)) {
        write << str;
        return;
    }

    if (syntax::run(str, ln)) {
        write << str;
        return;
    }
}