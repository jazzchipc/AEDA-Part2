// -*- Mode: c++; --*-

/**
 * @file BST.h
 */

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <class Comparable>
class BSTItrIn;

template <class Comparable>
class BSTItrPre;

template <class Comparable>
class BSTItrPost;

template <class Comparable>
class BSTItrLevel;

template <class Comparable>
class BST;

template <class Comparable>
class BinaryNode
{
  Comparable element;
  BinaryNode *left;
  BinaryNode *right;

  BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
    : element( theElement ), left( lt ), right( rt ) { }

  friend class BST<Comparable>;
  friend class BSTItrIn<Comparable>;
  friend class BSTItrPre<Comparable>;
  friend class BSTItrPost<Comparable>;
  friend class BSTItrLevel<Comparable>;
};

template <class Comparable>
class BST
{
 public:
  explicit BST( const Comparable & notFound );
  BST( const BST & rhs );
  ~BST( );

  const Comparable & findMin( ) const;
  const Comparable & findMax( ) const;
  const Comparable & find( const Comparable & x ) const;
  bool isEmpty( ) const;
  void printTree( ) const;

  void makeEmpty( );
  void insert( const Comparable & x );
  void remove( const Comparable & x );

  const BST & operator=( const BST & rhs );

 private:
  BinaryNode<Comparable> *root;
  const Comparable ITEM_NOT_FOUND;

  const Comparable & elementAt( BinaryNode<Comparable> *t ) const;

  void insert( const Comparable & x, BinaryNode<Comparable> * & t ) const;
  void remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
  BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
  BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
  BinaryNode<Comparable> * find( const Comparable & x, BinaryNode<Comparable> *t ) const;
  void makeEmpty( BinaryNode<Comparable> * & t ) const;
  void printTree( BinaryNode<Comparable> *t ) const;
  BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;

  friend class BSTItrIn<Comparable>;
  friend class BSTItrPre<Comparable>;
  friend class BSTItrPost<Comparable>;
  friend class BSTItrLevel<Comparable>;
};

// Note that all "matching" is based on the < method.

/**
 * @brief Construtor: Cria uma BST que vai armazenar variáveis do tipo "Comparable"
 *
 * @param notFound Elemento "Comparable", que representará uma variável não encontrada
 */
template <class Comparable>
BST<Comparable>::BST( const Comparable & notFound ) :
  root(NULL), ITEM_NOT_FOUND( notFound )
{ }


/**
 * @brief Construtor: Cria uma BST, que é uma cópia de outra BST
 *
 * @param rhs Ávore da qual se quer fazer cópia
 */
template <class Comparable>
BST<Comparable>::BST( const BST<Comparable> & rhs ) : root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
{
  *this = rhs;
}

/**
 * @brief Destrutor: Elimina uma BST
 */
template <class Comparable>
BST<Comparable>::~BST( )
{
  makeEmpty( );
}

/**
 * @brief Insere um elemento da mesma classe que a BST, de forma a manter a ordenação
 *
 * @param x Elemento a inserir
 */
template <class Comparable>
void BST<Comparable>::insert( const Comparable & x )
{
  insert( x, root );
}

/**
 * @brief Remove um elemento da BST, compensando a sua eliminação de forma a manter a ordenação
 *
 * @param x Elemento a remover
 */
template <class Comparable>
void BST<Comparable>::remove( const Comparable & x )
{
  remove( x, root );
}

/**
 * @brief Procura e retorna o menor elemento da árvore, segundo o operador "<" da classe "Comparable"
 *
 * @return Menor elemento da BST
 */
template <class Comparable>
const Comparable & BST<Comparable>::findMin( ) const
{
  return elementAt( findMin( root ) );
}

/**
 * @brief Procura e retorna o maior elemento da árvore, segundo o operador "<" da classe "Comparable"
 *
 * @return Maior elemento da BST
 */
template <class Comparable>
const Comparable & BST<Comparable>::findMax( ) const
{
  return elementAt( findMax( root ) );
}

/**
 * @brief Procura um elemento na BST. Se chegar à raíz da árvore (NULL) sem o ter encontrado, retorna ITEM_NOT_FOUND
 *
 * @return O próprio elemento, se existir, ou o elemento definido como ITEM_NOT_FOUND, se não existir
 */
template <class Comparable>
const Comparable & BST<Comparable>::
find( const Comparable & x ) const
{
  return elementAt( find( x, root ) );
}

/**
 * @brief Apaga todos os elementos da árvore
 */
template <class Comparable>
void BST<Comparable>::makeEmpty( )
{
  makeEmpty( root );
}

/**
 * @brief Permite saber se uma árvore tem elementos ou não, verificando se a raíz é um elemento ou se é NULL
 *
 * @return True se a árvore estiver vazia. False caso contrário.
 */
template <class Comparable>
bool BST<Comparable>::isEmpty( ) const
{
  return root == NULL;
}

/**
 * @brief Imprime a BST da esquerda para a direita (do menor para o maior). Cada elemento é representado numa linha.
 */
template <class Comparable>
void BST<Comparable>::printTree( ) const
{
  if( isEmpty( ) )
    cout << "Empty tree" << endl;
  else
    printTree( root );
}

/**
 * @brief Verifica se uma BST é igual a outra BST do mesmo tipo.
 *
 * @param rhs BST a comparar.
 *
 * @return A própria BST, se for igual a rhs, ou uma BST vazia, se forem diferentes.
 */
template <class Comparable>
const BST<Comparable> &
BST<Comparable>::
operator=( const BST<Comparable> & rhs )
{
  if( this != &rhs )
    {
      makeEmpty( );
      root = clone( rhs.root );
    }
  return *this;
}

/**
 * @brief Permite obter o elemento de um determinado nó da árvore
 *
 * @param *t Nó do qual se pretende saber o elemento
 *
 * @return Elemento do nó
 */
template <class Comparable>
const Comparable & BST<Comparable>::
elementAt( BinaryNode<Comparable> *t ) const
{
  if( t == NULL )
    return ITEM_NOT_FOUND;
  else
    return t->element;
}


template <class Comparable>
void BST<Comparable>::
insert( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
  if( t == NULL )
    t = new BinaryNode<Comparable>( x, NULL, NULL );
  else if( x < t->element )
    insert( x, t->left );
  else if( t->element < x )
    insert( x, t->right );
  else
    ;  // Duplicate; do nothing
}

template <class Comparable>
void BST<Comparable>::
remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
  if( t == NULL )
    return;   // Item not found; do nothing
  if( x < t->element )
    remove( x, t->left );
  else if( t->element < x )
    remove( x, t->right );
  else if( t->left != NULL && t->right != NULL ) // Two children
    {
      t->element = findMin( t->right )->element;
      remove( t->element, t->right );
    }
  else
    {
      BinaryNode<Comparable> *oldNode = t;
      t = ( t->left != NULL ) ? t->left : t->right;
      delete oldNode;
    }
}

template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::findMin( BinaryNode<Comparable> *t ) const
{
  if( t == NULL )
    return NULL;
  if( t->left == NULL )
    return t;
  return findMin( t->left );
}


template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::findMax( BinaryNode<Comparable> *t ) const
{
  if( t != NULL )
    while( t->right != NULL )
      t = t->right;
  return t;
}

template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::
find( const Comparable & x, BinaryNode<Comparable> *t ) const
{
  if( t == NULL )
    return NULL;
  else if( x < t->element )
    return find( x, t->left );
  else if( t->element < x )
    return find( x, t->right );
  else
    return t;    // Match
}
/****** NONRECURSIVE VERSION*************************
        template <class Comparable>
        BinaryNode<Comparable> *
        BST<Comparable>::
        find( const Comparable & x, BinaryNode<Comparable> *t ) const
        {
            while( t != NULL )
                if( x < t->element )
                    t = t->left;
                else if( t->element < x )
                    t = t->right;
                else
                    return t;    // Match

            return NULL;   // No match
        }
*****************************************************/

/**
 * MÉTODOS QUE PERMITEM ALTERAR SUB-ÁRVORES
 */

/**
 * @brief Torna uma sub-árvore que tenha o nó "t" por raíz vazia
 *
 * @param t Nó que é a raíz da sub-árvore a eliminar
 */
template <class Comparable>
void BST<Comparable>::
makeEmpty( BinaryNode<Comparable> * & t ) const
{
  if( t != NULL )
    {
      makeEmpty( t->left );
      makeEmpty( t->right );
      delete t;
    }
  t = NULL;
}

/**
 * @brief Imprime uma sub-árvore que tenha o nó t por raíz
 *
 * @param t Nó que é a raíz da sub-árvore a eliminar
 */
template <class Comparable>
void BST<Comparable>::printTree( BinaryNode<Comparable> *t ) const
{
  if( t != NULL )
    {
      printTree( t->left );
      cout << t->element << endl;
      printTree( t->right );
    }
}

/**
 * @brief Clona uma sub-árvore
 *
 * @param t Nó que é a raíz da sub-árvore a clonar
 *
 * @return Sub-árvore clonada
 */
template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::clone( BinaryNode<Comparable> * t ) const
{
  if( t == NULL )
    return NULL;
  else
    return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}


/**************
// Iteradores
**************/


template <class Comparable>
class BSTItrPost {
public:
  BSTItrPost(const BST<Comparable> &bt);

  void advance();
  Comparable &retrieve() { return itrStack.top()->element; }
  bool isAtEnd() {return itrStack.empty(); }

private:
  stack<BinaryNode<Comparable> *> itrStack;
  stack<bool> visitStack;
  void slideDown(BinaryNode<Comparable> *n);
};


template <class Comparable>
BSTItrPost<Comparable>::BSTItrPost (const BST<Comparable> &bt)
{
  if (!bt.isEmpty())
    slideDown(bt.root);
}

template <class Comparable>
void BSTItrPost<Comparable>::advance ()
{
  itrStack.pop();
  visitStack.pop();
  if ((!itrStack.empty()) && (visitStack.top() == false)) {
    visitStack.pop();
    visitStack.push(true);
    slideDown(itrStack.top()->right);
  }
}

template <class Comparable>
void BSTItrPost<Comparable>::slideDown(BinaryNode<Comparable> *n)
{
  while (n) {
    itrStack.push(n);
    if (n->left) {
      visitStack.push(false);
      n = n->left;
    } else if (n->right) {
      visitStack.push(true);
      n = n->right;
    } else {
      visitStack.push(true);
      break;
    }
  }
}


/////////////////////

template <class Comparable>
class BSTItrPre {
public:
  BSTItrPre(const BST<Comparable> &bt);

  void advance();
  Comparable &retrieve() { return itrStack.top()->element; }
  bool isAtEnd() {return itrStack.empty(); }

private:
  stack<BinaryNode<Comparable> *> itrStack;

};

template <class Comparable>
BSTItrPre<Comparable>::BSTItrPre (const BST<Comparable> &bt)
{
  if (!bt.isEmpty())
    itrStack.push(bt.root);
}

template <class Comparable>
void BSTItrPre<Comparable>::advance()
{
  BinaryNode<Comparable> * actual = itrStack.top();
  BinaryNode<Comparable> * seguinte = actual->left;
  if (seguinte)
    itrStack.push(seguinte);
  else {
    while (!itrStack.empty()) {
      actual = itrStack.top();
      itrStack.pop();
      seguinte = actual -> right;
      if (seguinte) {
	itrStack.push(seguinte);
	break;
      }
    }
  }
}


template <class Comparable>
class BSTItrIn {
public:
  BSTItrIn(const BST<Comparable> &bt);

  void advance();
  Comparable &retrieve() { return itrStack.top()->element; }
  bool isAtEnd() {return itrStack.empty(); }

private:
  stack<BinaryNode<Comparable> *> itrStack;

  void slideLeft(BinaryNode<Comparable> *n);
};

template <class Comparable>
BSTItrIn<Comparable>::BSTItrIn (const BST<Comparable> &bt)
{
  if (!bt.isEmpty())
    slideLeft(bt.root);
}

template <class Comparable>
void BSTItrIn<Comparable>::slideLeft(BinaryNode<Comparable> *n)
{
  while (n) {
    itrStack.push(n);
    n = n->left;
  }
}

template <class Comparable>
void BSTItrIn<Comparable>::advance()
{
  BinaryNode<Comparable> * actual = itrStack.top();
  itrStack.pop();
  BinaryNode<Comparable> * seguinte = actual->right;
  if (seguinte)
    slideLeft(seguinte);
}


template <class Comparable>
class BSTItrLevel {
public:
  BSTItrLevel(const BST<Comparable> &bt);

  void advance();
  Comparable &retrieve() { return itrQueue.front()->element; }
  bool isAtEnd() {return itrQueue.empty(); }

private:
  queue<BinaryNode<Comparable> *> itrQueue;

};

template <class Comparable>
BSTItrLevel<Comparable>::BSTItrLevel (const BST<Comparable> &bt)
{
  if (!bt.isEmpty())
    itrQueue.push(bt.root);
}

template <class Comparable>
void BSTItrLevel<Comparable>::advance()
{
  BinaryNode<Comparable> * actual = itrQueue.front();
  itrQueue.pop();
  BinaryNode<Comparable> * seguinte = actual->left;
  if (seguinte)
    itrQueue.push(seguinte);
  seguinte = actual->right;
  if (seguinte)
    itrQueue.push(seguinte);
}


#endif
