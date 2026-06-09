#ifndef TRIE_HPP
#define TRIE_HPP

#include "Game.hpp"
#include <vector>

const int ALPHABET_SIZE = 36;

class TrieNode {

public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    /**
     * @brief Inicializa um nó da Trie com filhos nulos e sem jogo associado.
     */
    TrieNode();
    /**
     * @brief Destrói o nó.
     */
    ~TrieNode();
};

class Trie {

private:

    TrieNode* root;
    /**
     * @brief Percorre a subárvore a partir de um nó e coleta todos os jogos encontrados.
     * 
     * @param node Nó raiz da subárvore a ser percorrida.
     * @return Vetor com ponteiros para todos os jogos encontrados na subárvore.
     */
    std::vector<Game*> depthSearchGames(TrieNode* node);
    /**
     * @brief Percorre a subárvore a partir de um nó e libera todos os nós recursivamente.
     * 
     * @param node Nó raiz da subárvore a ser deletada.
     */
    void depthDeleteNodes(TrieNode* node);

public:

    /**
     * @brief Inicializa a Trie com um nó raiz vazio.
     */
    Trie();
    /**
     * @brief Destrói a Trie e libera todos os nós alocados.
     */
    ~Trie();

    /**
     * @brief Insere um jogo na Trie usando seu título como chave.
     * 
     * @param game Ponteiro para o jogo a ser inserido.
     * @return true se a inserção foi bem-sucedida.
     */
    bool insert(Game* game);
    /**
     * @brief Verifica se um jogo com o título fornecido está presente na Trie.
     * 
     * @param title Título a ser buscado.
     * @return true se o título existe na Trie; false caso contrário.
     */
    bool contains(std::string title);

    /**
     * @brief Retorna até k jogos cujos títulos começam com o prefixo fornecido.
     *        Os resultados são ordenados por popularidade decrescente.
     * 
     * @param prefix Prefixo a ser buscado.
     * @param k      Número máximo de resultados a retornar.
     * @return Vetor com ponteiros para os jogos encontrados.
     */
    std::vector<Game*> autocomplete(std::string prefix, int k);

    /**
     * @brief Converte uma string para o formato de chave de busca da Trie,
     *        normalizando para minúsculas e substituindo caracteres não alfanuméricos.
     * 
     * @param text Texto a ser convertido.
     * @return String normalizada para uso como chave na Trie.
     */
    std::string toSearchKey(std::string text);
    
    /**
     * @brief Ordena um vetor de jogos por popularidade decrescente.
     * 
     * @param games Referência ao vetor de ponteiros de jogos a ser ordenado.
     */
    void sortResults(std::vector<Game*>& games);
    // Outros métodos auxiliares, se necessário
};

#endif