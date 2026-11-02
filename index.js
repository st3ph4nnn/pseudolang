import translate from "./translate/translate.js";

const INDENT = "    ";

const examples = {
    hello: {
        name: "Hello World",
        code: [
            "foloseste iostream",
            "main",
            '    afiseaza "Salut, lume!"',
            "incheie"
        ].join("\n")
    },
    sum: {
        name: "Citire și sumă",
        code: [
            "foloseste iostream",
            "main",
            "    declara a b suma int",
            "    citeste a b",
            "    suma = a + b",
            '    afiseaza "Suma este:"',
            "    afiseaza suma",
            "incheie"
        ].join("\n")
    },
    average: {
        name: "Medie",
        code: [
            "foloseste iostream",
            "main",
            "    declara a b media double",
            "    citeste a b",
            "    media = (a + b) / 2",
            '    afiseaza "Media este:"',
            "    afiseaza media",
            "incheie"
        ].join("\n")
    },
    evenOdd: {
        name: "Par sau impar",
        code: [
            "foloseste iostream",
            "main",
            "    declara n int",
            "    citeste n",
            "    daca n % 2 == 0 atunci",
            '        afiseaza "Par"',
            "    altfel",
            '        afiseaza "Impar"',
            "    sfarsit",
            "incheie"
        ].join("\n")
    },
    forLoop: {
        name: "Buclă for",
        code: [
            "foloseste iostream",
            "main",
            "    pentru int i = 1, i <= 5, i++ executa",
            "        afiseaza i",
            "    sfarsit",
            "incheie"
        ].join("\n")
    },
    sumLoop: {
        name: "Sumă 1..5",
        code: [
            "foloseste iostream",
            "main",
            "    declara suma int",
            "    suma = 0",
            "    pentru int i = 1, i <= 5, i++ executa",
            "        suma = suma + i",
            "    sfarsit",
            "    afiseaza suma",
            "incheie"
        ].join("\n")
    },
    whileLoop: {
        name: "Buclă while",
        code: [
            "foloseste iostream",
            "main",
            "    declara i int",
            "    i = 5",
            "    cat timp i >= 1 atunci",
            "        afiseaza i",
            "        i = i - 1",
            "    sfarsit",
            "incheie"
        ].join("\n")
    },
    doWhile: {
        name: "Buclă do...while",
        code: [
            "foloseste iostream",
            "main",
            "    declara i int",
            "    i = 0",
            "    executa",
            "        afiseaza i",
            "        i = i + 1",
            "    pana cand i <= 5",
            "incheie"
        ].join("\n")
    },
    evens: {
        name: "Numere pare",
        code: [
            "foloseste iostream",
            "main",
            "    pentru int i = 0, i <= 10, i++ executa",
            "        daca i % 2 == 0 atunci",
            "            afiseaza i",
            "        sfarsit",
            "    sfarsit",
            "incheie"
        ].join("\n")
    },
    multiplication: {
        name: "Tabla înmulțirii",
        code: [
            "foloseste iostream",
            "main",
            "    pentru int i = 1, i <= 3, i++ executa",
            "        pentru int j = 1, j <= 3, j++ executa",
            "            afiseaza i * j",
            "        sfarsit",
            "    sfarsit",
            "incheie"
        ].join("\n")
    },
    factorial: {
        name: "Factorial",
        code: [
            "foloseste iostream",
            "main",
            "    declara n int",
            "    declara rezultat int",
            "    n = 5",
            "    rezultat = 1",
            "    cat timp n > 1 atunci",
            "        rezultat = rezultat * n",
            "        n = n - 1",
            "    sfarsit",
            "    afiseaza rezultat",
            "incheie"
        ].join("\n")
    },
    vector: {
        name: "Vector",
        code: [
            "foloseste iostream",
            "main",
            "    declara v[3] int",
            "    v[0] = 10",
            "    v[1] = 20",
            "    v[2] = 30",
            "    afiseaza v[0]",
            "    afiseaza v[1]",
            "    afiseaza v[2]",
            "incheie"
        ].join("\n")
    },
    greeting: {
        name: "Nume și salut",
        code: [
            "foloseste iostream string",
            "main",
            "    declara nume string",
            "    citeste nume",
            '    afiseaza "Salut,"',
            "    afiseaza nume",
            "incheie"
        ].join("\n")
    }
};

const input = document.getElementById("input");
const output = document.getElementById("output");
const inputHighlight = document.getElementById("input-highlight");
const outputHighlight = document.getElementById("output-highlight");
const statusText = document.getElementById("status");
const exampleSelect = document.getElementById("examples");

function setStatus(message, type = "") {
    statusText.textContent = message;
    statusText.className = type;
}

const pseudolangRules = [
    { type: "comment", regex: /\/\/.*/y },
    { type: "string", regex: /"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'/y },
    { type: "number", regex: /\b\d+(?:\.\d+)?\b/y },
    {
        type: "keyword",
        regex: /\b(?:foloseste|declara|citeste|afiseaza|daca|atunci|altfel|sfarsit|gata|main|incheie|pentru|executa|cat|timp|pana|cand|inapoiaza|start|oprire|int|float|double|char|bool|string)\b/y
    },
    { type: "type", regex: /\b(?:std::string|iostream)\b/y },
    { type: "operator", regex: /<<|>>|==|!=|<=|>=|\+\+|--|[-+*/%=<>!]/y },
    { type: "punct", regex: /[{}()[\];,.]/y }
];

const cppRules = [
    { type: "comment", regex: /\/\/.*/y },
    { type: "string", regex: /"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'/y },
    { type: "preprocessor", regex: /#include\b/y },
    { type: "number", regex: /\b\d+(?:\.\d+)?\b/y },
    {
        type: "keyword",
        regex: /\b(?:int|float|double|char|bool|void|return|if|else|while|for|do|break|continue|using|namespace|true|false|string)\b/y
    },
    {
        type: "type",
        regex: /\b(?:std::string|std::cout|std::cin|iostream|cout|cin|std|endl)\b/y
    },
    { type: "operator", regex: /<<|>>|==|!=|<=|>=|\+\+|--|[-+*/%=<>!&|]/y },
    { type: "punct", regex: /[{}()[\];,.]/y }
];

function escapeHtml(text) {
    return text
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;");
}

function highlight(code, rules) {
    let html = "";
    let index = 0;

    while (index < code.length) {
        let matched = false;

        for (const rule of rules) {
            rule.regex.lastIndex = index;
            const match = rule.regex.exec(code);

            if (match && match.index === index) {
                html += `<span class="tok-${rule.type}">${escapeHtml(match[0])}</span>`;
                index += match[0].length;
                matched = true;
                break;
            }
        }

        if (!matched) {
            html += escapeHtml(code[index]);
            index += 1;
        }
    }

    return html;
}

function renderHighlights() {
    document.querySelectorAll(".code-editor").forEach((editor) => {
        editor.classList.add("has-highlight");
    });

    inputHighlight.innerHTML = highlight(input.value, pseudolangRules);
    outputHighlight.innerHTML = highlight(output.value, cppRules);
}

function highlightExamples() {
    document.querySelectorAll("code[data-lang]").forEach((block) => {
        const rules = block.dataset.lang === "cpp" ? cppRules : pseudolangRules;
        block.innerHTML = highlight(block.textContent, rules);
    });
}

function opensBlock(line) {
    return line === "main" ||
        line === "executa" ||
        line === "altfel" ||
        line === "start" ||
        line === "atunci" ||
        line.endsWith(" atunci") ||
        line.endsWith(" executa");
}

function indentSelectedLines() {
    const value = input.value;
    const start = input.selectionStart;
    const end = input.selectionEnd;
    const lineStart = value.lastIndexOf("\n", start - 1) + 1;
    const selected = value.slice(lineStart, end);
    const indented = selected
        .split("\n")
        .map((line) => INDENT + line)
        .join("\n");

    input.setRangeText(indented, lineStart, end, "select");
}

function outdentSelectedLines() {
    const value = input.value;
    const start = input.selectionStart;
    const end = input.selectionEnd;
    const lineStart = value.lastIndexOf("\n", start - 1) + 1;
    const selected = value.slice(lineStart, end);
    const outdented = selected
        .split("\n")
        .map((line) => {
            const spaces = (line.match(/^ +/) || [""])[0].length;
            return line.slice(Math.min(spaces, INDENT.length));
        })
        .join("\n");

    input.setRangeText(outdented, lineStart, end, "select");
}

function outdentCurrentLine() {
    const value = input.value;
    const selectionStart = input.selectionStart;
    const selectionEnd = input.selectionEnd;
    const lineStart = value.lastIndexOf("\n", selectionStart - 1) + 1;
    const newline = value.indexOf("\n", selectionStart);
    const lineEnd = newline === -1 ? value.length : newline;
    const line = value.slice(lineStart, lineEnd);
    const spaces = (line.match(/^ +/) || [""])[0].length;
    const remove = Math.min(spaces, INDENT.length);

    if (!remove) {
        return;
    }

    input.setRangeText("", lineStart, lineStart + remove, "preserve");
    input.selectionStart = Math.max(lineStart, selectionStart - remove);
    input.selectionEnd = Math.max(lineStart, selectionEnd - remove);
}

function handleEditorKey(event) {
    if (event.key === "Tab" && !event.ctrlKey && !event.altKey && !event.metaKey) {
        event.preventDefault();

        if (event.shiftKey) {
            if (input.selectionStart === input.selectionEnd) {
                outdentCurrentLine();
            } else {
                outdentSelectedLines();
            }
        } else if (input.selectionStart === input.selectionEnd) {
            input.setRangeText(INDENT, input.selectionStart, input.selectionEnd, "end");
        } else {
            indentSelectedLines();
        }

        input.dispatchEvent(new Event("input", { bubbles: true }));
        return;
    }

    if (event.key !== "Enter") {
        return;
    }

    event.preventDefault();

    const start = input.selectionStart;
    const end = input.selectionEnd;
    const before = input.value.slice(0, start);
    const currentLine = before.slice(before.lastIndexOf("\n") + 1);
    const indent = (currentLine.match(/^[ \t]*/) || [""])[0];
    const line = currentLine.trim();

    let nextIndent = indent;

    if (opensBlock(line)) {
        nextIndent += INDENT;
    }

    input.setRangeText("\n" + nextIndent, start, end, "end");
    input.dispatchEvent(new Event("input", { bubbles: true }));
}

function simplifyCpp(code) {
    let result = code
        .replace(/std::cout/g, "cout")
        .replace(/std::cin/g, "cin")
        .replace(/std::string/g, "string")
        .replace(/std::endl/g, "endl");

    if (!/\b(?:cout|cin|string|endl)\b/.test(result) || result.includes("using namespace std;")) {
        return result;
    }

    const lines = result.split("\n");
    let insertAt = -1;

    lines.forEach((line, index) => {
        if (line.startsWith("#include")) {
            insertAt = index;
        }
    });

    if (insertAt >= 0) {
        lines.splice(insertAt + 1, 0, "", "using namespace std;", "");
    } else {
        lines.splice(0, 0, "using namespace std;", "");
    }

    return lines.join("\n");
}

function spaceOperators(line) {
    return line
        .split(/("(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')/g)
        .map((part, index) => {
            if (index % 2 === 1) {
                return part;
            }

            return part
                .replace(/\s*<<\s*/g, " << ")
                .replace(/\s*>>\s*/g, " >> ");
        })
        .join("");
}

function indentCode(code) {
    let level = 0;

    return code
        .split("\n")
        .map((line) => {
            line = spaceOperators(line.trim());

            if (!line) {
                return "";
            }

            if (line.startsWith("}")) {
                level--;
            }

            const result = "    ".repeat(Math.max(level, 0)) + line;

            if (line.endsWith("{")) {
                level++;
            }

            return result;
        })
        .join("\n");
}

function translateCode() {
    if (!input.value.trim()) {
        setStatus("Scrie mai întâi cod Pseudolang.", "error");
        return;
    }

    output.value = "";
    renderHighlights();

    try {
        translate(
            { getValue: () => input.value },
            { setValue: (code) => { output.value = indentCode(simplifyCpp(code)); } }
        );

        renderHighlights();

        if (output.value.trim()) {
            setStatus("Traducere reușită.", "success");
        } else {
            setStatus("Nu s-a putut traduce. Verifică sintaxa.", "error");
        }
    } catch (error) {
        console.error(error);
        setStatus("A apărut o eroare la traducere.", "error");
    }
}

async function copyCode() {
    if (!output.value.trim()) {
        setStatus("Nu există cod de copiat.", "error");
        return;
    }

    try {
        await navigator.clipboard.writeText(output.value);
    } catch (error) {
        output.select();
        if (!document.execCommand("copy")) {
            setStatus("Copierea nu a funcționat.", "error");
            return;
        }
    }

    setStatus("Codul C++ a fost copiat.", "success");
}

function clearEditor() {
    input.value = "";
    output.value = "";
    exampleSelect.value = "";
    renderHighlights();
    setStatus("Editor golit.");
    input.focus();
}

function loadExample(key) {
    if (!examples[key]) {
        return;
    }

    input.value = examples[key].code;
    output.value = "";
    exampleSelect.value = key;
    renderHighlights();
    setStatus("Exemplu încărcat.");
}

function initExamples() {
    Object.keys(examples).forEach((key) => {
        const option = document.createElement("option");
        option.value = key;
        option.textContent = examples[key].name;
        exampleSelect.appendChild(option);
    });

    exampleSelect.addEventListener("change", () => {
        if (exampleSelect.value) {
            loadExample(exampleSelect.value);
        }
    });

    input.addEventListener("input", () => {
        exampleSelect.value = "";
        renderHighlights();
    });

    input.addEventListener("scroll", () => {
        inputHighlight.scrollTop = input.scrollTop;
        inputHighlight.scrollLeft = input.scrollLeft;
    });

    output.addEventListener("scroll", () => {
        outputHighlight.scrollTop = output.scrollTop;
        outputHighlight.scrollLeft = output.scrollLeft;
    });

    loadExample("hello");
}

function initTabs() {
    const buttons = document.querySelectorAll(".nav-btn");
    const pages = document.querySelectorAll(".page");

    buttons.forEach((button) => {
        button.addEventListener("click", () => {
            buttons.forEach((item) => item.classList.remove("active"));
            pages.forEach((page) => page.classList.remove("active"));

            button.classList.add("active");
            document.getElementById(button.dataset.page).classList.add("active");
            window.scrollTo(0, 0);
        });
    });
}

document.getElementById("translate").addEventListener("click", translateCode);
document.getElementById("copy").addEventListener("click", copyCode);
document.getElementById("clear").addEventListener("click", clearEditor);
input.addEventListener("keydown", handleEditorKey);

initTabs();
initExamples();
highlightExamples();
renderHighlights();
setStatus("Pregătit.");
