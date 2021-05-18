#ifndef ABP
#define ABP

#include <iostream>
using namespace std;

/**
 * author: Eduardo Rodrigues
 * 
 * brief: Arvore Abp auto Avl,
 *  o balanceamento é executado na inserção.
 * 
 * version: 1.0
 * date: 2021-05-17
 */
class Abp
{
private:
    /**
     * @brief Classe de nó
     * 
     */
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;
        int bal_factor;
    };

    Node *root;

    /**
    * @brief Função recursiva para apagar os nós alocados
    * 
    * @param node 
    */
    void free_(Node *node);

    /**
    * @brief Executa um balanceamento na região de um nó selecionado
    * 
    * @return Node* 
    */
    Node *balance(Node *);

    /**
     * @brief vê a altura da esquerda e direita e retorna a maior
     * 
     * @return int 
     */
    int height(Node *);

    /**
     * @brief Retorna a diferença das alturas (fator de balanceamento)
     * 
     * @return int 
     */
    int diff(Node *);

    /**
     * @brief Rotações
     * 
     * @return Node* 
     */
    //
    Node *rotateRR(Node *);
    Node *rotateRL(Node *);
    Node *rotateLR(Node *);
    Node *rotateLL(Node *);
    //

    /**
     * @brief Função recursiva para inserir na árvore
     * 
     * @return Node* 
     */
    Node *insert_(int, Node *);

    /**
     * @brief Função recursiva para imprimir a arvore na tela
     * 
     */
    void displayTree_(Node *, int = 1);

    /**
     * @brief Função recursiva para mostrar as chaves em ordem crescente
     * e seus respectivos fatores de balanceamento
     * 
     */
    void updateBalFactor_(Node *);

public:
    /**
    * @brief Construct a new Abp:: Abp object
    * 
    */
    Abp();

    /**
    * @brief Destroy the Abp:: Abp object
    * 
    */
    ~Abp();

    /**
     * @brief Método para inserir na árvore
     * 
     * @param value 
     */
    void insert(int value);

    /**
     * @brief Método que imprime a árvore na tela
     * 
     */
    void displayTree();

    /**
     * @brief Método que mostra as chaves em ordem crescente
     * e seus respectivos fatores de balanceamento
     * 
     */
    void updateBalFactor();

    /**
    * @brief Vê se a árvore está vazia
    * 
    * @return true 
    * @return false 
    */
    bool isEmpty();

    /**
     * @brief Apaga todos os nós da árvore
     * 
     */
    void reset();
};

#endif