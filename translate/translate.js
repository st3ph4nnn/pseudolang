import check from "http://localhost:8000/translate/defines.js"

export default function translate(input, output) {
    var split = input.getValue().split(/\n/);
    var output_txt = "";

    split = split.filter(function(str) {
        return /\S/.test(str);
    });
    
    split.forEach(element => {
        if (!element.replace(/\s/g, '').length)
            return;

        element = element.replace(/\s+/g,' ').trim();
        element = element.split(" ");
        output_txt += check(element);
    });

    output.setValue(output_txt)
}