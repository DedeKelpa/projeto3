# 🎵 Jogo da Memória Musical com Arduino

## 🧠 Descrição do Projeto

Este projeto é um **jogo da memória musical** feito com Arduino.  
O objetivo do jogador é **ouvir uma sequência de notas musicais** e **reproduzi-la corretamente** usando **quatro botões** físicos.  
Um **display LCD 16x2** serve como interface visual, enquanto um **buzzer** reproduz as notas das músicas.

🎶 Estão disponíveis **4 músicas** no jogo:
- Mario
- Estrelinha (Twinkle Twinkle)
- Sonic
- Tetris

Cada música possui **3 níveis de dificuldade** com sequências cada vez maiores.

---

## 🔧 Componentes Utilizados

- Arduino Uno  
- Display LCD 16x2  
- Buzzer  
- 4 Botões  
- 2 LEDs (Verde e Vermelho)  
- Resistores de Pull-down  
- 2 Protoboards  
- Jumpers  

---

## ⚙️ Mapeamento de Pinos

| Componente     | Pino Arduino |
|----------------|--------------|
| LCD RS         | 12           |
| LCD E          | 11           |
| LCD D4         | 7            |
| LCD D5         | 6            |
| LCD D6         | 5            |
| LCD D7         | 4            |
| Buzzer         | 8            |
| Botão 1        | 2            |
| Botão 2        | 3            |
| Botão 3        | 9            |
| Botão 4        | 10           |
| LED Verde      | 0            |
| LED Vermelho   | 1            |

---

## 🎮 Como Jogar

1. Uma **mensagem de boas-vindas** é exibida no LCD, seguida pela **lista de músicas**.  
2. Use os botões para navegar:  
   - **Botão 1**: Avança para o próximo item  
   - **Botão 2**: Seleciona a música  
3. Após a seleção, **uma sequência de notas é tocada** automaticamente.  
4. O jogador deve **reproduzir a sequência corretamente** pressionando os botões na ordem.  
5. Regras:
   - Acertou a sequência → Avança para o próximo nível  
   - Errou a sequência → Perde 1 vida (são 3 vidas no total)  
   - Ao perder todas as vidas → Volta para o **nível 1** da música atual  

---

## 🧹 Funções do Código

### 🔊 `void tocar(int frequency, int duration)`
- Toca um som no buzzer com a frequência e duração passadas.
- Se `frequency == 0`, o buzzer permanece mudo e apenas espera (`delay`).

---

### ⚒️ `void setup()`
- Inicializa os pinos dos botões e LEDs.
- Configura o display LCD.
- Exibe a mensagem inicial.
- Toca uma melodia de introdução.
- Chama o menu de seleção.

---

### 🔁 `void loop()`
- Controla o **menu principal** baseado em **estados (de 1 a 5)**:
  - **Estados 1 a 4**: Seleciona uma das 4 músicas.
  - **Estado 5**: Volta ao início do menu.

---

## 🎼 Funções das Músicas

> Todas seguem o mesmo padrão de funcionamento, exceto a música do Tetris que inclui controle adicional de duração das notas.

### 🎵 `void mario()`
- Usa 4 notas (1 para cada botão).
- **Níveis**: 3, 5 e 7 notas.
- Em caso de erro: perde 1 vida e reinicia no nível 1.

---

### ⭐ `void estrelinha()`
- Usa 4 notas.
- **Níveis**: 5, 7 e 10 notas.
- Mesmo comportamento do `mario()`.

---

### 🔀 `void sonic()`
- Usa 4 notas.
- **Níveis**: 4, 8 e 16 notas.
- Ideal para testar reflexos rápidos!

---

### 🔷 `void tetris()`
- Usa 4 notas.
- **Níveis**: 6, 12 e 18 notas.
- **Diferencial**: possui um array adicional que define a **duração de cada nota**, o que deixa a melodia mais realista.

---

## 📌 Observações Técnicas

- Todas as funções de música usam:
  - `notas[]` → Notas associadas aos botões.
  - `botoes[]` → Pinos dos botões.
  - `sequenciaCorreta[]` → Sequência da música.
  - `sequenciaUsuario[]` → Entrada do jogador.
- Funções com laços `for` e `while` controlam a execução do jogo:
  - Tocar sequência
  - Capturar entradas do jogador
  - Validar respostas

---

## 🖼️ Extras

- 📸 **Fotos do Projeto**: *(inserir aqui quando disponíveis)*
- 🎥 **Vídeo de Funcionamento**: *(inserir link para o vídeo se disponível)*




































Projeto 3 
David Gabriel de Souza Batista RA:22.123.056-8


O projeto consiste em 13 funções e 1 função auxiliar 

1 - Cadastrar Tarefas: Função que pede para o usuário cadastrar a tarefa, pedindo categoria, prioridade, estado e descrição.
2 - Listar Tarefas: Função que mostra ao usuario todas as tarefas cadastradas.
3 - Deletar Tarefas: Função que deleta a tarefa a partir de seu indice.
4 - Salvar Tarefas: Função que salva as tarefas em um arquivo.txt.
5 - Alterar Tarefas: Altera a tarefa a partir do seu indice, alterando apenas o que o usuario desejar.
6 - Filtrar Prioridade: Filtra as tarefas baseada na prioridade pedida pelo usuário.
7 - Filtrar Estado: Filtra as tarefas baseadas no estado digitado pelo usuário.
8 - Filtrar Categoria crescente: Filtra as tarefas baseada na categoria digitada pelo usuário, porém em ordem crescente baseada em sua prioridade.
9 - Filtrar Prioridade e categoria: Filtra as tarefas baseada na categoria e prioridade digitada pelo usuário.
10 - Arquivo Prioridade: Cria um arquivo com as tarefas baseada na prioridade pedida pelo usuário.
11 - Arquivo Categoria crescente: Cria um arquivo com as tarefas baseada na categoria digitada pelo usuário, porém em ordem crescente baseada em sua prioridade.
12 - Arquivo Prioridade e Categoria: Filtra as tarefas baseada na categoria e prioridade digitada pelo usuário.
13 - Sair: Dá break no código.
14 - Carregar Tarefas: Carrega as tarefas que estão no arquivo.txt para o código

a Função auxiliar é compararPorPrioridade, que compara as prioridades e as deixa em ordem crescente.
