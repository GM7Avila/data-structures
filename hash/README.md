# HASH!
- Foco em grande quantidade de **busca** em um mesmo conjunto de dados com *resposta eficiente*;
- Muitas remoções e adições se torna ineficiente;
- Ideal sempre sobrar espaço;
- Boa função de espalhamento e tratamento de colisões;
- Analise de fator de carga da tabela hash;

## Tabela Hash Eficiente

- **Tamanho da tabela (M)**
    - Número primo;
    - Analisar o conjunto de dados:
    - Primo mais próximo do valor do conjunto de dados * 2
    - Ex.: 6 elementos; Tamanho da tabela: 6 * 2 = 12; primo mais próximo = 11;
    - M = elemento * 2 (resultado --> arrendondar para primo)

- **Fator de carga (fc)**
    - Taxa de população (0~1 - 0~100%);
    - Analiasar otimização de espaço;
    - fc = qtd. elementos / conjunto; 
    - ex.: 6 / 11 = 0.54 (54% da tabela populada);
    - valor ideal: meio termo, aproximadamente 50%

## Função de Espalhamento
- *Hash Function*: chave % M

## Colisões
- **Método 1 (Menos otimizado)**: Em caso de colisão durante a busca, continuamos a posição seguinte em uma busca linear até encontrar o elemento ou um elemento nulo (nesse caso o elemento não está na tabela)

- **Método 2 (Otimizado)**: Utilização de *Listas Encadeadas*; Usamos um vetor de ponteiros para listas encadeadas; Em caso de colisão, busca o próximo elemento da lista encadeada indexada na posição i do vetor de ponteiros para lista encadeada(todo os ponteiros são de next são nulos e ocupam memória);

- Avaliar o consumo de memória (escassez de memória - podemos usar o método 1)