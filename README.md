# Sistema de Autocomplete de Jogos com Trie

Sistema de autocomplete implementado em C++ que armazena um catálogo de jogos em uma Trie e retorna sugestões a partir de um prefixo, ordenadas por popularidade.

---

## Descrição do projeto

A Trie armazena os títulos dos jogos caractere a caractere, permitindo buscas eficientes por prefixo. Dado um prefixo e um número `k`, o sistema retorna até `k` jogos cujo título começa com aquele prefixo, ordenados por popularidade decrescente. Em caso de empate, o desempate é feito pela ordem alfabética da chave de busca do título.

A busca é **case-insensitive** e **ignora espaços**, ou seja, `"Half Life"`, `"halflife"` e `"HALF L"` são tratados como o mesmo prefixo.

Cada jogo possui:

- **title**: título do jogo;
- **shortDescription**: breve descrição;
- **popularity**: nível de popularidade (inteiro).

---

## Organização dos arquivos

```
autocomplete/
├── main.cpp             # Ponto de entrada; lê argumentos, insere jogos na Trie e exibe resultados
├── Game.hpp             # Declaração da classe Game
├── Game.cpp             # Implementação da classe Game
├── Trie.hpp             # Declaração das classes TrieNode e Trie
├── Trie.cpp             # Implementação das classes TrieNode e Trie
├── GamesDatabase.hpp    # Declaração do array de jogos e da variável numberOfGames
├── GamesDatabase.cpp    # Definição da base de jogos
└── README.md            # Este arquivo
```

- **`Game.hpp` / `Game.cpp`**: define a estrutura de um jogo e seus getters (`getTitle`, `getShortDescription`, `getPopularity`).
- **`Trie.hpp` / `Trie.cpp`**: contém a lógica central — inserção, busca por título exato (`contains`), autocomplete por prefixo e ordenação dos resultados. O alfabeto interno tem 36 caracteres (dígitos 0–9 e letras a–z), mapeados por `toSearchKey`.
- **`GamesDatabase.hpp` / `GamesDatabase.cpp`**: declara e define o array estático de jogos carregado no início do programa.
- **`main.cpp`**: lê `k` e o prefixo da linha de comando, insere todos os jogos da base na Trie e imprime os resultados.

---

## Compilação

Todos os arquivos devem estar no mesmo diretório. Para compilar, execute:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

Não são necessárias flags adicionais.

---

## Execução

```bash
./app k prefixo
```

Onde `k` é o número máximo de sugestões e `prefixo` é o texto a buscar.

No Windows:

```bash
app.exe k prefixo
```

Se o prefixo contiver espaços, passe-o entre aspas:

```bash
./app 3 "half l"
```

---

## Exemplos de uso

**Busca por prefixo `ha`, retornando até 3 resultados:**

```bash
./app 3 ha
```

```
Hades | Roguelike de acao baseado na mitologia grega | 95
Half Life | FPS classico de ficcao cientifica | 92
Halo | FPS futurista com campanha e multiplayer | 85
```

**Busca com espaço no prefixo (equivalente à busca sem espaço):**

```bash
./app 5 "half l"
```

```
Half Life | FPS classico de ficcao cientifica | 92
```

**Busca sem resultados:**

```bash
./app 3 zelda
```

```
No results found
```

**Argumentos incorretos:**

```bash
./app
```

```
Usage: ./app k prefix
```