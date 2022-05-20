```
                                               __          ___                                
                                              /\ \        /\_ \                               
             _____     ____     __   __  __   \_\ \    ___\//\ \      __      ___      __     
            /\ '__`\  /',__\  /'__`\/\ \/\ \  /'_` \  / __`\\ \ \   /'__`\  /' _ `\  /'_ `\   
            \ \ \L\ \/\__, `\/\  __/\ \ \_\ \/\ \L\ \/\ \L\ \\_\ \_/\ \L\.\_/\ \/\ \/\ \L\ \  
             \ \ ,__/\/\____/\ \____\\ \____/\ \___,_\ \____//\____\ \__/.\_\ \_\ \_\ \____ \ 
              \ \ \/  \/___/  \/____/ \/___/  \/__,_ /\/___/ \/____/\/__/\/_/\/_/\/_/\/___L\ \
               \ \_\                                                                   /\____/
                \/_/                                                                   \_/__/ 
```
# Ce este pseudolang?

pseudolang este un compilator pentru pseudo-cod.  
Avandu-si propia documentatie, si o similaritate de 80% cu pseudo-cod-ul pe care il  
folosesti in fiecare zi, el poate fi folosit pentru (aproape) orice.  
    
Tin sa mentionez, ca, pseudolang poate si traduce pseudocod in C++.

exemplu:

```c++
foloseste iostream  
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

### Online: st3ph4nnn.github.io/pseudolang/ (NU ESTE UPDATAT MEREU!)
## Offline
### ATENTIE: DACA VRETI SA COMPILATI CODUL, AVETI NEVOIE DE G++: https://www.youtube.com/watch?v=Zcy981HhGw0 

Descarci ultima versiune de fisier executabil de la 'Releases'  
si il pui intr-un folder. Dupa aceea creezi un fisier, de preferabil, cu extensia .pseudo  
iar apoi incepi sa codezi. Vezi wiki-ul oficial.
Pentru a compila/translata, parametrii sunt in felul urmator:  

```pseudolang.exe (fisier.pseudo) (args...)```

Cititi mai intai, wiki-ul: https://github.com/st3ph4nnn/pseudolang/wiki

# Cum pot compila compilatorul? (pleonasm)

Modifica codul dupa dorinta ta, iar dupa aceea compileaza-l (in terminal, desigur) folosind:  

```
Linux: 
sudo apt install make
make OS=LINUX (in folderul cu Makefile)

Windows:
mingw32-make.exe (in folderul cu Makefile)
```
