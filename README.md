# Árvore Quad-tree

## Introdução:

Membros do grupo

- Felipe Patitucci
$\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:$
DRE: 120022269  
- Igor Torres
$\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:$
DRE: 119034669  
- Matheus Moreira do Nascimento 
$\:\:\:$
DRE: 119042060
- Pedro Wong
$\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:$
DRE: 120076810  
- Ruan Felipe da Silva e Sousa $\:\:\:\:\:\:\:\:\:\:\:$
DRE: 119041454  


O programa implementa visualmente uma Quad-Tree em C++ utilizando programação orientada a objeto.  
 Ela é populada a partir dos pontos existentes no arquivo passado como parametro ao programa.
<p align="center">
  <img src="https://user-images.githubusercontent.com/48777468/211158857-58521313-d38e-4926-b021-3eb24df6089a.gif" alt="quad-tree-gif" />
</p>

## Objetos e seus métodos:

Point: Esse é o objeto que descreve uma coordenada x,y
- Metodos
  - getX: Retorna o valor da coordenada x do ponto
  - getY: Retorna o valor da coordenada y do ponto
  - relativePosition: Retorna a direção cardinal do ponto em relação a outro ponto dado

Node: Esse é o objeto que serve de nó para a árvore. Não há diferenciação de
nó galho para nó folha no nosso programa
- Metodos
  - relativeDirection: Retorna a direção cardinal de um ponto dado em relação ao centro do nó

Tree: Esse é o objeto que descreve a Point Quad-Tree
- Metodos
  - size: Rretorna quantos pontos a árvore possui.
  - has : Retorna se o ponto dado está ou não na árvore.
  - Insert: Insere o ponto dado na árvore.
  - clear : Remove todos os pontos da árvore.
  - searchWindow: Retorna todos os pontos dentro da janela formada pelos pontos (ponto superior esquerdo, ponto inferior direito) dados.
  - searchDirection: Retorna todos os pontos da árvore na direção cardinal dada relativa ao ponto dado.

Window: Esse objeto descreve a janela visual que mostra a árvore
- Metodos
  - isClosed: Retorna um booleano indicando se a janela está fechada ou não.
  - pollEvents: Método utilizado pelo fluxo padrão do programa para receber e processar os comandos do teclado e mouse.

## Projeto Funcional:
Ao iniciar, o programa abre uma tela com as dimensões $800\times450$. Ela representa
os pontos da arvore pela cor vermelha, também são feitos alguns traçados pretos
para identificar a região a qual o ponto pertence. Com toda a representação finalizada
é possivel interagir com a visualização dos pontos utilizando o teclado e o mouse.

**Comandos:**
- Click do mouse:
  - cria um novo ponto e insere na arvore.
- Scroll do mouse:
  - aumenta e diminui o zoom na tela de visão.
- Setas:
  - movem a tela de visão nas direções correspondentes.
- Tecla p:
  - printa no terminal todos os pontos existentes na arvore.
- Tecla v:
  - printa no terminal todos os pontos exitentes na tela de visão.
- Tecla r:
  - restaura a tela de visão para a posição inicial.
- Tecla c:
  - deleta todos os pontos existentes na arvore.

## Requisitos Para Compilação

Necessario compilador gcc, ferramenta make e lib SDL.

**Comando para atualizar lista de pacotes:**
```sh
sudo apt-get update
```
**Comando para instalar gcc, g++ e make:**
```sh
sudo apt-get -y install build-essential
```
**Comando para instalar SDL:**
```sh
sudo apt-get -y install libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2*dev
```

## Como Utilizar:

**Comando para compilação:**
```sh
make
```

**Comando para execução:**
```sh
./quad-tree [arquivo]
```

O arquivo utilizado deve possuir uma formatação especifica:
- deve conter apenas pares ordenados separados por virgula.
- as cordenadas devem ser pontos flutuantes dentro do intervalo $[0, 800] \times [0, 450]$.
- os pares ordenados devem ser separados por espaço, tabs ou quebra de linha.

**Exemplo:**
```sh
350.3432,340.4334        0,0.23    43,58

433.5000,356
23,350.22   234,254  433,23
```
