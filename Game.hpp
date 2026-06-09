#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

class Game {

private:
    std::string title;
    std::string shortDescription;
    int popularity;

public:

    /**
     * @brief Inicializa um jogo com valores padrão.
     */
    Game();
    /**
     * @brief Inicializa um jogo com os dados fornecidos.
     * 
     * @param title            Título do jogo.
     * @param shortDescription Breve descrição do jogo.
     * @param popularity       Nível de popularidade do jogo.
     */
    Game(std::string title, std::string shortDescription, int popularity);
    /**
     * @brief Destrói o jogo e libera os recursos associados.
     */
    ~Game();

    /**
     * @brief Retorna o título do jogo.
     * 
     * @return String com o título do jogo.
     */
    std::string getTitle();
    /**
     * @brief Retorna a descrição curta do jogo.
     * 
     * @return String com a descrição curta do jogo.
     */
    std::string getShortDescription();
    /**
     * @brief Retorna a popularidade do jogo.
     * 
     * @return Inteiro representando o nível de popularidade do jogo.
     */
    int getPopularity();
};

#endif