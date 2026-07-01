# include<iostream>
# include<cstdlib>
#include "estetico.h"
using namespace std;

void pausa(){
cout<<endl;
rlutil::setColor(rlutil::YELLOW);
cout<<">>PRESIONE UNA TECLA PARA VOLVER<<";
rlutil::setColor(rlutil::WHITE);
rlutil::anykey();

}
void centrar(int renglon){
rlutil::locate(48,10+renglon);
}

void textoLargo(int renglon){
rlutil::locate(44,10+renglon);
}
void negro(){
rlutil::setColor(rlutil::BLACK);
}
void blanco(){
rlutil::setColor(rlutil::WHITE);
}
void rojo(){
rlutil::setColor(rlutil::RED);
}
void amarillo(){
rlutil::setColor(rlutil::YELLOW);
}
void violeta(){
rlutil::setColor(rlutil::RED);
}
