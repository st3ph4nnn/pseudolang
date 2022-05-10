# pseudolang

EN: pseudolang is a compiler for my romanian pseudo language warriors out there.  
I will continue speaking romanian.  

# Ce este pseudolang?

pseudolang este un compilator pentru pseudo-cod.  
Avandu-si propia documentatie, si o similaritate de 80% cu pseudo-cod-ul pe care il  
folosesti in fiecare zi, el poate fi folosit pentru (aproape) orice.  
    
Tin sa mentionez, ca, pseudolang poate si traduce pseudocod in C++.

# Cum il pot folosi?

ATENTIE: DACA VRETI SA COMPILATI CODUL, AVETI NEVOIE DE G++: https://www.youtube.com/watch?v=Zcy981HhGw0  

Descarci ultima versiune de fisier executabil de la 'Releases'  
si il pui intr-un folder. Dupa aceea creezi un fisier, de preferabil, cu extensia .pseudo  
iar apoi incepi sa codezi. Vezi documentatia oficiala.  
Pentru a compila/translata, parametrii sunt in felul urmator:  
**pseudolang.exe (fisier.pseudo) (executabil.exe) (trans/compile)**
trans - translateaza codul in fisierul temp.cpp    
compile - compileaza codul in executabil.exe  

# Cum il pot compila?

Modifica codul dupa dorinta ta, iar dupa aceea compileaza-l folosind:  
g++ main.cpp -o ./build/pseudocomp.exe