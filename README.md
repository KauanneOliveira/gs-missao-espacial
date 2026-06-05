# GS2026.1 — Sistema de Monitoramento de Missão Espacial

## Identificação Acadêmica
**Disciplina**: Data Structures and Algorithms <br>
**Curso**: Ciências da Computação - 1º Ano <br>
**Turma**: 1CCPI <br>
**Integrantes**:

| Nome | RM |
|------|----|
| Kauanne Paula de Oliveira | 574191 |
| Nayhely Estela Calle Castillo | 571416 |

## Sobre o projeto

Este projeto foi desenvolvido para a disciplina de Data Structures and Algorithms e tem como objetivo simular um sistema de monitoramento de uma missão espacial experimental. O programa recebe dados operacionais simulados, analisa as condições da missão e emite alertas quando necessário.

## Estrutura do repositório

```
/
├── demonstracao-pratica/
│   └── Fotos do terminal com exemplos reais de execução do programa,
│       mostrando o menu, inserção de dados, análise e estatísticas.
│
├── fluxograma/
│   └── Imagem do fluxograma do sistema e um arquivo .txt
│       com o link para acesso online da imagem.
│
└── gs-dsa-missao-espacial/
    └── Código-fonte em C do sistema de monitoramento (missao-espacial.c).
```

## Explicação da lógica

### Variáveis globais

O programa utiliza variáveis globais para armazenar os dados da missão: `temperatura`, `energia` e `comunicacao`. Também utiliza dois vetores — `histTemperatura` e `histEnergia` — com capacidade para 5 posições cada, responsáveis por guardar o histórico das últimas leituras registradas. A variável `dadosInseridos` controla se o usuário já inseriu algum dado antes de tentar visualizar ou analisar.

### Menu interativo

O menu fica rodando num loop `do-while` até o usuário decidir sair. Cada opção é tratada por um `switch`, que manda o programa pra função certa dependendo do que foi digitado.

### Cadastro de dados (opção 1)

O usuário digita a temperatura, o nível de energia e o status da comunicação via `scanf`. Depois disso, os valores são salvos nos vetores de histórico. Quando o vetor já tem 5 leituras e chega uma nova, um `for` empurra tudo uma posição pra esquerda, joga fora a leitura mais antiga e coloca a nova no final.

### Visualização do status (opção 2)

Mostra os valores atuais de temperatura, energia e comunicação. Antes de exibir qualquer coisa, o programa checa se `dadosInseridos` é igual a 1 — se não for, aparece uma mensagem pedindo pra inserir os dados primeiro.

### Análise do sistema (opção 3)

Verifica três condições com `if`:
- Temperatura acima de 80°C → alerta de superaquecimento
- Energia abaixo de 20% → alerta de economia de energia
- Comunicação igual a 0 → alerta de falha de comunicação

Cada alerta encontrado soma 1 num contador. O status geral da missão sai com base nisso: zero alertas é `NORMAL`, um é `ATENCAO`, dois ou mais é `CRITICA`.

### Estatísticas e picos (opção 4)

Percorre os vetores de histórico com um `for`, acumulando a soma dos valores e identificando o maior valor registrado (pico) de temperatura e energia. No final do loop, divide a soma pelo número de leituras pra tirar a média e mostra tudo na tela.

### Encerramento (opção 5)

Quando o usuário escolhe essa opção, o `do-while` encerra direto e o programa finaliza.

## Como compilar e executar

No terminal do programa, rode os seguintes comandos:

```
gcc missao_espacial.c -o missao
./missao
```
