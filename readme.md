# Platformă de Streaming - Sistem de Gestiune (C++ OOP)

Acest proiect este o aplicație C++ (Console-based) menită să simuleze sistemul de backend al unei platforme de streaming (tip Netflix/Spotify)

Prezentul proiect demonstrează simularea completă a unui modul backend de gestiune a resurselor multimedia. Doresc să îmbunătățesc proiectul prin adăugarea de funcții care să utilizeze cât mai coerent și realist resursele valabile, cât mai asemănător unui model real de aplicație de streaming.

## Funcționalități principale:
### 1. Managementul Conținutului Media
Platforma suportă mai multe tipuri de conținut, fiecare cu proprietăți specifice:
* **Filme:** Stochează detalii precum rezoluția (ex: 4K, 1080p), format ratio și rating-ul.
* **Melodii:** Gestionează genul muzical, calitatea audio (bitrate) și disponibilitatea unui videoclip.
* **Videoclipuri Muzicale:** O fuziune între film și melodie, adăugând informații despre regizor și album.
* **Playlisturi globale:** Administratorul poate creea playlist-uri dacă dispune de date în baza lui ți le poate introduce în cadrul acestuia.

### 2. Gestiunea Utilizatorilor și a Abonamentelor
* Crearea de utilizatori noi asociați cu diferite planuri tarifare.
* **Abonament Standard:** Acces de bază la platformă.
* **Abonament Premium:** Beneficii extra (calitate 4K, vizionare pe mai multe ecrane, acces la avanpremiere).
* Posibilitatea de a **modifica/upgrada** abonamentul unui utilizator în timp real.

### 3. Sistem de Playlist-uri Globale
* Administratorul poate crea playlist-uri personalizate.
* Orice fișier media încărcat pe server poate fi adăugat într-o colecție prin intermediul ID-ului său unic, generat automat de sistem.

## Arhitectura Proiectului 

Totul este controlat printr-un meniu intuitiv, direct în consolă. 

* **Moștenire și Ierarhie:** Există o clasă de bază `ContinutMedia` din care derivă `ContinutFilm` și `ContinutMelodie`. Clasa `VideoclipMuzical` folosește *moștenirea multiplă* pentru a prelua caracteristici din ambele.
* **Polimorfism:** Fiecare tip de conținut știe cum să se afișeze corect, indiferent de context, datorită funcțiilor virtuale. De asemenea, la redarea unui conținut afișarea se face personalizat prin polimorfism, astfel că programul știe dacă trebuie să redea un film, o melodie sau un videoclip muzical.
* **Managementul Sigur al Memoriei:** Fiecare clasă are constructori de copiere, operatori de atribuire și destructori bine definiți. 
* **Tratarea Excepțiilor:** Erorile (cum ar fi introducerea de date invalide) sunt gestionate elegant prin clasa personalizată `ExceptiePlatforma`, prevenind blocarea bruscă a programului.

Starea internă a tuturor entităților este strict protejată prin modificatorii de acces private și protected. Niciun modul extern (nici măcar clasa controller Meniu) nu poate modifica direct durata unui film sau tipul unui abonament după instanțiere. Manipularea datelor se face exclusiv prin constructori și metode publice de tip "getter".

Orice clasă din cadrul proiectului care manipulează memorie alocată pe Heap a fost constrânsă să respecte „Regula celor Trei” (The Rule of Three): 
  - Destructorul Virtual: Declararea destructorului clasei de bază ca virtual ~continutMedia() garantează că, în momentul apelării comenzii delete pe un pointer de bază, curățarea memoriei coboară recursiv pe ierarhie până la nivelul cel mai derivat, ștergând complet structura obiectului.
  - Constructorul de Copiere: S-a implementat o copiere profundă (Deep Copy) a datelor, asigurând că la multiplicarea unei entități se obțin adrese de memorie complet noi și independente, evitând eroarea de tip Double-Free.
  - Operatorul de Atribuire: Suprascrierea operator= a inclus mecanisme de protecție împotriva auto-atribuirii (if (this != &altul)), curățând memoria veche înainte de alocarea și copierea noii stări.

Toate colecțiile de date din sistem (baza de date principală, playlist-urile globale, istoricul utilizatorilor) sunt stocate ca structuri liniare de tip std::vector<continutMedia*>. Interacțiunea sistemului cu aceste colecții demonstrează polimorfismul mediat de tabela de funcții virtuale. Când sistemul iterează prin baza de date pentru afișare, decizia privind funcția care trebuie apelată se ia la runtime, în funcție de adresa concretă din memorie.

Meniul interactiv permite o multitudine de funcții de gestiune precum adăugarea de conținut în vaza de date, adăugarea de clienți, de playlisturi și melodii în cadrul acestora dar și opțiuni precum modificarea abonamentelor unor clienți, căutarea de melodii după ID și ștergerea acestora sau redarea de conținut. Opțiunile sunt afișate intuitiv în terminal

Un exemplu de funcție pe care doresc să o adaug este cea de separare de conținut în funcție de abonamente, adică unele conținuturi să poată fi accesate doar de utilizatorii cu abonamente Premium. De asemenea, doresc să îmbunătățesc baza de utilizatori și să adaug funcții aferente acesteia, precum să le creez istoric de vizionare sau de achizitii (abonamente) și să îi integrez mai mult în partea de gestiune
 
