# Platformă de Streaming - Sistem de Gestiune (C++ OOP)

Acest proiect este o aplicație C++ (Console-based) menită să simuleze sistemul de backend al unei platforme de streaming (tip Netflix/Spotify)

## Funcționalități principale:
### 1. Managementul Conținutului Media
Platforma suportă mai multe tipuri de conținut, fiecare cu proprietăți specifice:
* **Filme:** Stochează detalii precum rezoluția (ex: 4K, 1080p), format ratio și rating-ul.
* **Melodii:** Gestionează genul muzical, calitatea audio (bitrate) și disponibilitatea unui videoclip.
* **Videoclipuri Muzicale:** O fuziune între film și melodie, adăugând informații despre regizor și album.

### 2. Gestiunea Utilizatorilor și a Abonamentelor
* Crearea de utilizatori noi asociați cu diferite planuri tarifare.
* **Abonament Standard:** Acces de bază la platformă.
* **Abonament Premium:** Beneficii extra (calitate 4K, vizionare pe mai multe ecrane, acces la avanpremiere).
* Posibilitatea de a **modifica/upgrada** abonamentul unui utilizator în timp real.

### 3. Sistem de Playlist-uri Globale
* Administratorul poate crea playlist-uri personalizate.
* Orice fișier media încărcat pe server poate fi adăugat într-o colecție prin intermediul ID-ului său unic, generat automat de sistem.
  
Totul este controlat printr-un meniu intuitiv, direct în consolă. 

* **Moștenire și Ierarhie:** Există o clasă de bază `ContinutMedia` din care derivă `ContinutFilm` și `ContinutMelodie`. Clasa `VideoclipMuzical` folosește *moștenirea multiplă* pentru a prelua caracteristici din ambele.
* **Polimorfism:** Fiecare tip de conținut știe cum să se afișeze corect, indiferent de context, datorită funcțiilor virtuale.
* **Managementul Sigur al Memoriei:** Fiecare clasă are constructori de copiere, operatori de atribuire și destructori bine definiți. 
* **Tratarea Excepțiilor:** Erorile (cum ar fi introducerea de date invalide) sunt gestionate elegant prin clasa personalizată `ExceptiePlatforma`, prevenind blocarea bruscă a programului.
