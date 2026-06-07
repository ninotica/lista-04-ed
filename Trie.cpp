#include "Trie.hpp"
#include <cctype>

TrieNode::TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
    isEndOfTitle = false;
    game = nullptr;
}
TrieNode::~TrieNode() {
    
}

std::vector<Game*> Trie::depthSearchGames(TrieNode* node){
    if (node == nullptr){
        return {};
    }
    std::vector<Game*> resultado = {};
    if (node->isEndOfTitle){
        resultado.push_back(node->game);
    }
    for (int i=0; i<ALPHABET_SIZE; i++){
        std::vector<Game*> child = depthSearchGames(node->children[i]);
        resultado.insert(resultado.end(), child.begin(), child.end());
    }
    return resultado;    
}

void Trie::depthDeleteNodes(TrieNode* node){
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i<ALPHABET_SIZE; i++) {
        depthDeleteNodes(node->children[i]);
    }
    delete node;
    return;
}

Trie::Trie() {
    root = new TrieNode();
}
Trie::~Trie() {
    depthDeleteNodes(root);
}

bool Trie::insert(Game* game) {
    std::string key = toSearchKey(game->getTitle());
    TrieNode* parent = root;
    for (char c : key){
        int idx = (int)c;
        if (parent->children[idx] == nullptr){
            parent->children[idx] = new TrieNode();
        }
        parent = parent->children[idx];
    }
    parent->isEndOfTitle = true;
    parent->game = game;
    return true;
}

bool Trie::contains(std::string title) {
    std::string key = toSearchKey(title);
    TrieNode* node = root;

    for (char c : key) {
        int idx = (int)c;
        
        if (node->children[idx] == nullptr) {
            return false;
        }
        
        node = node->children[idx];
    }

    return node->isEndOfTitle;
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){
    std::string key = toSearchKey(prefix);
    TrieNode* start = root;
    for (char c : key) {
        int idx = (int)c;
        if (start->children[idx] == nullptr) {
            return {};
        }
        start = start->children[idx];
    }
    std::vector<Game*> games = depthSearchGames(start);
    sortResults(games);
    return games;   
}

std::string Trie::toSearchKey(std::string text) {
    // Aqui, implementamos uma função que nos devolve uma string 
    // ilegível de caracteres (potencialmente não printáveis) 
    // cujos códigos ASCII vão de 0 a 35. Assim, fica fácil 
    // convertê-los de volta para int e usá-los como índices em outras funções!
    std::string resultado = "";
    for(char c : text){
        int idx = -1;
        if (c >= '0' && c <= '9') idx = c - '0';
        if (c >= 'a' && c <= 'z') idx = 10 + c - 'a';
        if (c >= 'A' && c <= 'Z') idx = 10 + c - 'A';
        if (idx != -1){
            resultado += (char)idx;
        }
    }
    return resultado;
}
void Trie::sortResults(std::vector<Game*> &games) {
    int min_index;
    Game* temp;
    
    for (int i =0; i < games.size(); i++){
        min_index = i;
        for (int j=i + 1; j< games.size(); j++){
            if (games[j]->getPopularity()>games[min_index]->getPopularity()){
                min_index = j;
            } else if (games[j]->getPopularity()==games[min_index]->getPopularity() && toSearchKey(games[j]->getTitle()) < toSearchKey(games[min_index]->getTitle())) {
                min_index = j;
            }
        }
        if (min_index != i){
            temp = games[i];
            games[i] = games[min_index];
            games[min_index] = temp;
        }
    }
}
