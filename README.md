 ```                           _                      _                                     
   ___ _ __ _ __   ___  ___| |_ ___     __ _ _   _(_)_ __ ___   __ _ _ __ __ _  ___  ___ 
  / _ \ '__| '_ \ / _ \/ __| __/ _ \   / _` | | | | | '_ ` _ \ / _` | '__/ _` |/ _ \/ __|
 |  __/ |  | | | |  __/\__ \ || (_) | | (_| | |_| | | | | | | | (_| | | | (_| |  __/\__ \
  \___|_|  |_| |_|\___||___/\__\___/   \__, |\__,_|_|_| |_| |_|\__,_|_|  \__,_|\___||___/```
                                       |___/                                             

# pseudolang

EN: pseudolang is a compiler for my romanian pseudo language warriors out there.  
I will continue by speaking my native language: romanian.  

# Ce este pseudolang?

pseudolang este un compilator pentru pseudo-cod.  
Avandu-si propia documentatie, si o similaritate de 80% cu pseudo-cod-ul pe care il  
folosesti in fiecare zi, el poate fi folosit pentru (aproape) orice.  
    
Tin sa mentionez, ca, pseudolang poate si traduce pseudocod in C++.

exemplu:

```c++
foloseste iostream  
std  
main  
    afiseaza "5\n"  
incheie  

ECHIVALENT CU, DUPA TRADUCERE:  

#include <iostream>  
using namespace std;  
int main() {  
    cout<<"5\n";  
    return 0;  
}  
```

# Cum il pot folosi?

## ATENTIE: DACA VRETI SA COMPILATI CODUL, AVETI NEVOIE DE G++: https://www.youtube.com/watch?v=Zcy981HhGw0  

Descarci ultima versiune de fisier executabil de la 'Releases'  
si il pui intr-un folder. Dupa aceea creezi un fisier, de preferabil, cu extensia .pseudo  
iar apoi incepi sa codezi. Vezi wiki-ul oficial.
Pentru a compila/translata, parametrii sunt in felul urmator:  

```pseudolang.exe (fisier.pseudo) (args...)```

Cititi mai intai, wiki-ul: https://github.com/st3ph4nnn/pseudolang/wiki

# Cum pot compila compilatorul? (pleonasm)

Modifica codul dupa dorinta ta, iar dupa aceea compileaza-l folosind:  
```
g++ main.cpp -o ./build/pseudocomp.exe

Sau rulati:

mingw32-make.exe
```
