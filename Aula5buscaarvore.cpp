#include "search_tree.h"

void SearchTree::destroyTree(NodeType*& tree)
{
  if (tree != NULL)
    {
      destroyTree(tree->esquerda);
      destroyTree(tree->direita);
      delete tree;
    }
}

bool SearchTree::isEmpty() const {
  return root == NULL;
}
bool SearchTree::isFull() const {
  NodeType* location;
  try
    {
      location = new NodeType;
      delete location;
      return false;
    }
  catch(std::bad_alloc exception)
    {
      return true;
    }
}

void SearchTree::retrieveAluno(NodeType* tree,
			       Aluno& aluno,
			       bool& found) const {
  if (tree == NULL)
    found = false;
  else if (aluno.getRa() < tree->aluno.getRa())
    retrieveAluno(tree->esquerda, aluno, found);
  else if (aluno.getRa() > tree->aluno.getRa())
    retrieveAluno(tree->direita, aluno, found);
  else {
    aluno = tree->aluno;
    found = true;
  }
}

void SearchTree::insertAluno(NodeType*& tree, Aluno aluno)
{
  if (tree == NULL)
    {
      tree = new NodeType;
      tree->direita  = NULL;
      tree->esquerda = NULL;
      tree->aluno    = aluno;
    }
  else if (aluno.getRa() < tree->aluno.getRa() )
    insertAluno(tree->esquerda, aluno);
  else
    insertAluno(tree->direita, aluno);
}

void SearchTree::deleteAluno(NodeType*& tree, int aluno)
{
  if (aluno < tree->aluno.getRa() )
    deleteAluno(tree->esquerda, aluno);
  else if (aluno > tree->aluno.getRa() )
    deleteAluno(tree->direita, aluno); 
  else if (aluno == tree->aluno.getRa())
    deleteNode(tree);
}

void SearchTree::deleteNode(NodeType*& tree) {   
  Aluno data;
  NodeType* tempPtr;
  tempPtr = tree;
  if (tree->esquerda == NULL) {
    tree = tree->direita;
    delete tempPtr;
  }
  else if (tree->direita == NULL) {
    tree = tree->esquerda;
    delete tempPtr;
  }
  else {
    getSuccessor(tree, data);
    tree->aluno = data;
    deleteAluno(tree->direita, data.getRa());
  }
}

void SearchTree::getSuccessor(NodeType* tree, Aluno& data)
{
  tree = tree->direita;
  while (tree->esquerda != NULL)
    tree = tree->esquerda;
  data = tree->aluno;
}

void SearchTree::printPreOrder(NodeType* tree) const {
  if (tree != NULL) {
      std::cout << tree->aluno.getNome() << " , ";
      printPreOrder(tree->esquerda);
      printPreOrder(tree->direita);
    }
}

void SearchTree::printInOrder(NodeType* tree) const {
  if (tree != NULL) {
	printInOrder(tree->esquerda);
	std::cout << tree->aluno.getNome() << " , ";
	printInOrder(tree->direita);
    }
}
void SearchTree::printPostOrder(NodeType* tree) const {
  if (tree != NULL) {
	printPostOrder(tree->esquerda);
	printPostOrder(tree->direita);
	std::cout << tree->aluno.getNome() << " , ";
    }
}

#include "search_tree.h"
using namespace std;

const int NUM_ALUNOS = 8;

int main() {
  SearchTree searchTree;

  int ras[NUM_ALUNOS] = {20, 18, 58, 7, 19, 26, 25, 30};     
  string nomes[NUM_ALUNOS] = {
    "Pedro", "Raul", "Paulo",
    "Carlos", "Lucas", "Maria",
    "Samanta", "ulisses"};
  Aluno alunos[NUM_ALUNOS];

  for (int i = 0; i < NUM_ALUNOS; i++){
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunos[i] = aluno;
    searchTree.insertAluno(aluno);
  }

  cout << "Pre:  ";
  searchTree.printPreOrder();
  cout << endl;
  cout << "In:   ";
  searchTree.printInOrder();
  cout << endl;
  cout << "Post: ";
  searchTree.printPostOrder();
  cout << endl;

  // Removendo aluno na raiz;
  searchTree.deleteAluno(alunos[0].getRa());
  cout << "********" << endl;
  cout << "Pre:  ";
  searchTree.printPreOrder();
  cout << endl;
  cout << "In:   ";
  searchTree.printInOrder();
  cout << endl;
  cout << "Post: ";
  searchTree.printPostOrder();
  cout << endl;
}
#include <cstddef>
#include <iostream>
#include "aluno.h"

/*
  Estrutura usada para 
  guardar a informação 
  e os endereços das
  subárvores
 */
struct NodeType
{
  Aluno aluno;
  NodeType* esquerda;
  NodeType* direita;
};


/*
  A classe SearchTree é a que irá gerenciar todas as 
  funções da árvore de busca. Você notará que essa 
  árvore foi implementada com várias funções recursivas 
  privadas e várias funções públicas que simplesmente 
  invocam as funções privadas e fornecem algum valor 
  para o parâmetro como ponto de partida.
 */
class SearchTree
{
 public:  
  SearchTree() { root = NULL;  }  
  ~SearchTree(){ destroyTree(root); }
  bool isEmpty() const;
  bool isFull() const;
  void retrieveAluno(Aluno& item, bool& found) const{
    retrieveAluno(root, item, found);
  }
  void insertAluno(Aluno item){ insertAluno(root, item); }  
  void deleteAluno(int item){ deleteAluno(root, item); }
  void printPreOrder()  const { printPreOrder(root); }
  void printInOrder()   const { printInOrder(root);  }
  void printPostOrder() const { printPostOrder(root);}
     
 private:
  void destroyTree(NodeType*& tree);
  void retrieveAluno(NodeType* tree,
		     Aluno& item,
		     bool& found) const;
  void insertAluno(NodeType*& tree, Aluno item);
  void deleteAluno(NodeType*& tree, int item);     
  void deleteNode(NodeType*& tree); 
  void getSuccessor(NodeType* tree, Aluno& data);
  void printTree(NodeType *tree) const;  
  void printPreOrder(NodeType* tree)  const;
  void printInOrder(NodeType* tree)   const;
  void printPostOrder(NodeType* tree) const;  
  //  Raiz da árvore binária de busca.
  NodeType* root;
};
