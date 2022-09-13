#include <iostream>

int main() {
  int c[10] = {14, 0, 13};
  
  c[5] = 30;
  c[7] = 40;
  c[8] = 50;

  for (int i = 0; i < 10; i++) {
    std::cout << "c[" << i << "] = " << c[i] << "\n";
  }  
  return 0;
}
const int NUM_ELEM = 10;

int main() {
  int c[NUM_ELEM];
  for (int i = 0; i < NUM_ELEM; i++) {
    c[i] = 2*i;
  }
  for (int i = 0; i < NUM_ELEM; i++) {
    std::cout << "c[" << i << "] = " << c[i] << "\n";
  }  
  return 0;
}
int main() {
  int num_elem;
  std::cout << "Digite o tamanho do vetor: ";
  std::cin >> num_elem;
  
  int* c = new int[num_elem];
  
  for (int i = 0; i < num_elem; i++) {
    c[i] = 2*i;
  }
  for (int i = 0; i < num_elem; i++) {
    std::cout << "c[" << i << "] = " << c[i] << "\n";
  }

  delete [] c;
  
  return 0;
}
void valor_alocando_memoria(int* p)
{
  p = new int;
  *p = 7;
}
void valor_modificando_memoria(int* p)
{
  *p = 8;
}
void referencia(int*& p)
{
  p = new int;
  *p = 9;
}

int main()
{
  int a  = 1;
  int b  = 2;
  int c  = 3; 
  int* p1 = &a;
  int* p2 = &b;
  int* p3 = &c;

  cout <<"Antes: "<<  p1 <<" "<<  p2 <<" "<<  p3 << endl;
  cout <<"Antes: "<< *p1 <<" "<< *p2 <<" "<< *p3 << endl;
  cout << endl;
  
  valor_alocando_memoria(p1); 
  valor_modificando_memoria(p2);
  referencia(p3);  

  cout << "Depois: "<<  p1 <<" "<<  p2 <<" "<<  p3 << endl;
  cout << "Depois: "<< *p1 <<" "<< *p2 <<" "<< *p3 << endl;
  cout << "Depois: "<< a <<" "<< b <<" "<< c << endl;

  return 0;
}
void modifica_vetor_sintaxe_1(int b[], int num_elem)
{
  for (int i = 0; i < num_elem; i++){
    b[i] = b[i] * 2;
  }
}

void modifica_vetor_sintaxe_2(int* b, int num_elem)
{
  for (int i = 0; i < num_elem; i++){
    b[i] = b[i] * 2;
  }
}

void vetor_const_sintaxe_1(const int* b, int num_elem) 
{
  // Corpo sem alterar os elementos do vetor
}

void vetor_const_sintaxe_2(const int b[], int num_elem) 
{
  // Corpo sem alterar os elementos do vetor
}


const int NUM_ELEM = 10;
int main()
{
  // Alocação Estática
  int c[NUM_ELEM] = {1,2,3,4,5,6,7,8,9,10};

  // Alocação Dinâmica
  int *d = new int[NUM_ELEM];
  for (int i = 0; i < NUM_ELEM; i++){
    d[i] = i + 1;
  }
  
  modifica_vetor_sintaxe_1(c, NUM_ELEM);
  modifica_vetor_sintaxe_2(c, NUM_ELEM);

  modifica_vetor_sintaxe_1(d, NUM_ELEM);
  modifica_vetor_sintaxe_2(d, NUM_ELEM);

  for (int i = 0; i < NUM_ELEM; i++){
    std::cout << i << " : " << c[i] << " , " << d[i] << std::endl;
  }
  return 0;
}
