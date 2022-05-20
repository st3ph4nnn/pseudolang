var cuv = [];

function foloseste() {
    if (cuv[0] == "foloseste") {
        if (cuv.length > 2) {
            var rtn = "";
            for (var i = 1; i < cuv.length; i++)
                rtn += "#include <" + cuv[i] + ">\n";
            return rtn;
        }
        return "#include <" + cuv[1] + ">\n";
    }

    return " ";
}

function variabila(vr) {
    return ["int", "double", "bool", "std::string", "string", "float", "char", "charv", "intv", "doublev", "boolv", "std::stringv", "stringv", "floatv"].includes(vr);
}

function declara() {
    if (cuv[0] == "declara") {
        if (cuv.length == 1 || variabila(cuv[1]) || !variabila(cuv[cuv.length - 1])) {
            console.error("[EROARE] 'declara' nu a fost folosit corect");
            console.log("\nUtilizare: declara {nume} {tip} \n");
            return " ";
        }

        var rtn = "";

        for (var i = 1; i < cuv.length - 1; i++)
            rtn += (cuv[cuv.length - 1] + " " + cuv[i] + ";\n");

        return rtn;
    }

    return " ";
}

function citestev() {
    if (cuv[0] == "citeste") {
        if (cuv.length == 1) {
            console.error("[EROARE] 'citeste' nu a fost folosit corect:");
            console.log("\nUtilizare: citeste {var_1} {var_2} ...\n");
            return " ";
        }

        var rtn = "";
        for (var i = 1; i < cuv.length; i++)
            rtn += cuv[i] + ">>";
        rtn = rtn.slice(0, -2);

        return "std::cin>>" + rtn + ";\n";
    }

    return " ";
}

function printeaza() {
    if (cuv[0] == "afiseaza") {
        if (cuv.length > 2) {
            var rtn = ""
            for (var i = 1; i < cuv.length; i++)
                rtn += (cuv[i] + " ");

            rtn = rtn.slice(0, -1);
            return "std::cout<<" + rtn + ";\n";
        }
        return "std::cout<<" + cuv[1] + ";\n";
    }

    return " ";
}

function ifstatement() {
    if (cuv[0] == "daca") {
        if (cuv.length >= 3 && cuv[cuv.length - 1] == "atunci") {
            var rtn = ""
            for (var i = 1; i < cuv.length - 1; i++)
                rtn += (cuv[i] + " ");

            rtn = rtn.slice(0, -1);
            return "if (" + rtn + ") {\n";
        } else {
            console.error("[EROARE] 'daca' nu a fost folosit corect");
            console.log("\nUtilizare: daca {parametri} atunci ... sfarsit\n");
            return " ";
        }
    }

    if (cuv[0] == "altfel")
        return "} else {\n";

    return " ";
}

function whilestatement() {
    if (cuv[0] == "cat" && cuv[1] == "timp") {
        if (cuv.length >= 3 && cuv[cuv.length - 1] == "atunci") {
            var rtn = "";
            for (var i = 2; i < cuv.length - 1; i++)
                rtn += cuv[i] + " ";

            rtn = rtn.slice(0, -1);
            return "while (" + rtn + ") {\n";
        } else {
            console.error("[EROARE] 'cat timp' nu a fost folosit corect");
            console.log("\nUtilizare: cat timp {parametri} atunci ... sfarsit\n");
            return " ";
        }
    }

    return " ";
}

function dowhilestatement() {
    if (cuv[0] == "executa") {
        return "do \n{\n";
    }

    if (cuv[0] == "pana" && cuv[1] == "cand") {
        if (cuv.length <= 2) {
            console.error("[EROARE] 'executa ... pana cand' nu a fost folosit corect");
            console.log("\nUtilizare: executa (instructiuni) ... pana cand (conditie) sfarsit\n");
            return " ";
        }

        var rtn = "";
        for (var i = 2; i < cuv.length; i++)
            rtn += cuv[i] + " ";

        rtn = rtn.slice(0, -1);
        return "} while (" + rtn + ");\n";
    }

    return " ";
}

function forstatement() {
    if (cuv[0] == "pentru") {
        if (cuv[cuv.length - 1] == "executa") {
            var start = "";
            var pos = 1;
            for (var i = 1; i < cuv.length; i++) {
                pos = i;
                if (cuv[i][cuv[i].length-1] == ',') {
                    start += cuv[i].slice(0, -1);
                    break;
                }

                start += cuv[i] + " ";
            }

            pos++;

            var condition = "";
            for (var i = pos; i < cuv.length; i++) {
                pos = i;
                if (cuv[i][cuv[i].length-1] == ',') {
                    condition += cuv[i].slice(0, -1);
                    break;
                }

                condition += cuv[i] + " ";
            }

            pos++;

            var increment = "";
            for (var i = pos; cuv[i][0] != 'e'; i++)
                increment += cuv[i] + " ";

            increment = increment.slice(0, -1);

            return "for (" + start + "; " + condition + "; " + increment + ") {\n";
        } else {
            console.error("[EROARE] 'pentru' nu a fost folosit corect");
            console.log("\nUtilizare: pentru {val. initiala}, {conditie}, {crestere}, executa ... sfarsit\n");
            return " ";
        }
    }

    return " ";
}

export default function check(cuvi) {
    cuv = cuvi;

    for (var i = 0; i < cuv.length; i++) {
        if (cuv[i] == "//")
        break;

    var printing = printeaza();
    if (printing != " ")
        return printing;

    var citeste = citestev();
    if (citeste != " ")
       return citeste;

    var folosit = foloseste();
    if (folosit != " ")
        return folosit;

    var declare = declara();
    if (declare != " ")
        return declare;

    var ifstate = ifstatement();
    if (ifstate != " ")
        return ifstate;

    var whilestate = whilestatement();
    if (whilestate != " ")
        return whilestate;

    var forstate = forstatement();
    if (forstate != " ")
        return forstate;

    var dostate = dowhilestatement();
    if (dostate != " ")
        return dostate;

    if (cuv[i] == "main")
        return "int main()\n{\n";

    if (cuv[i] == "executa" || cuv[i] == "atunci" || cuv[i] == "start")
        return "{\n";

    if (cuv[i] == "sfarsit" || cuv[i] == "gata")
        return "}\n";

    if (cuv[i] == "oprire")
        return "return 0";

    if (cuv[i] == "incheie")
        return "return 0;\n}";

    if (cuv[i] == "inapoiaza")
        return "return " + cuv[i + 1] + ";\n";

    if (i == cuv.length - 1)
        return cuv.join("") + ";\n";
    }
}