/*
Leonardo Alvarado Menéndez A01705998
POO Segundo avance
En este programa creas uno o varios usuarios, desde estos puedes acceder a su biblioteca de juegos, puedes agregar juegos o ver las caracteristicas de los que ya tienes
Nota1: De momento solo se puede usar los tres juegos que puse al final del UML, aunque en realidad podrias agregar todos los juegos que quierieras.
Nota2: En esta entega unicamente coloque la clase padre Juegos y una de sus herencias "Halo" ya que con estas se cumplia lo pedido,
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
        string mostrar_datos();
};

Juegos::Juegos(){
    nombre="";
    resenia="";
    diseniador="";
    requisitos_basicos="";
}

Juegos::Juegos(string new_nom, string new_res, string new_dis, string new_r_b){
    nombre=new_nom;
    resenia=new_res;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
}

string Juegos::mostrar_datos(){
    string salida;
    salida= nombre +"\n"+ resenia +"\n"+ diseniador +"\n"+ requisitos_basicos ;
    return salida;
}

class Halo:public Juegos{
    private:
        string num_niveles;
        string dificultad;
    public:
        Halo();
        Halo(string new_nom, string new_res, string new_dis, string new_r_b, string new_num_niv, string new_dif);
        string mostrar_datos();
};

Halo::Halo(){
    nombre="Halo";
    resenia="Mejor juego";
    diseniador="Bungi";
    requisitos_basicos="4ram";
    num_niveles="12";
    dificultad="media";
}

Halo::Halo(string new_nom, string new_res, string new_dis, string new_r_b, string new_num_niv, string new_dif){
    nombre=new_nom;
    resenia=new_res;
    diseniador=new_dis;
    requisitos_basicos=new_r_b;
    num_niveles=new_num_niv;
    dificultad=new_dif;
}

string Halo::mostrar_datos(){
    string salida;
    salida= nombre +"\n"+ resenia +"\n"+ diseniador +"\n"+ requisitos_basicos +"\n"+ num_niveles +"\n"+ dificultad;
    return salida;
}

int main()
{
    Halo l;
    cout << l.mostrar_datos();
    return 0;
}
