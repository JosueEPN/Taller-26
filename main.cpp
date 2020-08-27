#include <iostream>
#include <fstream>
void ordenarArreglo( float miArray[], int Dim);
void Ingresar(int Arreglo[]);
void Interpolacion(int arreglo[]);

using namespace std;

int main()
{
  int opci; 
  int Arreglo[10];
  do{
  cout << "\t\tBienvenido\n";
  cout << "1.-Ingresar\n";
  cout << "2.-Buscar\n";
  cout << "3.- Salir\n";
  cin >> opci;

  switch(opci)
  { case 1: 
      Ingresar (Arreglo);
      break;
    case 2:
      Interpolacion(Arreglo);
      break;
    case 3:
      cout<< "Salio del Sistema";
  }
}while(opci !=3);
}

void ordenarArreglo( int miArray[], int Dim)
{
  ofstream Archivodata;
	float temporal;
	
	for (int i = 0; i < Dim; i++)
  {
		for (int j = 0; j < Dim-1; j++)
    {
			if (miArray[j] > miArray[j+1])
      { 
			temporal = miArray[j]; 
			miArray[j] = miArray[j+1]; 
			miArray[j+1] = temporal;
			}
		}
	}
  Archivodata.open("Interpolacion",ios::app);
  Archivodata << "Arreglo Ordenado: {";

  for(int i=0;i<Dim;i++)
  {
    Archivodata << miArray[i] << " ";

  }
  Archivodata << "}\n";
  Archivodata.close();
}

void Ingresar(int Arreglo[])
{
  ofstream Archivodata;
  Archivodata.open("Interpolacion",ios::out);
  Archivodata << "Arreglo Ingresado: {";
  for (int i=0;i<10;i++)
  {
    cout  << "Ingrese el Elemento en la posicion " << i +1 << ": ";

    cin >> Arreglo[i];

    Archivodata << Arreglo[i] << " ";

  }
  Archivodata << "}\n";

  Archivodata.close();

  ordenarArreglo(Arreglo,10);

  
}

void Interpolacion(int arreglo[])
{
  ofstream Archivodata;
  int primero=0;
  int ultimo = 10 - 1;
  int medio;
  int contador=0;
  int numero;

  Archivodata.open("Interpolacion",ios::app);
  Archivodata << "Numero: a buscar: ";

  cout << "Ingrese el numero a buscar: ";

  cin  >> numero;
   Archivodata << numero << endl;

   while(arreglo[primero]!= numero && contador <=10)
   {
     medio=primero+((numero - arreglo[primero])*(ultimo-primero))/(arreglo[ultimo]-arreglo[primero]);

     if(arreglo[medio]<numero)
     {
       primero=medio+1;
     }else if(arreglo[medio>numero])
     {
       ultimo=medio-1;
     }else 
          primero = medio;

       contador++;
 
      }
      
  if(arreglo[primero]==numero){
   cout << "Elemento encontrado en la posicion: " << primero+1;

    Archivodata << "\nElemento encontrado en la posicion: " << primero+1 << endl;
  }
 
  else {
   cout<<"\nELEMENTO NO ENCONTRADO\n";
  Archivodata<<"\nELEMENTO NO ENCONTRADO\n";

   }
   Archivodata.close();
}