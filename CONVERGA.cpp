#include <iostream>
#include <conio.h>

using namespace std;

int* Ingresar(int);
void Union(int*,int*,int,int);
void Interseccion(int*,int*,int,int);
void Diferencia(int*,int*,int,int);
void DiferenciaSimetrica(int*,int*,int,int);

int main(){

	int numVal,numVal2,aux=0;

	cout << "Introduce el numero de valores del conjunto A: ";
	cin >> numVal;
	
	cout << "Introduce el numero de valores del conjunto B: ";
	cin >> numVal2;

	int *A,*B;

	cout << "Datos A:"<<endl;
	A = Ingresar(numVal);
	cout <<endl<<endl;
	cout << "Datos B:"<<endl;
	B = Ingresar(numVal2);
	cout <<endl<<endl;

	cout << " A U B: ";
	Union(A,B,numVal,numVal2);

	cout << " A Y B: ";
	Interseccion(A,B,numVal,numVal2);

	cout << " A - B: ";
	Diferencia(A,B,numVal,numVal2);
	cout <<endl<<endl;

	cout << " A (+) B: ";
	DiferenciaSimetrica(A,B,numVal,numVal2);


}

int* Ingresar(int size){
	int *array;
	array = new int[size];

	for(int i = 0; i < size; i++){
		cout << "Introduce el dato de la posicion ["<<i<<"] : ";
		cin >> array[i];cin.ignore();
	}
	return array;
}

void Union(int *a, int *b, int size_a, int size_b){
	int final[20], aux = 0;

	for(int i =0; i < (size_a+size_b); i++){
		if(i<size_a){
			final[i] = a[i];
		}else{
			final[i] = b[aux];
			aux++;
		}
	}

	for (int i = 0; i < (size_a+size_b); i++)
		cout << final[i] << " ";
	cout <<endl<<endl;
}

void Interseccion(int *a, int *b, int size_a, int size_b){
	int final[20], aux = 0;

	for(int i=0; i < size_a;i++){
		for(int j=0; j < size_b;j++){
			if(a[i]==b[j]){
				final[aux] = a[i];
				aux++;
			}
		}
	}

	for (int i = 0; i < aux; ++i)
		cout << final[i] << " ";
	cout <<endl<<endl;

}

void Diferencia(int *a, int *b, int size_a, int size_b){
	int final[20], aux[20], cont = 0, cont2 = 0;

	for(int i=0; i < size_a;i++){
		for(int j=0; j < size_b;j++){
			if(a[i]==b[j]){
				aux[cont] = a[i];
				cont++;
			}
		}
	}
	
	for (int i = 0; i < size_a; i++){
		final[cont2] = a[i];
				cont2++;
	}
	for(int i = 0; i < cont2; i++){
		for(int j=0; j < cont;j++){
			if( final[i] == aux[j]){
				final[i] = 0;
			}
		}
	}

	for (int i = 0; i < cont2; i++){
		if( final[i]!=0){
		cout << final[i] << " ";
		}
	}

}

void DiferenciaSimetrica(int *a, int *b, int size_a, int size_b){
	
	Diferencia(a,b,size_a,size_b);

	Diferencia(b,a,size_b,size_a);

	cout <<endl<<endl;
}