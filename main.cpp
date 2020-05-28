/*
Leonardo Alvarado Menéndez A01705998
POO Segundo avance
En este programa creas uno o varios usuarios, desde estos puedes acceder a su biblioteca de juegos, puedes agregar juegos o ver las caracteristicas de los que ya tienes
Nota1: De momento solo se puede usar los tres juegos que puse al final del UML, aunque en realidad podrias agregar todos los juegos que quierieras.
Nota2: En esta entega unicamente coloque la clase padre Juegos y sus herencias ya que con estas se cumplia lo pedido,
para entregas futuras implementare de manera completa las otras clases.
Nota3: Cambie un poco el UML
*/
#include <iostream>
#include <string>
using namespace std;

class Juegos{
    protected:
        string nombre;
        string resenia;
        string diseniador;
        string requisitos_basicos;
    public:
        Juegos();
        Juegos(string, string, string, string);
        virtual void mostrar_datos();
};

Juegos::Juegos(){
    nombre="Nombre";
    resenia="Resenia";
    diseniador="Diseniador";
    requisitos_basicos="Requisitos";
}

Juegos::Juegos(string new_nom, string new_res, string new_dis, string new_r_b){
    nombre=new_nom;
    resenia=new_res;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
}

void Juegos::mostrar_datos(){
    cout << nombre << endl;
    cout << resenia << endl;
    cout << diseniador << endl;
    cout << requisitos_basicos << endl;
}

class Halo:public Juegos{
    private:
        int num_niveles;
        string dificultad;
    public:
        Halo();
        Halo(string new_nom, string new_res, string new_dis, string new_r_b, int new_num_niv, string new_dif);
        void mostrar_datos();
};

Halo::Halo(){
    nombre="Halo";
    resenia="Halo murio en reach";
    diseniador="Bungie";
    requisitos_basicos="2 RAM";
    num_niveles=12;
    dificultad="media";
}

Halo::Halo(string new_nom, string new_res, string new_dis, string new_r_b, int new_num_niv, string new_dif){
    nombre=new_nom;
    resenia=new_res;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
    num_niveles=new_num_niv;
    dificultad=new_dif;
}

void Halo::mostrar_datos(){
    cout << "Nombre: " << nombre << endl;
    cout << "Resenia: " <<  resenia << endl;
    cout << "Diseniador: " << diseniador << endl;
    cout << "Requisitos: " << requisitos_basicos << endl;
    cout << "Numero de niveles: " << num_niveles << endl;
    cout << "Dificultad: " << dificultad << endl;
}

class FIFA:public Juegos{
    private:
        int numero_estadios;
        int numero_equipos;
    public:
        FIFA();
        FIFA(string new_nom, string new_res, string new_dis, string new_r_b, int new_num_est, int new_num_eqp);
        void mostrar_datos();
};

FIFA::FIFA(){
    nombre="FIFA 2013";
    resenia="El mismo juego de cada anio";
    diseniador="EA";
    requisitos_basicos="4 RAM";
    numero_estadios=200;
    numero_equipos=200;
}

FIFA::FIFA(string new_nom, string new_res, string new_dis, string new_r_b, int new_num_est, int new_num_eqp){
    nombre=new_nom;
    resenia=new_res;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
    numero_estadios=new_num_est;
    numero_equipos=new_num_eqp;
}

void FIFA::mostrar_datos(){
    cout << "Nombre del juego: " << nombre << endl;
    cout << "Resenia: " << resenia << endl;
    cout << "Diseniador: " << diseniador << endl;
    cout << "Requisitos: " << requisitos_basicos << endl;
    cout << "Numero de estadios: " << numero_estadios << endl;
    cout << "Numero de equipos: " << numero_equipos << endl;
}

class Mortal_Kombat:public Juegos{
    private:
        int num_personajes;
        int num_fatalities;
    public:
        Mortal_Kombat();
        Mortal_Kombat(string new_nom, string new_res, string new_dis, string new_r_b, int new_num_per, int new_num_fat);
        void mostrar_datos();
};

Mortal_Kombat::Mortal_Kombat(){
    nombre="Mortal Kombat X";
    resenia="Mismo juego, nueva historia";
    diseniador="NetherRealm Studios";
    requisitos_basicos="6 RAM";
    num_personajes=40;
    num_fatalities=80;
}

Mortal_Kombat::Mortal_Kombat(string new_nom, string new_res, string new_dis, string new_r_b, int new_num_per, int new_num_fat){
    nombre=new_nom;
    resenia=new_res;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
    num_personajes=new_num_per;
    num_fatalities=new_num_fat;
}

void Mortal_Kombat::mostrar_datos(){
    cout << "Nombre del juego: " << nombre << endl;
    cout << "Resenia: " << resenia << endl;
    cout << "Diseniador: " << diseniador << endl;
    cout << "Requisitos: " << requisitos_basicos << endl;
    cout << "Numero de personajes: " << num_personajes << endl;
    cout << "Numero de fatalities: " << num_fatalities << endl;
}

int main()
{
    Juegos *Juegos[3];
    Juegos[0]= new Halo;
    Juegos[1] = new FIFA;
    Juegos[2] = new Mortal_Kombat;
    for (int i = 0;i<3;i++){
        Juegos[i]->mostrar_datos();
        cout << endl;
    }
    delete Juegos;
    return 0;
}
