/*
Leonardo Alvarado Menéndez A01705998
POO cuarto avanze
En este programa creas uno o varios usuarios, desde estos puedes acceder a su biblioteca de juegos, puedes agregar juegos o ver las caracteristicas de los que ya tienes
Nota1: De momento solo se puede usar los tres juegos que puse al final del UML, aunque en realidad podrias agregar todos los juegos que quierieras.
Nota2: En esta entega unicamente coloque la clase padre Juego, sus herencias y la biblioteca ya que con estas se cumplia lo pedido,
para entregas futuras implementare de manera completa las otras clases.
Nota3: Cambie un poco el UML
*/
#include <iostream>
#include <string>
using namespace std;

class Juegos{
    protected:
        string nombre;
        string diseniador;
        string requisitos_basicos;
    public:
        Juegos();
        Juegos(string, string, string);
        virtual void mostrar_datos()=0;
        string get_nombre();
};

Juegos::Juegos(){
    nombre="Nombre";
    diseniador="Diseniador";
    requisitos_basicos="Requisitos";

}

Juegos::Juegos(string new_nom, string new_dis, string new_r_b){
    nombre=new_nom;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
}

string Juegos::get_nombre(){
    return nombre;
}

class Halo:public Juegos{
    private:
        int num_niveles;
        string dificultad;
    public:
        Halo();
        Halo(string new_nom, string new_dis, string new_r_b, int new_num_niv, string new_dif);
        void mostrar_datos();
};

Halo::Halo(){
    nombre="Halo";
    diseniador="Bungie";
    requisitos_basicos="2 RAM";
    num_niveles=12;
    dificultad="media";
}

Halo::Halo(string new_nom, string new_dis, string new_r_b, int new_num_niv, string new_dif){
    nombre=new_nom;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
    num_niveles=new_num_niv;
    dificultad=new_dif;
}

void Halo::mostrar_datos(){
    cout << "Nombre: " << nombre << endl;
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
        FIFA(string new_nom, string new_dis, string new_r_b, int new_num_est, int new_num_eqp);
        void mostrar_datos();
};

FIFA::FIFA(){
    nombre="FIFA 2013";
    diseniador="EA";
    requisitos_basicos="4 RAM";
    numero_estadios=200;
    numero_equipos=200;
}

FIFA::FIFA(string new_nom, string new_dis, string new_r_b, int new_num_est, int new_num_eqp){
    nombre=new_nom;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
    numero_estadios=new_num_est;
    numero_equipos=new_num_eqp;
}

void FIFA::mostrar_datos(){
    cout << "Nombre del juego: " << nombre << endl;
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
        Mortal_Kombat(string new_nom, string new_dis, string new_r_b, int new_num_per, int new_num_fat);
        void mostrar_datos();
};

Mortal_Kombat::Mortal_Kombat(){
    nombre="Mortal Kombat X";
    diseniador="NetherRealm Studios";
    requisitos_basicos="6 RAM";
    num_personajes=40;
    num_fatalities=80;
}

Mortal_Kombat::Mortal_Kombat(string new_nom, string new_dis, string new_r_b, int new_num_per, int new_num_fat){
    nombre=new_nom;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
    num_personajes=new_num_per;
    num_fatalities=new_num_fat;
}

void Mortal_Kombat::mostrar_datos(){
    cout << "Nombre del juego: " << nombre << endl;
    cout << "Diseniador: " << diseniador << endl;
    cout << "Requisitos: " << requisitos_basicos << endl;
    cout << "Numero de personajes: " << num_personajes << endl;
    cout << "Numero de fatalities: " << num_fatalities << endl;
}

class Biblioteca{
    private:
        Juegos *catalogo_juegos[3];
        int indice_catalogo;
    public:
        Biblioteca();
        Biblioteca(Juegos *_catalogo_juegos[3]);
        void aniadir_juego(Juegos *_catalogo_juegos);
        void mostrar_juego();
};

Biblioteca::Biblioteca(){
    indice_catalogo=0;
}

Biblioteca::Biblioteca(Juegos *_catalogo_juegos[3]){
    for (int i=0;i<3;i++){
        if (_catalogo_juegos[i]->get_nombre()==""){
            indice_catalogo=i-1;
            break;
        }
        catalogo_juegos[i]=_catalogo_juegos[i];
    }
}

void Biblioteca::aniadir_juego(Juegos *_catalogo_juegos){
    catalogo_juegos[indice_catalogo]=_catalogo_juegos;
    indice_catalogo++;
}

void Biblioteca::mostrar_juego(){
    for (int i=0;i<3;i++){
        if (catalogo_juegos[i]->get_nombre()==""){
            break;
        }
        catalogo_juegos[i]->mostrar_datos();
    }
}

int main()
{

    Juegos *Juegos[3];
    Juegos[0]= new Halo;
    Juegos[1] = new FIFA;
    Juegos[2] = new Mortal_Kombat;
    Biblioteca b;
    for (int i=0;i<3;i++){
        b.aniadir_juego(Juegos[i]);
    }
    b.mostrar_juego();
    delete Juegos;
    return 0;
}
