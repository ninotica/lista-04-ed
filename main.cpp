#include "Trie.hpp"
#include "Game.hpp"
#include "GamesDatabase.hpp"


int main(int argc, char* argv[]){
    if(argc != 3){
        std::cout << "Usage: ./app k prefix" << std::endl;
    }
    int k = (int)argv[1] - '0';
    std::string prefix = (std::string)argv[2];

    Trie trie = Trie();
    for(int i = 0; i<numberOfGames; i++){
        trie.insert(&games[i]);
    }
    
    std::vector<Game*> result = trie.autocomplete(prefix, k);
    for (Game* game: result) {
        std::cout << game->getTitle() << " | " << game->getShortDescription() << " | " << game->getPopularity() << std::endl;
    }
}