import translate from "./translate/translate.js"

$("body").hide();

function get_mobile() {
    const toMatch = [
        /Android/i,
        /webOS/i,
        /iPhone/i,
        /iPad/i,
        /iPod/i,
        /BlackBerry/i,
        /Windows Phone/i
    ];
    
    return toMatch.some((toMatchItem) => {
        return navigator.userAgent.match(toMatchItem);
    });
}

var mobile = get_mobile();

if (mobile) {
    console.log("mobile");
    $("#input-txt").hide();
    $("#output-txt").hide();
}

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
    output.setValue(js_beautify(output.getValue()));
});