# FÉLÉVES FELADAT #

-GAUSS-JORDAN OMP-

- OpenMp: Gauss-Jordan elimináció egyenletrendszerek megoldására "nxm" es mátrix. 
- Szekvenciális és omp megoldások összehasonlítása: 
- Megfigyelhető, hogy minnél nagyobb a mátrix annál nagyobb gyorsítást érhetünk el párhuzamosítással.
- A grafikon gauss_jordan.jpg néven található meg. Az ehhez tartozó adatok a gaussjordan mappán belül data.csv néven található.

-IFINITY-NORM PTHREAD/PYTHON-

- Egy "nxn" es mátrix végtelen normájának kiszámítása szekvenciális és pthread felhasználásával valamint python multithreadinget használva.
- Kevés elemszámnál megfigyelhető hogy nem éri meg túl sok threadet létrehozni mivel ez időveszteséghez vezet, viszont minnél nagyobb a mátrix mérete annál hatékonyabb több szállal dolgozni. A kisebb elemű méréseket a "few_oc.jpg" tartalmazza, a nagyobb méretűeket pedig "infnorm_oc.jpg".
- A pythonban megvalósított multithreading nagyon lassúnak bizonyult, igen magas időkülömbségek jöttek ki. A grafikon a mérésekről: "python_c.jpg".
- Ellenben a pypy fordítót használva a c pthread-hez hasonló adatokat kapunk. Grafikon: "python_pypy".
