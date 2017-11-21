#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

struct{
	char nom[15];
   int cate,canti;
   float prec;
}arti[' '],venta[' '];

void pantalla();
int menu();
void tabla();
void tabla1(int aux,int aux1);
int entrada(int i);
void busqueda(int c);
void actual(int c);
int ventas(float v[' '][2],int cantv,int c);
void venttotal(float v[' '][2],int cantv);


main(){
	system("color 0B");
	int opc,cant=0,cantv=0;
   float v[' '][2];
	do{
   	clrscr();
   	pantalla();
      opc=menu();
      switch(opc){
      	case 1:
         	clrscr();
         	pantalla();
            tabla();
            cant=entrada(cant);
            break;
         case 2:
         	clrscr();
            gotoxy(8,4);cout<<"Ventas del dia";
            pantalla();
            tabla();
            cantv=ventas(v,cantv,cant);
            break;
         case 3:
            clrscr();
         	pantalla();
         	actual(cant);
         	break;
         case 4:
            clrscr();
            pantalla;
         	busqueda(cant);
         	break;
         case 5:
            clrscr();
         	pantalla();
            venttotal(v,cantv);
         case 6:
         	gotoxy(20,13);cout<<"Saliendo...";
         	break;
         default:
         	gotoxy(20,13);cout<<"Opcion Invalida";
      }
   }while(opc!=6);
   getch();
}

void pantalla(){
    int i;
	 for(i=0;i<=27;i++){
      	gotoxy(19+i,1);cout<<"*";
         gotoxy(19+i,3);cout<<"*";
    }
	 gotoxy(19,2);cout<<"* Almacen de Ropa 'Tu Luz' *"<<endl;
}

int menu(){
   int opc;
	gotoxy(20,5);cout<<"Menu de Operaciones"<<endl;
   gotoxy(20,6);cout<<"1) Agregar prenda o calzado"<<endl;
   gotoxy(20,7);cout<<"2) Ingresar Ventas"<<endl;
   gotoxy(20,8);cout<<"3) Actualizacion de precios"<<endl;
   gotoxy(20,9);cout<<"4) Busqueda"<<endl;
   gotoxy(20,10);cout<<"5) Venta total"<<endl;
   gotoxy(20,11);cout<<"6) Salir"<<endl;
   gotoxy(20,12);cout<<"Que deseas hacer: "<<endl;
   gotoxy(38,12);cin>>opc;
   return opc;
}

void tabla(){
	int i,j;
   gotoxy(8,6);cout<<"Producto";
   gotoxy(20,6);cout<<"Categoria";
   gotoxy(32,6);cout<<"Cantidad";
   gotoxy(46,6);cout<<"Precio";
   gotoxy(61,6);cout<<"Categorias";
   gotoxy(60,8);cout<<"1. Calzado";
   gotoxy(60,10);cout<<"2. Prendas";
   gotoxy(60,12);cout<<"3. Accesorios";
//---------Tabla----------------------
   for(i=1;i<=20;i++){
		for(j=1;j<=48;j++){
        	gotoxy(5+j,3+(i*2));cout<<"*";
      }
   }
   for(i=1;i<=5;i++){
		for(j=1;j<=39;j++){
        	gotoxy(-6+(i*12),4+j);cout<<"*";
      }
   }
//----------Categorias----------------
   for(i=1;i<=5;i++){
		for(j=1;j<=17;j++){
        	gotoxy(57+j,3+(i*2));cout<<"*";
      }
   }
   for(i=0;i<=1;i++){
		for(j=1;j<=8;j++){
        	gotoxy(58+(i*16),4+j);cout<<"*";
      }
   }
}

void tabla1(int aux,int aux1){
	int i,j;
	for(i=1;i<=aux;i++){
		for(j=1;j<=21;j++){
        	gotoxy(10+j,3+(i*2));cout<<"*";
      }
   }
   for(i=0;i<=2;i++){
		for(j=1;j<=aux1;j++){
        	gotoxy(11+(i*10),4+j);cout<<"*";
      }
   }
}

int entrada(int i){
   char resp;
	do{
   	gotoxy(57,15);cout<<"                        ";
   	gotoxy(8,8+(i*2));cin>>arti[i].nom;
      gotoxy(20,8+(i*2));cin>>arti[i].cate;
      gotoxy(32,8+(i*2));cin>>arti[i].canti;
      gotoxy(44,8+(i*2));cin>>arti[i].prec;
      i++;
   gotoxy(57,15);cout<<"Otro articulo?(S|N) ";
   gotoxy(77,15);cin>>resp;
   }while(resp!='n');
   return i;
}

int ventas(float v[' '][2],int cantv,int c){
	char resp;
   int i=0,tv=0,x,aux,aux1=0;
	do{
   	gotoxy(57,15);cout<<"                        ";
   	gotoxy(8,8+(i*2));cin>>venta[i].nom;
      gotoxy(32,8+(i*2));cin>>venta[i].canti;
      for(x=0;x<c;x++){
      	if(strcmp(venta[i].nom,arti[x].nom)==0){
         	arti[x].canti=arti[x].canti - venta[i].canti;
            gotoxy(46,8+(i*2));cout<<arti[x].prec;
            gotoxy(20,8+(i*2));cout<<arti[x].cate;
            aux=((venta[i].canti)*(arti[x].prec));
            aux1--;
         }
         aux1++;
      }
      if(aux1==c){
      	gotoxy(57,14);cout<<"No existe articulo";
         aux=0;
      }
      i++;
      tv=tv+aux;
   gotoxy(57,15);cout<<"Otra venta?(S|N) ";
   gotoxy(76,15);cin>>resp;
   }while(resp!='n');
   cantv++;
   gotoxy(57,17);cout<<"El total de";
   gotoxy(57,18);cout<<"tu venta es: "<<tv;
   v[(cantv-1)][0]=cantv;
   v[(cantv-1)][1]=tv;
   getch();
   return cantv;
}

void actual(int c){
   char nombre[15],resp;
   float precion;
   int i,aux=0;
   do{
   	clrscr();
      pantalla();
		gotoxy(20,5);cout<<"Nombre del articulo: ";
   	gotoxy(42,5);cin>>nombre;
   	for(i=0;i<c;i++){
   		if(strcmp(nombre,arti[i].nom)==0){
      		gotoxy(20,7);cout<<"Articulo Encontrado!";
         	gotoxy(20,8);cout<<"Ingresa nuevo precio: ";
            gotoxy(43,8);cin>>precion;
            gotoxy(20,10);cout<<"Precio anterior: $"<<arti[i].prec;
            gotoxy(20,11);cout<<"Precio nuevo: $"<<precion;
            arti[i].prec=precion;
            aux--;
      	}
         aux++;
   	}
      if(aux==c){
      	gotoxy(20,11);cout<<"No existe articulo";
      }
      gotoxy(52,5);cout<<"Hacer otra operacion?(S|N)";
      gotoxy(52,6);cin>>resp;
	}while(resp!='n');
}

void busqueda(int c){
	char nombre[15],resp;
   int cat,i,opc,aux=0,j;
   do{
   	clrscr();
      pantalla();
   	gotoxy(20,5);cout<<"Busqueda por: ";
      gotoxy(20,6);cout<<"1)Nombre";
      gotoxy(20,7);cout<<"2)Categoria";
      gotoxy(35,5);cin>>opc;
      switch(opc){
      	case 1:
         	gotoxy(20,9);cout<<"Nombre del articulo: ";
   			gotoxy(42,9);cin>>nombre;
            for(i=0;i<c;i++){
      	 		if(strcmp(nombre,arti[i].nom)==0){
          			gotoxy(20,11);cout<<"Articulo Encontrado!";
            		gotoxy(20,12);cout<<"Nombre: "<<arti[i].nom;
            		gotoxy(20,13);cout<<"Categoria: "<<arti[i].cate;
            		gotoxy(20,14);cout<<"Cantidad disponible: "<<arti[i].canti;
            		gotoxy(20,15);cout<<"Precio: "<<arti[i].prec;
                  aux--;
          		}
               aux++;
      		}
            if(aux==c){
            	gotoxy(20,11);cout<<"No existe articulo";
            }
         	break;
         case 2:
         	gotoxy(20,9);cout<<"Categoria: ";
   			gotoxy(32,9);cin>>cat;
            j=0;
            for(i=0;i<c;i++){
      	 		if(cat==arti[i].cate){
          			gotoxy(20,11+(j*5));cout<<"Nombre: "<<arti[i].nom;
            		gotoxy(20,12+(j*5));cout<<"Categoria: "<<arti[i].cate;
            		gotoxy(20,13+(j*5));cout<<"Cantidad disponible: "<<arti[i].canti;
            		gotoxy(20,14+(j*5));cout<<"Precio: "<<arti[i].prec;
                  j++;
          		}
               if(cat>3){
               	gotoxy(20,11);cout<<"Categoria invalida";
               }
      		}
            break;
         default:
         	cout<<"Opcion invalida";
            break;
      }
   	gotoxy(57,5);cout<<"Otra busqueda?(S|N) ";
      gotoxy(78,5);cin>>resp;
   }while(resp!='n');
}

void venttotal(float v[' '][2],int cantv){
   int i,vt=0,aux,aux1;
	clrscr();
   aux=cantv+1;
   aux1=(cantv*3)-1;
   pantalla();
   gotoxy(35,6);cout<<"Estas son las ventas del dia";
   tabla1(aux,aux1);
   for(i=0;i<cantv;i++){
   	gotoxy(13,6+(i*2));cout<<"Venta "<<v[i][0];
      gotoxy(23,6+(i*2));cout<<"$"<<v[i][1];
      vt=vt+v[i][1];
   }
   gotoxy(35,8);cout<<"El monto vendido";
   gotoxy(35,9);cout<<"hasta ahora es: "<<vt;
   getch();
}
