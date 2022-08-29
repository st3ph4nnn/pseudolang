# pseudolang

Pseudolang este o variatie a pseudo-cod-ului din ziua de astazi, putin modificata, construita folosind c++17. 
Pseudocomp este "compilatorul" pentru pseudolang.

Câteva lucruri tari pe care pseudolang le poate face: 
- să traducă cod C++ in Pseudocod
- să compileze cod Pseudocod
- să folosească termeni deja întâlniți în C++, precum funcții, librării, etc..

Un scurt exemplu: 

```c++
C++
____________
foloseste iostream  
main  
    afiseaza "5\n"  
incheie  

Pseudolang
____________
#include <iostream>  
using namespace std;  
int main() {  
    cout<<"5\n";  
    return 0;  
}  
```

# Cum il pot folosi?

### Online

Avem site-ul construit folosind Github Pages: https://st3ph4nnn.github.io/pseudolang/ 
Varianta aceasta este nerecomandată totuși, pentru că poate fi outdated.

### Offline

Pentru a compila codul, mai întai trebuie G++ instalat.
- Windows: https://www.youtube.com/watch?v=Zcy981HhGw0
- Linux: (sudo apt install g++ / sudo dnf install g++) etc..

Dacă folosiți Linux, va trebuii să instalați si **make**:  
**sudo apt install make** / **sudo dnf install make** etc..

Clonați (sau pur și simplu downloadați: https://github.com/st3ph4nnn/pseudolang/archive/refs/heads/main.zip) proiectul.  
Intrați in folderul proiectului, pseudocomp, build, deschideți CMD/Terminal (in același folder) si executați:  
- Windows: mingw32-make.exe OS=WIN
- Linux: make OS=LINUX

Dupa aceea, un fisier executabil va aparea in folderul **build**.  
Puteti rula un fisier **.pseudo** in felul urmator:  
```pseudolang.exe (fisier.pseudo) (args...)```

Citiți mai întai, wiki-ul: https://github.com/st3ph4nnn/pseudolang/wiki