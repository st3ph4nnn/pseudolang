import translate from "https://st3ph4nnn.github.io/pseudolang/translate/translate.js"
var beautifier = require('https://cdnjs.cloudflare.com/ajax/libs/js-beautify/1.14.3/beautify.js')

$("body").hide();

var input = ace.edit("input");
input.setTheme("ace/theme/one_dark");
input.setShowPrintMargin(false);
input.setOptions({ fontSize: "15pt" });

var output = ace.edit("output");
output.setTheme("ace/theme/one_dark");
output.session.setMode("ace/mode/c_cpp");
output.setShowPrintMargin(false);
output.setOptions({ fontSize: "15pt" });

$("body").fadeIn(1000);

var button = document.getElementById('translate');

button.addEventListener("click", () => {
    translate(input, output);
    console.log(beautifier.js_beautify(output.getValue()));
});