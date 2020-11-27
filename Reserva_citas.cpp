
#include <iostream>
#include <windows.h>
#include <cstring>
#include<iomanip>
#include<fstream>
#include <conio.h>
#define max 100
#define max_char 50
using namespace std;

int opcion, cant,cod,v;


//-------------Prototipos de Las funciones


//Prototipos de las funciones
void menu_principal();


//menu especialidades
void menu_especialidades();
void menucomun();

//-------------Estructuras de Madicina Interna
//medicina interna
struct datosM{
    int codigo;
    string nombres ;
    string apellidos;
    
} medicina[max], *Pmedicina = medicina;

// ....................prototipo de medicina interna
void menu_medicinainterna();
void registro_doctoresM(datosM *);
void lista_doctoresM(datosM *);
void buscar_codigoM(datosM *);
void eliminar_codigoM(datosM *);
void modificar_codigoM(datosM *);

//Declarando ficheros de medicina interna
ofstream guardarM;
ofstream tempM;
ifstream leerM;


//-------------------------------Estructuras de psicologia
//psicologia
struct datosP{
    int codigo;
    string nombres ;
    string apellidos;
    
} psicologia[max], *Ppsicologia = psicologia;

// ........................prototipo de Psicologia
void menu_psicologia();
void registro_doctoresP(datosP *);
void lista_doctoresP(datosP *);
void buscar_codigoP(datosP *);
void eliminar_codigoP(datosP *);
void modificar_codigoP(datosP *);

//Declarando ficheros de Psicologia
ofstream guardarP;
ofstream tempP;
ifstream leerP;

//----------------------------------Estructuras de Dermatologia
//Dermatologia
struct datosD{
    int codigo;
    string nombres ;
    string apellidos;
    
} dermatologia[max], *Pdermatologia = dermatologia;

// prototipo de Dermatologia
void menu_dermatologia();
void registro_doctoresD(datosD *);
void lista_doctoresD(datosD *);
void buscar_codigoD(datosD *);
void eliminar_codigoD(datosD *);
void modificar_codigoD(datosD *);

//Declarando ficheros de Dermatologia
ofstream guardarD;
ofstream tempD;
ifstream leerD;

//----------------------------------Estructuras de Endocrinologia
//Endocrinologia
struct datosE{
    int codigo;
    string nombres ;
    string apellidos;
    
} endocrinologia[max], *Pendocrinologia = endocrinologia;

// prototipo de Endocrinologia
void menu_endocrinologia();
void registro_doctoresE(datosE *);
void lista_doctoresE(datosE *);
void buscar_codigoE(datosE *);
void eliminar_codigoE(datosE *);
void modificar_codigoE(datosE *);

//Declarando ficheros de Endocrinologia
ofstream guardarE;
ofstream tempE;
ifstream leerE;

//----------------------------------Estructuras de traumatologia
//Traumatologia
struct datosT{
    int codigo;
    string nombres ;
    string apellidos;
 
} traumatologia[max], *Ptraumatologia = traumatologia;

// prototipo de Traumatologia
void menu_traumatologia();
void registro_doctoresT(datosT *);
void lista_doctoresT(datosT *);
void buscar_codigoT(datosT *);
void eliminar_codigoT(datosT *);
void modificar_codigoT(datosT *);

//Declarando ficheros de traumatologia
ofstream guardarT;
ofstream tempT;
ifstream leerT;

//---------------------------------Estructuras de Historias clinicos
//PACIENTES
struct datosH{
    int codigo;
    string nombres ;
    string apellidos;
    float costo;
    string especialidad;
} historia[max], *Phistoria = historia;

// prototipo de historias clinicas
void menucomunH();
void menu_historia();
void registro_pacientesH(datosH *);
void lista_pacientesH(datosH *);
void buscar_codigoH(datosH *);
void eliminar_codigoH(datosH *);
void modificar_codigoH(datosH *);

//Declarando ficheros de Historias Clinicas
ofstream guardarH;
ofstream tempH;
ifstream leerH;


//Declarando ficheros de Citas
ofstream guardarC;
ofstream tempC;
ifstream leerC;

void orden_codigo(datosM *, int );
void citas();
void proceso(datosH *Phistoria) ;
void buscar_codigoC(datosH *Phistoria);
void ver_citasC(datosH *Phistoria);

int main() {
	cout<<"\n\t\t\tAdministracion de LSC Diagnostics";
    cout<<"\n\n\n\n";
    system("pause");
    system ("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    menu_principal();
    getch();
	return 0;
}

/*--------------- Muestra el Menu  --------------------------*/
void menu_principal(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout <<"\n\n";
	cout <<"\t\t    ======  LSC DIAGNOSTICS ALGORITHM  ======";
    cout <<"\n\n               ";
    cout <<"\t\t   ==== ""Sistema Clinico"" ====";
    cout << "\n\n";
    cout<<"\n\t\t\t     1. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Especialidades    ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     2. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Historias clinicas ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     3. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Citas              ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     4. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Salir              ";
	cout<<endl;
	cout<<"\n\t\t\t     Ingrese opcion : ";
	
    
    do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
            
                    menu_especialidades();
                    system("cls");
                    break;
            case 2: 
                    menucomunH();
                    menu_historia();
                    system("cls");
                    break;
            case 3: citas();
                    system("cls");
                    break;
            case 4: 
			        cout<<"\nEl programa se cerrara";
					exit(1);
                    break;
                    
            default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
                     menu_principal();
			break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=4);
}

/*--------------- Muestra el Menu Especialidades  --------------------------*/
void menu_especialidades(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout << "\n\n";
	cout << "\t\t\t======  ESPECIALIDADES  ======";
    cout << "\n\n";
    cout<<"\n\t\t\t     1. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Medicina interna";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     2. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Psicologia";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     3. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Dermatologia";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     4. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Endocrinologia";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     5. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Traumatologia";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     6. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Atras";
    cout<<endl;
    cout<<"\n\t\t\t     Ingrese opcion : ";
    
    do{
        cin>>opcion;
        system("cls");
        
        switch(opcion){
            case 1: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
                    menucomun();
			        menu_medicinainterna();
                    break;
                    
            case 2: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                    
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA ======";
			        menucomun();
			        menu_psicologia();
			        break;
                    
            case 3: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                    
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
			        menucomun();
			        menu_dermatologia();
                    break;
                    
            case 4: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                    
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA  ======";
			       menucomun();
			       menu_endocrinologia();
			        break;
                    
            case 5: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                   
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA  ======";
			       menucomun();
			       menu_traumatologia();
			        break;
 
            case 6: menu_principal();
 
 
            default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
                    menu_especialidades();
			break;
            
 
        }
        system("pause");
		system("cls");
    }while(opcion!=6);
}

/*--------------- Muestra el menu comun de cada especialidad  --------------------------*/
void menucomun()
{
	cout << "\n\n";
    cout<<"\n\t\t\t     1. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Registro de Doctores";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     2. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Lista de Doctores";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     3. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Buscar Doctores";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     4. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Eliminar Doctores";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     5. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Modificar Doctores";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t     6. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Atras";
    cout<<endl;
    cout<<"\n\t\t\t     Ingrese opcion : ";
}

/*----------------------- Ordenamiento por codigo--------------------------*/
void orden_codigo(datosM *Pmedicina, int cant){
	int j=0;
	int auxcodigo;
	string auxnombres, auxapellidos;
	for(int i=1; i<cant; i++){
		auxcodigo = (Pmedicina + i)->codigo;
		auxnombres = (Pmedicina + i)->nombres;
		auxapellidos = (Pmedicina + i)->apellidos;
		j = i-1;
		
		while(j >= 0 && (Pmedicina + j)->codigo > auxcodigo ){
			(Pmedicina + j + 1)->codigo = (Pmedicina + j)->codigo;
			(Pmedicina + j + 1)->nombres = (Pmedicina + j)->nombres;
			(Pmedicina + j + 1)->apellidos = (Pmedicina + j)->apellidos;
			j--;
		}
		(Pmedicina + j + 1)->codigo = auxcodigo;
		(Pmedicina + j + 1)->nombres = auxnombres;
		(Pmedicina + j + 1)->apellidos = auxapellidos;
	}
}

/*-------------------------------------------------------------------- MENU MEDICINA INTERNA------------------------------------------------------------*/

/*-------------------- Funcion para las opciones del menu medicina interna ------------------*/
void menu_medicinainterna()
{
   do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
			        registro_doctoresM(Pmedicina);
			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
					menucomun();
					menu_medicinainterna();			        
                    break;
            case 2: 
		           	lista_doctoresM(Pmedicina);
		           	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
		           	menucomun();
					menu_medicinainterna();
                    break;
            case 3: 
                    buscar_codigoM(Pmedicina);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
                    menucomun();
                    menu_medicinainterna();
                    break;
                    
            case 4: 
                    eliminar_codigoM(Pmedicina);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
                    menucomun();
                    menu_medicinainterna();
                    break;
            
            case 5: 
                    modificar_codigoM(Pmedicina);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
                    menucomun();
                    menu_medicinainterna();
                    break;
                    
            case 6: 
                    menu_especialidades();
                    break;
            default: 
			        cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
			        menucomun();
			        menu_medicinainterna();
			        break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=6);
}

/*----------------------- Funcion para registrar doctores a Medicina interna--------------------------*/
void registro_doctoresM(datosM *Pmedicina){
	
	cout<<"\n\t\t\tCANTIDAD DE DOCTORES A REGISTRAR: "<<endl;
    cout<<"\n\t\t\t\t\t";cin>>cant;
                    
    system("cls");
    guardarM.open("Medicina.txt",ios::app);
    if(guardarM.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL ARCHIVO...\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
        menucomun();
		menu_medicinainterna();
    }
    cout<<"\n\t\t\tDigite los datos de los doctores: \n";
    for(int i=0; i<cant;i++){
        fflush(stdin);
        cout<<endl;
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\t\t\t======  REGISTRO DE DOCTORES ======";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<endl;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Codigo: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cin>>(Pmedicina + i)->codigo;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Nombre: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Pmedicina + i)->nombres);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Apellido: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Pmedicina + i)->apellidos);
        
        
        guardarM<<(Pmedicina + i)->codigo<<endl;
        guardarM<<(Pmedicina + i)->nombres<<endl;
        guardarM<<(Pmedicina + i)->apellidos<<endl;
        guardarM<<endl;
        
        getch();
        system("cls"); 
    }
    guardarM.close();
    cout<<"\n\t\t\t     REGISTRO COMPLETO!\n\n";
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion que muestra a todos los doctores registrados en medicina interna ------------------*/
void lista_doctoresM(datosM *Pmedicina){

    leerM.open("Medicina.txt",ios::in);
    if(leerM.fail()){
    	cout<<"\n\t\t\t     NO HAY DOCTORES REGISTRADOS...\n";
    	cout<<endl;
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
        menucomun();
		menu_medicinainterna();
    }
    
    leerM>>(Pmedicina)->codigo;
    cout <<"\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t  ======  LISTA DE DOCTORES ======"<<endl;
    while(!leerM.eof())
	{
            leerM>>(Pmedicina)->nombres>>(Pmedicina)->apellidos;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->nombres<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->apellidos<<endl;
            cout<<endl;
            cout<<"\t\t\t  ________________________________";
            leerM>>(Pmedicina)->codigo;
    }
    leerM.close();
    cout<<endl<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion busqueda de los doctores registrados en medicina interna ------------------*/

void buscar_codigoM(datosM *Pmedicina){
	int Bcodigo;
	
	leerM.open("Medicina.txt",ios::in);

    if(leerM.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
        menucomun();
		menu_medicinainterna();
    }
    
	leerM>>(Pmedicina)->codigo;
	bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A BUSCAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	 while(!leerM.eof()){
            leerM>>(Pmedicina)->nombres>>(Pmedicina)->apellidos;
      
            if( (Pmedicina)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  _____________________________";
            
          }
        leerM>>(Pmedicina)->codigo;
    }
    if(encontrado == false){
    	cout<<"\n\t\t\t     CODIGO NO ENCONTRADO\n"<<endl;
    }
    
    leerM.close();
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion eliminar doctores de medicina interna por codigo ------------------*/

void eliminar_codigoM(datosM *Pmedicina){
	int Bcodigo;
	
	leerM.open("Medicina.txt",ios::in);
    tempM.open("tempM.txt");
    if(leerM.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
        menucomun();
		menu_medicinainterna();
    }
    
	leerM>>(Pmedicina)->codigo;
	bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A ELIMINAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	 while(!leerM.eof()){
            leerM>>(Pmedicina)->nombres>>(Pmedicina)->apellidos;
            
            if( (Pmedicina)->codigo == Bcodigo ){
            	encontrado = true;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  CODIGO ELIMINADO EXITOSAMENTE"<<endl;
          }
          
          else{
          	tempM<<(Pmedicina)->codigo<<" ";
            tempM<<(Pmedicina)->nombres<<" ";
            tempM<<(Pmedicina)->apellidos<<endl;
          }
        leerM>>(Pmedicina)->codigo;
    }
    
    if(encontrado == false){
    cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerM.close();
    tempM.close();
    
    //Eliminando fichero original
    remove("Medicina.txt");
    
    //Cambiando los ficheros
    rename("tempM.txt","Medicina.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion Modificar doctores de medicina interna por codigo ------------------*/

void modificar_codigoM(datosM *Pmedicina){
	int Bcodigo;
	string Nnombres, Napellidos;
	
	leerM.open("Medicina.txt",ios::in);
    tempM.open("tempM.txt");
    if(leerM.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  MEDICINA INTERNA  ======";
        menucomun();
		menu_medicinainterna();
    }
    
	leerM>>(Pmedicina)->codigo;
	bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A MODIFICAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	 while(!leerM.eof()){
            leerM>>(Pmedicina)->nombres>>(Pmedicina)->apellidos;
            
            if( (Pmedicina)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pmedicina)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  ________________________________";
            cout<<endl;
            cout<<"\n\t\t\tIngresar Nuevos Datos: "<<endl;
            cout<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Nnombres;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Napellidos;
            
            tempM<<(Pmedicina)->codigo<<" ";
            tempM<<Nnombres<<" ";
            tempM<<Napellidos<<endl;
            cout<<"\n\t\t\t     SE HA MODIFICADO CORRECTAMENTE\n";
          }
          
          else{
          	tempM<<(Pmedicina)->codigo<<" ";
            tempM<<(Pmedicina)->nombres<<" ";
            tempM<<(Pmedicina)->apellidos<<endl;
          }
        leerM>>(Pmedicina)->codigo;
    }
    
    if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerM.close();
    tempM.close();
    
    //Eliminando fichero original
    remove("Medicina.txt");
    
    //Cambiando los ficheros
    rename("tempM.txt","Medicina.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------------------------------------------------------- MENU PSICOLOGIA------------------------------------------------------------*/

/*-------------------- Funcion para las opciones del menu Psicologia ------------------*/
void menu_psicologia()
{

    do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
			        registro_doctoresP(Ppsicologia);
			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
					menucomun();
					menu_psicologia();			        
                    break;
                    
            case 2: 
		           	lista_doctoresP(Ppsicologia);
		           	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
		           	menucomun();
					menu_psicologia();
                    break;
            
			case 3: 
		           	buscar_codigoP(Ppsicologia);
		           	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
		           	menucomun();
					menu_psicologia();
                    break;
					
			case 4: 
		           	eliminar_codigoP(Ppsicologia);
		           	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
		           	menucomun();
					menu_psicologia();
                    break;
			
			case 5: 
		           	modificar_codigoP(Ppsicologia);
		           	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
		           	menucomun();
					menu_psicologia();
                    break;
									        
            case 6: 
                    menu_especialidades();
                    break;
                    
            default: 
			        cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
                    menucomun();
                    menu_psicologia();
			        break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=6);
}

/*----------------------- Funcion para registrar doctores a PSICOLOGIA--------------------------*/
void registro_doctoresP(datosP *Ppsicologia){
	
	cout<<"\n\t\t\tCANTIDAD DE DOCTORES A REGISTRAR: "<<endl;
    cout<<"\n\t\t\t\t\t";cin>>cant;
                    
    system("cls");
    guardarP.open("Psicologia.txt",ios::app);
    if(guardarP.fail()){
        cout<<"\n\t\t\t     NO SE PUDO ABRIR EL ARCHIVO...\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
        menucomun();
		menu_psicologia();
    }
    cout<<"\n\t\t\tDigite los datos de los doctores: \n";
    
    for(int i=0; i<cant;i++){
        fflush(stdin);
        cout<<endl;
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\t\t\t======  REGISTRO DE DOCTORES ======";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<endl;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Codigo: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cin>>(Ppsicologia + i)->codigo;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Nombre: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Ppsicologia + i)->nombres);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Apellido: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Ppsicologia + i)->apellidos);
        
        
        guardarP<<(Ppsicologia + i)->codigo<<endl;
        guardarP<<(Ppsicologia + i)->nombres<<endl;
        guardarP<<(Ppsicologia + i)->apellidos<<endl;
        guardarP<<endl;
        getch();
        system("cls"); 
    }
    guardarP.close();
    cout<<"\n\t\t\t     REGISTRO COMPLETO!\n\n";
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion que muestra a todos los doctores registrados en PSICOLOGIA ------------------*/
void lista_doctoresP(datosP *Ppsicologia){
 

    leerP.open("Psicologia.txt",ios::in);
    if(leerP.fail()){
    	cout<<"\n\t\t\t     NO HAY DOCTORES REGISTRADOS...\n";
    	cout<<endl;
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
        menucomun();
		menu_psicologia();
    }
    
    leerP>>(Ppsicologia)->codigo;
    
    cout <<"\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t  ======  LISTA DE DOCTORES ======"<<endl;
    while(!leerP.eof())
	{
            leerP>>(Ppsicologia)->nombres>>(Ppsicologia)->apellidos;
            
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->nombres<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->apellidos<<endl;
            cout<<endl;
            cout<<"\t\t\t  ________________________________";
            leerP>>(Ppsicologia)->codigo;
    }
    
    leerP.close();
    cout<<endl<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion busqueda de los doctores registrados en PSICOLOGIA ------------------*/
void buscar_codigoP(datosP *Ppsicologia){
	
	int Bcodigo;
	
    leerP.open("Psicologia.txt",ios::in);
    
    if(leerP.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
        menucomun();
		menu_psicologia();
    }
    
    leerP>>(Ppsicologia)->codigo;
    bool encontrado = false;
    
    cout<<"\n\t\t\t    INGRESAR CODIGO A BUSCAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerP.eof()){
            
            leerP>>(Ppsicologia)->nombres>>(Ppsicologia)->apellidos;
            
            if( (Ppsicologia)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  _____________________________";
            
        }
        leerP>>(Ppsicologia)->codigo;
    }
    
     if(encontrado == false){
    	cout<<"\n\t\t\t     CODIGO NO ENCONTRADO\n"<<endl;
    }
    cout<<endl;
    cout<<endl;
    leerP.close();
    system("pause");
    system("cls");
}


/*-------------------- Funcion eliminar doctores de Psicologia por codigo ------------------*/

void eliminar_codigoP(datosP *Ppsicologia){
	
	int Bcodigo;
	
    leerP.open("Psicologia.txt",ios::in);
    tempP.open("tempP.txt");
    
    if(leerP.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
        menucomun();
		menu_psicologia();
    }
    
    leerP>>(Ppsicologia)->codigo;
    bool encontrado = false;
    
    cout<<"\n\t\t\t    INGRESAR CODIGO A ELIMINAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerP.eof()){
            
            leerP>>(Ppsicologia)->nombres>>(Ppsicologia)->apellidos;
            
            if( (Ppsicologia)->codigo == Bcodigo ){
            	encontrado = true;
            	
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  CODIGO ELIMINADO EXITOSAMENTE"<<endl;
            
        }
        
        else{
          	tempP<<(Ppsicologia)->codigo<<" ";
            tempP<<(Ppsicologia)->nombres<<" ";
            tempP<<(Ppsicologia)->apellidos<<endl;
          }
        
        leerP>>(Ppsicologia)->codigo;
    }
    
     if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerP.close();
    tempP.close();
    
    //Eliminando fichero original
    remove("Psicologia.txt");
    
    //Cambiando los ficheros
    rename("tempP.txt","Psicologia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion Modificar doctores de Psicologia por codigo ------------------*/

void modificar_codigoP(datosP *Ppsicologia){
	
	int Bcodigo;
	string Nnombres, Napellidos;
	
    leerP.open("Psicologia.txt",ios::in);
    tempP.open("tempP.txt");
    
    if(leerP.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  PSICOLOGIA  ======";
        menucomun();
		menu_psicologia();
    }
    
    leerP>>(Ppsicologia)->codigo;
    bool encontrado = false;
    
    cout<<"\n\t\t\t    INGRESAR CODIGO A MODIFICAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerP.eof()){
            
            leerP>>(Ppsicologia)->nombres>>(Ppsicologia)->apellidos;
            
            if( (Ppsicologia)->codigo == Bcodigo ){
            	encontrado = true;
            	
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  ________________________________";
            cout<<endl;
            cout<<"\n\t\t\tIngresar Nuevos Datos: "<<endl;
            cout<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Nnombres;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Napellidos;
            
            tempP<<(Ppsicologia)->codigo<<" ";
            tempP<<Nnombres<<" ";
            tempP<<Napellidos<<endl;
            cout<<"\n\t\t\t     SE HA MODIFICADO CORRECTAMENTE\n";
        }
        
        else{
          	tempP<<(Ppsicologia)->codigo<<" ";
            tempP<<(Ppsicologia)->nombres<<" ";
            tempP<<(Ppsicologia)->apellidos<<endl;
          }
        
        leerP>>(Ppsicologia)->codigo;
    }
    
     if(encontrado == false){
    cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerP.close();
    tempP.close();
    
    //Eliminando fichero original
    remove("Psicologia.txt");
    
    //Cambiando los ficheros
    rename("tempP.txt","Psicologia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------------------------------------------------------- MENU DERMATOLOGIA------------------------------------------------------------*/

/*-------------------- Funcion para las opciones del menu Dermatologia ------------------*/
void menu_dermatologia()
{

    do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
			        registro_doctoresD(Pdermatologia);
			         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
					menucomun();
					menu_dermatologia();			        
                    break;
            case 2: 
		           	lista_doctoresD(Pdermatologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
		           	menucomun();
					menu_dermatologia();
                    break;
            
            case 3: 
		           	buscar_codigoD(Pdermatologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
		           	menucomun();
					menu_dermatologia();
                    break;
            
            case 4: 
		           	eliminar_codigoD(Pdermatologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
		           	menucomun();
					menu_dermatologia();
                    break;
            
            case 5: 
		           	modificar_codigoD(Pdermatologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
		           	menucomun();
					menu_dermatologia();
                    break;
            case 6: 
                    menu_especialidades();
                    break;
                    
            default: 
			        cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
			         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA ======";
                    menucomun();
                    menu_dermatologia();
			        break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=6);
}

/*----------------------- Funcion para registrar doctores a dermatologia--------------------------*/
void registro_doctoresD(datosD *Pdermatologia){
	
    cout<<"\n\t\t\tCANTIDAD DE DOCTORES A REGISTRAR: "<<endl;
    cout<<"\n\t\t\t\t\t";cin>>cant;
                    
    system("cls");
    guardarD.open("Dermatologia.txt",ios::app);
    if(guardarD.fail()){
    	cout<<"No se pudo abrir el archivo";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA ======";
        menucomun();
		menu_dermatologia();
    }
    cout<<"\n\t\t\tDigite los datos de los doctores: \n";
    
    for(int i=0; i<cant;i++){
        fflush(stdin);
        cout<<endl;
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\t\t\t======  REGISTRO DE DOCTORES ======";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<endl;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Codigo: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cin>>(Pdermatologia + i)->codigo;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Nombre: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Pdermatologia + i)->nombres);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Apellido: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Pdermatologia + i)->apellidos);
        
        
        guardarD<<(Pdermatologia + i)->codigo<<endl;
        guardarD<<(Pdermatologia + i)->nombres<<endl;
        guardarD<<(Pdermatologia + i)->apellidos<<endl;
        getch();
        system("cls"); 
    }
    guardarD.close();
    cout<<"\n\t\t\t     REGISTRO COMPLETO!\n\n";
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion que muestra a todos los doctores registrados en dermatologia ------------------*/
void lista_doctoresD(datosD *Pdermatologia){
	
    leerD.open("Dermatologia.txt",ios::in);
    if(leerD.fail()){
    	cout<<"\n\t\t\t     NO HAY DOCTORES REGISTRADOS...\n";
    	cout<<endl;
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
        menucomun();
		menu_dermatologia();
    }
    
    leerD>>(Pdermatologia)->codigo;
    cout <<"\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t  ======  LISTA DE DOCTORES ======"<<endl;
    
    while(!leerD.eof()){
    	
    	leerD>>(Pdermatologia)->nombres>>(Pdermatologia)->apellidos;
            
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->nombres<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->apellidos<<endl;
            cout<<endl;
            cout<<"\t\t\t  ________________________________";
            leerD>>(Pdermatologia)->codigo;
            
    }
    leerD.close();
    cout<<endl<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion busqueda de los doctores registrados en Dermatologia ------------------*/

void buscar_codigoD(datosD *Pdermatologia){
	
	int Bcodigo;
	
    leerD.open("Dermatologia.txt",ios::in);
    
    if(leerD.fail()){
    		cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
        menucomun();
		menu_dermatologia();
    }
    
    leerD>>(Pdermatologia)->codigo;
    bool encontrado = false;
    
      cout<<"\n\t\t\t    INGRESAR CODIGO A BUSCAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerD.eof()){
    	
    	leerD>>(Pdermatologia)->nombres>>(Pdermatologia)->apellidos;
         
         if( (Pdermatologia)->codigo == Bcodigo ){
            	encontrado = true;
            	
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  _____________________________";
            
        }
        
        leerD>>(Pdermatologia)->codigo;
    }
    
    if(encontrado == false){
    cout<<"\n\t\t\t     CODIGO NO ENCONTRADO\n"<<endl;
    }
    cout<<endl<<endl;
    leerD.close();
    system("pause");
    system("cls");
}

/*-------------------- Funcion eliminar doctores de Dermatologia por codigo ------------------*/

void eliminar_codigoD(datosD *Pdermatologia){
	
	int Bcodigo;
	
    leerD.open("Dermatologia.txt",ios::in);
    tempD.open("tempD.txt");
    
    if(leerD.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
        menucomun();
		menu_dermatologia();
    }
    
    leerD>>(Pdermatologia)->codigo;
    bool encontrado = false;
    
     cout<<"\n\t\t\t    INGRESAR CODIGO A ELIMINAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerD.eof()){
    	
    	leerD>>(Pdermatologia)->nombres>>(Pdermatologia)->apellidos;
         
         if( (Pdermatologia)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  CODIGO ELIMINADO EXITOSAMENTE"<<endl;
        }
        
        else{
          	tempD<<(Pdermatologia)->codigo<<" ";
            tempD<<(Pdermatologia)->nombres<<" ";
            tempD<<(Pdermatologia)->apellidos<<endl;
          }
          
        leerD>>(Pdermatologia)->codigo;
    }
    
    if(encontrado == false){
    		cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerD.close();
    tempD.close();
    
    //Eliminando fichero original
    remove("Dermatologia.txt");
    
    //Cambiando los ficheros
    rename("tempD.txt","Dermatologia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion Modificar doctores de Dermatologia por codigo ------------------*/
void modificar_codigoD(datosD *Pdermatologia){
	
	int Bcodigo;
	string Nnombres, Napellidos;
	
    leerD.open("Dermatologia.txt",ios::in);
    tempD.open("tempD.txt");
    
    if(leerD.fail()){
    cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  DERMATOLOGIA  ======";
        menucomun();
		menu_dermatologia();
    }
    
    leerD>>(Pdermatologia)->codigo;
    bool encontrado = false;
    
     cout<<"\n\t\t\t    INGRESAR CODIGO A MODIFICAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerD.eof()){
    	
    	leerD>>(Pdermatologia)->nombres>>(Pdermatologia)->apellidos;
         
         if( (Pdermatologia)->codigo == Bcodigo ){
            	encontrado = true;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ppsicologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pdermatologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  ________________________________";
            cout<<endl;
            cout<<"\n\t\t\tIngresar Nuevos Datos: "<<endl;
            cout<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Nnombres;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Napellidos;
            
            tempD<<(Pdermatologia)->codigo<<" ";
            tempD<<Nnombres<<" ";
            tempD<<Napellidos<<endl;
            
             cout<<"\n\t\t\t     SE HA MODIFICADO CORRECTAMENTE\n";
        }
        
        else{
          	tempD<<(Pdermatologia)->codigo<<" ";
            tempD<<(Pdermatologia)->nombres<<" ";
            tempD<<(Pdermatologia)->apellidos<<endl;
          }
          
        leerD>>(Pdermatologia)->codigo;
    }
    
    if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerD.close();
    tempD.close();
    
    //Eliminando fichero original
    remove("Dermatologia.txt");
    
    //Cambiando los ficheros
    rename("tempD.txt","Dermatologia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}


/*-------------------------------------------------------------------- MENU ENDOCRINOLOGIA------------------------------------------------------------*/

/*-------------------- Funcion para las opciones del menu Endocrinologia ------------------*/
void menu_endocrinologia()
{

    do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
			        registro_doctoresE(Pendocrinologia);
			         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA  ======";
					menucomun();
					menu_endocrinologia();			        
                    break;
            case 2: 
		           	lista_doctoresE(Pendocrinologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA   ======";
		           	menucomun();
					menu_endocrinologia();
                    break;
            case 3: 
		           	buscar_codigoE(Pendocrinologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA   ======";
		           	menucomun();
					menu_endocrinologia();
                    break;
            case 4: 
		           	eliminar_codigoE(Pendocrinologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA   ======";
		           	menucomun();
					menu_endocrinologia();
                    break;
            case 5: 
		           	modificar_codigoE(Pendocrinologia);
		           	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA   ======";
		           	menucomun();
					menu_endocrinologia();
                    break;
            case 6: 
                    menu_especialidades();
                    break;
                    
            default: 
			        cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
			         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA ======";
			        break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=3);
}

/*----------------------- Funcion para registrar doctores a Endocrinologia--------------------------*/
void registro_doctoresE(datosE *Pendocrinologia){
	
 cout<<"\n\t\t\tCANTIDAD DE DOCTORES A REGISTRAR: "<<endl;
    cout<<"\n\t\t\t\t\t";cin>>cant;
                    
    system("cls");
    guardarE.open("Endocrinologia.txt",ios::app);
    if(guardarE.fail()){
    	cout<<"No se pudo abrir el archivo";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA ======";
        menucomun();
		menu_endocrinologia();
    }
    cout<<"\n\t\t\tDigite los datos de los doctores: \n";
    for(int i=0; i<cant;i++){
        fflush(stdin);
        cout<<endl;
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\t\t\t======  REGISTRO DE DOCTORES ======";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<endl;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Codigo: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cin>>(Pendocrinologia + i)->codigo;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Nombre: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Pendocrinologia + i)->nombres);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Apellido: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Pendocrinologia + i)->apellidos);
        
        guardarE<<(Pendocrinologia + i)->codigo<<" ";
        guardarE<<(Pendocrinologia + i)->nombres<<" ";
        guardarE<<(Pendocrinologia + i)->apellidos<<endl;
        getch();
        system("cls"); 
    }
    guardarE.close();
    cout<<"\n\t\t\t     REGISTRO COMPLETO!\n\n";
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion que muestra a todos los doctores registrados en Endocrinologia ------------------*/
void lista_doctoresE(datosE *Pendocrinologia){

    leerE.open("Endocrinologia.txt",ios::in);
    
    if(leerE.fail()){
    	cout<<"\n\t\t\t     NO HAY DOCTORES REGISTRADOS...\n";
    	cout<<endl;
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA  ======";
        menucomun();
		menu_endocrinologia();
    }
    
    leerE>>(Pendocrinologia)->codigo;
    cout <<"\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t  ======  LISTA DE DOCTORES ======"<<endl;
    while(!leerE.eof()){
            leerE>>(Pendocrinologia)->nombres>>(Pendocrinologia)->apellidos;
            
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->nombres<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->apellidos<<endl;
            cout<<endl;
            cout<<"\t\t\t  ________________________________";
            leerE>>(Pendocrinologia)->codigo;
    }
    leerE.close();
    cout<<endl<<endl;
    system("pause");
    system("cls");
}


/*-------------------- Funcion busqueda de los doctores registrados en Endocrinologia ------------------*/

void buscar_codigoE(datosE *Pendocrinologia){

    int Bcodigo;
	 
    leerE.open("Endocrinologia.txt",ios::in);
    
    if(leerE.fail()){
    		cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA  ======";
        menucomun();
		menu_endocrinologia();
    }
    
    leerE>>(Pendocrinologia)->codigo;
    bool encontrado = false;
    
    cout<<"\n\t\t\t    INGRESAR CODIGO A BUSCAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerE.eof()){
            leerE>>(Pendocrinologia)->nombres>>(Pendocrinologia)->apellidos;
            
            if( (Pendocrinologia)->codigo == Bcodigo ){
            	
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  _____________________________";
        }
        
            leerE>>(Pendocrinologia)->codigo;
    }
    
    if(encontrado == false){
    cout<<"\n\t\t\t     CODIGO NO ENCONTRADO\n"<<endl;
    }
    cout<<endl<<endl;
    leerE.close();
    system("pause");
    system("cls");
}

/*-------------------- Funcion eliminar doctores de Endocrinologia por codigo ------------------*/

void eliminar_codigoE(datosE *Pendocrinologia){

    int Bcodigo;
	 
    leerE.open("Endocrinologia.txt",ios::in);
    tempE.open("tempE.txt");
    
    if(leerE.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA  ======";
        menucomun();
		menu_endocrinologia();
    }
    
    leerE>>(Pendocrinologia)->codigo;
    bool encontrado = false;
    
     cout<<"\n\t\t\t    INGRESAR CODIGO A ELIMINAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerE.eof()){
            leerE>>(Pendocrinologia)->nombres>>(Pendocrinologia)->apellidos;
            
            if( (Pendocrinologia)->codigo == Bcodigo ){
            	
            	encontrado = true;
            	
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  CODIGO ELIMINADO EXITOSAMENTE"<<endl;
        }
        
        else{
          	tempE<<(Pendocrinologia)->codigo<<" ";
            tempE<<(Pendocrinologia)->nombres<<" ";
            tempE<<(Pendocrinologia)->apellidos<<endl;
          }
        
            leerE>>(Pendocrinologia)->codigo;
    }
    
    if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerE.close();
    tempE.close();
    
    //Eliminando fichero original
    remove("Endocrinologia.txt");
    
    //Cambiando los ficheros
    rename("tempE.txt","Endocrinologia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion Modificar doctores de Endocrinologia por codigo ------------------*/

void modificar_codigoE(datosE *Pendocrinologia){

    int Bcodigo;
	 string Nnombres, Napellidos;
	 
    leerE.open("Endocrinologia.txt",ios::in);
    tempE.open("tempE.txt");
    
    if(leerE.fail()){
    cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  ENDOCRINOLOGIA  ======";
        menucomun();
		menu_endocrinologia();
    }
    
    leerE>>(Pendocrinologia)->codigo;
    bool encontrado = false;
    
    cout<<"\n\t\t\t    INGRESAR CODIGO A MODIFICAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerE.eof()){
            leerE>>(Pendocrinologia)->nombres>>(Pendocrinologia)->apellidos;
            
            if( (Pendocrinologia)->codigo == Bcodigo ){
            	
            	encontrado = true;
            	
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Pendocrinologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  ________________________________";
            cout<<endl;
            cout<<"\n\t\t\tIngresar Nuevos Datos: "<<endl;
            cout<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Nnombres;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Napellidos;
            
            tempE<<(Pendocrinologia)->codigo<<" ";
            tempE<<Nnombres<<" ";
            tempE<<Napellidos<<endl;
            cout<<"\n\t\t\t     SE HA MODIFICADO CORRECTAMENTE\n";
            
        }
        
        else{
          	tempE<<(Pendocrinologia)->codigo<<" ";
            tempE<<(Pendocrinologia)->nombres<<" ";
            tempE<<(Pendocrinologia)->apellidos<<endl;
          }
        
            leerE>>(Pendocrinologia)->codigo;
    }
    
    if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerE.close();
    tempE.close();
    
    //Eliminando fichero original
    remove("Endocrinologia.txt");
    
    //Cambiando los ficheros
    rename("tempE.txt","Endocrinologia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}


/*-------------------------------------------------------------------- MENU TRAUMATOLOGIA------------------------------------------------------------*/

/*-------------------- Funcion para las opciones del menu traumatologia ------------------*/
void menu_traumatologia()
{

    do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
			        registro_doctoresT(Ptraumatologia);
			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA ======";
					menucomun();
					menu_traumatologia();			        
                    break;
            case 2: 
		           	lista_doctoresT(Ptraumatologia);
		           	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA ======";
		           	menucomun();
					menu_traumatologia();
                    break;
            
			case 3: 
                    buscar_codigoT(Ptraumatologia);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA ======";
                    menucomun();
					menu_traumatologia();
                    break;
                    
            case 4: 
                    eliminar_codigoT(Ptraumatologia);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA ======";
                    menucomun();
					menu_traumatologia();
                    break;
            
            case 5: 
                    modificar_codigoT(Ptraumatologia);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA ======";
                    menucomun();
					menu_traumatologia();
                    break;       
            
            case 6: 
                    menu_especialidades();
                    break;
                    
            default: 
			        cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA ======";
                    menucomun();
                    menu_traumatologia();
			        break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=6);
}

/*----------------------- Funcion para registrar doctores a Traumatologia--------------------------*/
void registro_doctoresT(datosT *Ptraumatologia){
	
 cout<<"\n\t\t\tCANTIDAD DE DOCTORES A REGISTRAR: "<<endl;
    cout<<"\n\t\t\t\t\t";cin>>cant;
                    
    system("cls");
    guardarT.open("Traumatologia.txt",ios::app);
    if(guardarT.fail()){
    	cout<<"No se pudo abrir el archivo";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA ======";
        menucomun();
		menu_traumatologia();
    }
   cout<<"\n\t\t\tDigite los datos de los doctores: \n";
    for(int i=0; i<cant;i++){
        fflush(stdin);
        cout<<endl;
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\t\t\t======  REGISTRO DE DOCTORES ======";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<endl;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Codigo: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cin>>(Ptraumatologia + i)->codigo;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Nombre: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Ptraumatologia + i)->nombres);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Apellido: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Ptraumatologia + i)->apellidos);
        
        
        guardarT<<(Ptraumatologia + i)->codigo<<" ";
        guardarT<<(Ptraumatologia + i)->nombres<<" ";
        guardarT<<(Ptraumatologia + i)->apellidos<<endl;
        
        getch();
        system("cls"); 
        
    }
    guardarT.close();
    cout<<"\n\t\t\t     REGISTRO COMPLETO!\n\n";
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion que muestra a todos los doctores registrados en TRAUMATOLOGIA ------------------*/
void lista_doctoresT(datosT *Ptraumatologia){
	
    leerT.open("Traumatologia.txt",ios::in);
    
    if(leerT.fail()){
    		cout<<"\n\t\t\t     NO HAY DOCTORES REGISTRADOS...\n";
    	cout<<endl;
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA  ======";
        menucomun();
		menu_traumatologia();
    }
    
    leerT>>(Ptraumatologia)->codigo;
    cout <<"\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t  ======  LISTA DE DOCTORES ======"<<endl;
    while(!leerT.eof()){
            leerT>>(Ptraumatologia)->nombres>>(Ptraumatologia)->apellidos;
            
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->nombres<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->apellidos<<endl;
            cout<<endl;
            cout<<"\t\t\t  ________________________________";
            leerT>>(Ptraumatologia)->codigo;
            
    }
    leerT.close();
    cout<<endl<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion busqueda de los doctores registrados en TRAUMATOLOGIA ------------------*/
void buscar_codigoT(datosT *Ptraumatologia){
	
	int Bcodigo;
	
    leerT.open("Traumatologia.txt",ios::in);
    
    if(leerT.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA  ======";
        menucomun();
		menu_traumatologia();
    }
    
    leerT>>(Ptraumatologia)->codigo;
    
    bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A BUSCAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerT.eof()){
    	
            leerT>>(Ptraumatologia)->nombres>>(Ptraumatologia)->apellidos;
      
            if( (Ptraumatologia)->codigo == Bcodigo ){
            	encontrado = true;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  _____________________________"; 
            
          }
        leerT>>(Ptraumatologia)->codigo;
            
    }
    
    if(encontrado == false){
     cout<<"\n\t\t\t     CODIGO NO ENCONTRADO\n"<<endl;
    }
    cout<<endl<<endl;
    leerT.close();
    system("pause");
    system("cls");
}

/*-------------------- Funcion eliminar doctores de TRAUMATOLOGIA por codigo ------------------*/

void eliminar_codigoT(datosT *Ptraumatologia){
	
	int Bcodigo;
	
    leerT.open("Traumatologia.txt",ios::in);
    tempT.open("tempT.txt");
    
    if(leerT.fail()){
    		cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA  ======";
        menucomun();
		menu_traumatologia();
    }
    
    leerT>>(Ptraumatologia)->codigo;
    
    bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A ELIMINAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerT.eof()){
    	
            leerT>>(Ptraumatologia)->nombres>>(Ptraumatologia)->apellidos;
      
            if( (Ptraumatologia)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  CODIGO ELIMINADO EXITOSAMENTE"<<endl;
          }
          
          else{
          	tempT<<(Ptraumatologia)->codigo<<" ";
            tempT<<(Ptraumatologia)->nombres<<" ";
            tempT<<(Ptraumatologia)->apellidos<<endl;
          }
          
        leerT>>(Ptraumatologia)->codigo;
            
    }
    
    if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerT.close();
    tempT.close();
    
    //Eliminando fichero original
    remove("Traumatologia.txt");
    
    //Cambiando los ficheros
    rename("tempT.txt","Traumatologia.txt");
    cout<<endl<<endl;
    
    system("pause");
    system("cls");
}


/*-------------------- Funcion Modificar doctores de TRAUMATOLOGIA por codigo ------------------*/

void modificar_codigoT(datosT *Ptraumatologia){
	
	int Bcodigo;
	string Nnombres, Napellidos;
	
    leerT.open("Traumatologia.txt",ios::in);
    tempT.open("tempT.txt");
    
    if(leerT.fail()){
    cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	                cout <<"\n\n";
                    cout <<"\t\t\t======  TRAUMATOLOGIA  ======";
        menucomun();
		menu_traumatologia();
    }
    
    leerT>>(Ptraumatologia)->codigo;
    
    bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A MODIFICAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	
    while(!leerT.eof()){
    	
            leerT>>(Ptraumatologia)->nombres>>(Ptraumatologia)->apellidos;
      
            if( (Ptraumatologia)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Ptraumatologia)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  ________________________________";
            cout<<endl;
            cout<<"\n\t\t\tIngresar Nuevos Datos: "<<endl;
            cout<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Nnombres;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Napellidos;
            
            tempT<<(Ptraumatologia)->codigo<<" ";
            tempT<<Nnombres<<" ";
            tempT<<Napellidos<<endl;
            
            cout<<"\n\t\t\t     SE HA MODIFICADO CORRECTAMENTE\n";
          }
          
          else{
          	tempT<<(Ptraumatologia)->codigo<<" ";
            tempT<<(Ptraumatologia)->nombres<<" ";
            tempT<<(Ptraumatologia)->apellidos<<endl;
          }
          
        leerT>>(Ptraumatologia)->codigo;
            
    }
    
    if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerT.close();
    tempT.close();
    
    //Eliminando fichero original
    remove("Traumatologia.txt");
    
    //Cambiando los ficheros
    rename("tempT.txt","Traumatologia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------------------------------------------------------- MENU HISTORIAS CLINICAS------------------------------------------------------------*/

/*--------------- Muestra el menu de HISTORIAS CLINICAS  --------------------------*/
void menucomunH(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout << "\n\n";
	cout << "\t\t\t======  HISTORIAS CLINICAS  ======";
    cout << "\n\n";
    cout<<"\n\t\t\t      1. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Registro de Pacientes";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t      2. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Lista de Pacientes";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t      3. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Buscar";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t      4. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Eliminar";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t      5. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Modificar";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t      6. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Atras";
    cout<<endl;
    cout<<"\n\t\t\t     Ingrese opcion : ";
}

/*-------------------- Funcion para las opciones del HISTORIAS CLINICAS ------------------*/
void menu_historia()
{

    do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
			        registro_pacientesH(Phistoria);
			        menucomunH();
					menu_historia();			        
                    break;
            case 2: 
		           	lista_pacientesH(Phistoria);
		           	menucomunH();
					menu_historia();
                    break;
                    
            case 3: 
                    buscar_codigoH(Phistoria);
                    menucomunH();
					menu_historia();
                    break;
                    
            case 4: 
                    eliminar_codigoH(Phistoria);
                    menucomunH();
					menu_historia();
                    break;
            
            case 5: 
                    modificar_codigoH(Phistoria);
                    menucomunH();
					menu_historia();
                    break;
            case 6: 
                    menu_principal();
                    break;
                    
            default: 
			        cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
	                menucomunH();
	                menu_historia();
			        break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=6);
}

/*----------------------- Funcion para registrar pacientes a historia clinicas--------------------------*/
void registro_pacientesH(datosH *Phistoria){
	
	cout<<"\n\t\t\tCANTIDAD DE PACIENTES A REGISTRAR: "<<endl;
    cout<<"\n\t\t\t\t\t";cin>>cant;
                    
    system("cls");
    guardarH.open("Historia.txt",ios::app);
    if(guardarH.fail()){
    	cout<<"No se pudo abrir el archivo";
    	system("pause");
        system("cls");
        menucomunH();
		menu_historia();
    }
    cout<<"\n\t\t\tDigite los datos de los pacientes: \n";
    cout<<endl;
    for(v=0; v<cant;v++){
        fflush(stdin);
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\t\t\t======  REGISTRO DE PACIENTES ======";
        cout<<endl;
        fflush(stdin);
        cout<<"\n\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cin>>(Phistoria + v)->codigo;
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Nombres: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Phistoria + v)->nombres);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<"\n\t\t\t  Apellidos: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        getline(cin,(Phistoria + v)->apellidos);
        
        
        guardarH<<(Phistoria + v)->codigo<<" ";
        guardarH<<(Phistoria + v)->nombres<<" ";
        guardarH<<(Phistoria + v)->apellidos<<endl;
        
        getch();
        system("cls"); 
    }
    guardarH.close();
    cout<<"\n\t\t\t     REGISTRO COMPLETO!\n\n";
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion que muestra a todos los pacientes registrados en historia clinica ------------------*/
void lista_pacientesH(datosH *Phistoria){

    leerH.open("Historia.txt",ios::in);
    if(leerH.fail()){
    	cout<<"\n\t\t\t     NO HAY PACIENTES REGISTRADOS...\n";
        cout<<endl;
    	system("pause");
        system("cls");
        menucomunH();
		menu_historia();
    }
    
    leerH>>(Phistoria)->codigo;
    cout <<"\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t  ======  LISTA DE PACIENTES ======"<<endl;
    while(!leerH.eof()){
            leerH>>(Phistoria)->nombres>>(Phistoria)->apellidos;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<endl;
            cout<<"\n\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\n\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->nombres<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\n\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->apellidos<<endl;
            cout<<endl;
             cout<<endl;
            cout<<"\t\t\t  ________________________________";
            leerH>>(Phistoria)->codigo;
            
    }
    leerH.close();
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion busqueda de los pacientes registrados en Historias clinicas ------------------*/

void buscar_codigoH(datosH *Phistoria){
	int Bcodigo;
	
	leerH.open("Historia.txt",ios::in);

    if(leerH.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        menucomunH();
		menu_historia();
    }
    
	leerH>>(Phistoria)->codigo;
	bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A BUSCAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	 while(!leerH.eof()){
            leerH>>(Phistoria)->nombres>>(Phistoria)->apellidos;
      
            if( (Phistoria)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  _____________________________"; 
            
          }
        leerH>>(Phistoria)->codigo;
    }
    if(encontrado == false){
    cout<<"\n\t\t\t     CODIGO NO ENCONTRADO\n"<<endl;
    }
    
    leerH.close();
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion eliminar pacientes de historia clinica por codigo ------------------*/

void eliminar_codigoH(datosH *Phistoria){
	int Bcodigo;
	
	leerH.open("Historia.txt",ios::in);
    tempH.open("tempH.txt");
    
    if(leerH.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        menucomunH();
		menu_historia();
    }
    
	leerH>>(Phistoria)->codigo;
	bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A ELIMINAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	 while(!leerH.eof()){
            leerH>>(Phistoria)->nombres>>(Phistoria)->apellidos;
            
            if( (Phistoria)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  CODIGO ELIMINADO EXITOSAMENTE"<<endl;;
          }
          
          else{
          	tempH<<(Phistoria)->codigo<<" ";
            tempH<<(Phistoria)->nombres<<" ";
            tempH<<(Phistoria)->apellidos<<endl;
          }
        leerH>>(Phistoria)->codigo;
    }
    
    if(encontrado == false){
    		cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerH.close();
    tempH.close();
    
    //Eliminando fichero original
    remove("Historia.txt");
    
    //Cambiando los ficheros
    rename("tempH.txt","Historia.txt");
     cout<<endl<<endl;
    system("pause");
    system("cls");
}

/*-------------------- Funcion Modificar doctores de medicina interna por codigo ------------------*/

void modificar_codigoH(datosH *Phistoria){
	int Bcodigo;
	string Nnombres, Napellidos;
	
	leerH.open("Historia.txt",ios::in);
    tempH.open("tempH.txt");
    
    if(leerH.fail()){
    	cout<<"\n\t\t\t     NO SE PUDO ABRIR EL FICHERO\n";
    	system("pause");
        system("cls");
        menucomunH();
		menu_historia();
    }
    
	leerH>>(Phistoria)->codigo;
	bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A MODIFICAR "<<endl;
	cout<<"\n\t\t\t\t\t";cin>>Bcodigo;
	cout<<endl<<endl;
	 while(!leerH.eof()){
            leerH>>(Phistoria)->nombres>>(Phistoria)->apellidos;
            
            if( (Phistoria)->codigo == Bcodigo ){
            	
            	encontrado = true;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->codigo<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->nombres<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<(Phistoria)->apellidos<<endl;
            cout<<endl;  
            cout<<"\t\t\t  ________________________________";
            cout<<endl;
            cout<<"\n\t\t\tIngresar Nuevos Datos: "<<endl;
            cout<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo nombre: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Nnombres;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\t\t\t  Nuevo apellido: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cin>>Napellidos;
            
            tempH<<(Phistoria)->codigo<<" ";
            tempH<<Nnombres<<" ";
            tempH<<Napellidos<<endl;
            
          cout<<"\n\t\t\t     SE HA MODIFICADO CORRECTAMENTE\n";
          }
          
          else{
          	tempH<<(Phistoria)->codigo<<" ";
            tempH<<(Phistoria)->nombres<<" ";
            tempH<<(Phistoria)->apellidos<<endl;
          }
        leerH>>(Phistoria)->codigo;
    }
    
    if(encontrado == false){
    	cout<<"\n\t\t\t    CODIGO NO ENCONTRADO "<<endl;
    }
    
    leerH.close();
    tempH.close();
    
    //Eliminando fichero original
    remove("Historia.txt");
    
    //Cambiando los ficheros
    rename("tempH.txt","Historia.txt");
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}



void citas()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout << "\n\n";
	cout << "\t\t\t     ======  CITAS ======";
    cout << "\n\n";
    cout<<"\n\t\t\t      1. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Proceso";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t      2. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Ver Registro";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t      3. ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<"Atras";
    cout<<endl;
    cout<<"\n\t\t\t     Ingrese opcion : ";
    
	 do{
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
            
                    proceso(Phistoria);
                    citas();
                    break;
            case 2: 
                    ver_citasC(Phistoria);
                    citas();
                    break;
            case 3: menu_principal();
                    break;
           
            default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; 
                     citas();
			break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=3);

}

void proceso(datosH *Phistoria) 

{ 

	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n\t\t\t ===ESPECIALIDADES=== \t\t COSTO "<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t 1.";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<" Medicina interna "<<setw(18);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<" S/ 40.00"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t 2.";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<" Psicologia "<<setw(24);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<" S/ 25.00"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);  
    cout<<"\t\t\t 3.";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<" Dermatologia "<<setw(22);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<" S/ 90.00"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t 4.";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<" Endocrinologia "<<setw(20);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<" S/ 80.00"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t 5.";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<" Traumatologia  "<<setw(21);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);cout<<" S/ 100.00"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t 6.";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<" Atras   "<<endl;
	cout<<endl;
	
		
		
    do{
    	cout<<"\t\t    Elija una de las especialidades : ";
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: 
			        cout<<"\n\t\t\t  Usted ha elegido Medicina interna"<<endl;
			        
			        (Phistoria)->costo = 40.00;
			        (Phistoria)->especialidad = "Medicina_interna";
                    buscar_codigoC(Phistoria);
                    
                    citas();
                    break;
                    
            case 2: 
                    cout<<"\n\t\t\t  Usted ha elegido Psicologia"<<endl;
			        
			        (Phistoria)->costo = 25.00;
			        (Phistoria)->especialidad = "Psicologia";
                    buscar_codigoC(Phistoria);
                    citas();
			        break;
                    
            case 3: 
                    cout<<"\n\t\t\t  Usted ha elegido Dermatologia"<<endl;
			        
			        (Phistoria)->costo = 90.00;
			        (Phistoria)->especialidad = "Dermatologia";
                    buscar_codigoC(Phistoria);
                    citas();
                    break;
                    
            case 4: 
                    cout<<"\n\t\t\t  Usted ha elegido Endocrinologia"<<endl;
			        
			        (Phistoria)->costo = 80.00;
			        (Phistoria)->especialidad = "Endocrinologia";
                    buscar_codigoC(Phistoria);
                    citas();
			        break;
                    
            case 5: 
                    cout<<"\n\t\t\t  Usted ha elegido Traumatologia"<<endl;
			        
			        (Phistoria)->costo = 100.00;
			        (Phistoria)->especialidad = "Traumatologia";
                    buscar_codigoC(Phistoria);
                    citas();
			        break;
 
            case 6: citas();
 
 
            default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
 
        }
        system("pause");
		system("cls");
    }while(opcion!=6);
		
		
		
	}
	
	void buscar_codigoC(datosH *Phistoria){
	
	int Bcodigo;
	
	guardarC.open("Citas.txt",ios::app);
	leerH.open("Historia.txt",ios::in);
	

    if(leerH.fail()){
    	cout<<"\n\nNo se pudo abrir el fichero...\n";
    	system("pause");
        system("cls");
        citas();
    }
    
	leerH>>(Phistoria)->codigo;
	bool encontrado = false;
	
	cout<<"\n\t\t\t    INGRESAR CODIGO A BUSCAR "<<endl;
	cout<<"\n\t\t\t\t    ";cin>>Bcodigo;
	cout<<endl<<endl;
	
	 while(!leerH.eof()){
            leerH>>(Phistoria)->nombres>>(Phistoria)->apellidos;
      
            if( (Phistoria)->codigo == Bcodigo ){
            	encontrado = true;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);	
            cout<<"\t\tEl costo a pagar del paciente  ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->nombres<<" "<<(Phistoria)->apellidos<<" sera : "<<(Phistoria)->costo<<endl;
            guardarC<<(Phistoria)->codigo<<" ";
            guardarC<<(Phistoria)->nombres<<" ";
            guardarC<<(Phistoria)->apellidos<<" ";
            guardarC<<(Phistoria)->costo<<" ";
            guardarC<<(Phistoria)->especialidad<<endl;
            cout<<endl;  
            
          }
        leerH>>(Phistoria)->codigo;
    }
    if(encontrado == false){
    	cout<<"\nCodigo no encontrado"<<endl;
    }
    
    leerH.close();
    guardarC.close();
    system("pause");
    system("cls");
}
	
void ver_citasC(datosH *Phistoria){
		
		leerC.open("Citas.txt",ios::in);
		
		if(leerC.fail()){
    	cout<<"\n\nNO HAY CITAS REGISTRADAS...\n";
    	system("pause");
        system("cls");
        citas();
		menu_historia();
    }
    
    leerC>>(Phistoria)->codigo;
    cout <<"\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\t\t\t  ======  LISTA DE CITAS ======"<<endl;
    while(!leerC.eof()){
            leerC>>(Phistoria)->nombres>>(Phistoria)->apellidos>>(Phistoria)->costo>>(Phistoria)->especialidad;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout <<"\n\n";
            cout<<"\t\t\t  Codigo: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->codigo;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\n\t\t\t  Nombre: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->nombres;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\n\t\t\t  Apellido: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->apellidos;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\n\t\t\t  Costo: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->costo;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\n\t\t\t  Especialidad: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);cout<<(Phistoria)->especialidad;
            cout<<endl;
            cout<<"\t\t\t  _____________________________"; 
            leerC>>(Phistoria)->codigo;
            
    }
    leerC.close();
    cout<<endl<<endl;
    system("pause");
    system("cls");
	}
	
	

