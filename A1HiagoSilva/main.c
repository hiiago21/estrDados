/*

#################
#################
##### N1-A1 #####
#################
#################

- Atividade individual.
- Os exercicicos a seguir devem ser observados, completados, implementados, apresentados, executados, explicados.
- A tela deve ser gravada com o audio da explicacao.
- Utilize programas sem tarjas e propagandas, existem diversos softwares gratuitos para isso, como por exemplo o OBS Studio, quicktime, etc.
- O video deve ser de no maximo 20 minutos para os 2 exercicios.
- O video deve ser colocado o youtube, seu link testado e enviado no exercicio.
- Nao Ã© permitido acelerar a gravacao, logo deve ser em tempo normal.
- A decisao de como e quais informacoes devem ser apresentadas sera do aluno, isso parte da avaliacao
*/

// ################
// # EXERCICIO 01 #
// ################

#include <stdlib.h>
#include <stdio.h>

// Estrutura criada da matriz em struct para manipulacao utilizando TAD
struct matriz{

  int linha;
  int coluna;
  float* valor;

};

// O que faz e para utilizar nesse contexto?
typedef struct matriz Matriz;

// Funcao de criacao de uma Matriz utilizando TAD.
// Observe a funcao e explique o funcionamento da criacao da matriz utilizando TAD?
Matriz* cria(int m, int n){

    // cria dinamicamente o tamanho da matriz se for nulo o valor de mat é pq não tem memória suficiente par isto
  Matriz* mat = (Matriz*)malloc(sizeof(Matriz));

  if (mat == NULL){
    printf("Memoria insuficiente!\n");
    exit(1);
  }

  mat->linha = m;
  mat->coluna = n;
  // seta o tamanho total da matriz com a linhas e colunos contabilizando um valor flot em cada posição
  mat->valor = (float*)malloc(m*n*sizeof(float));
  //[-,-,-,-,-]


  return mat;

}

// Observe a funcao e explique o funcionamento?
void libera(Matriz* mat){

    //necessário liberar primeiro o valor pois ele é um endereço de memória
    free(mat->valor);
    free(mat);

}

// Observe a funcao e explique o funcionamento?
float acessa(Matriz* mat, int i, int j) {

  int k;

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) {
    printf("Acesso invalido!\n");
    menu(mat);
  }

  k = i * mat->coluna + j;

  return mat->valor[k];

}

// Observe a funcao e explique o funcionamento?
void atribui(Matriz* mat, int linhaRecebida, int colunaRecebida, float valor) {
    // 1, 1, 10
  int k;

  if (linhaRecebida < 0 || linhaRecebida >= mat->linha || colunaRecebida < 0 || colunaRecebida >= mat->coluna) {
    printf("Atribuicao invalida!\n");
    menu(mat);
  }

  k = linhaRecebida * mat->coluna + colunaRecebida;

  /*
      2,2

      linha - 0
      linha - 1

      coluna - 0
      coluna - 1

      1,2
      3,4

      [1,2,3,4]
  */
  mat->valor[k] = valor;
}

// Observe a funcao e explique o funcionamento?
int linhas(Matriz* mat){

  return mat->linha;

}

// Observe a funcao e explique o funcionamento?
int colunas(Matriz* mat){

  return mat->coluna;

}

void imprimeVetor(float *vetorValores, int tamanhoVetor){

    printf("\n[");
    for(int i = 0; i < tamanhoVetor; i++){
        printf("%d", (int)vetorValores[i]);
        if(i < tamanhoVetor-1){
            printf(",");
        }
    }
    printf("]\n\n\n");
}

void mostrarDiagonalSecundaria(Matriz* mat){
    /*
    4 x 4

    ---0,3
    --1,2-
    -2,1--
    3,0---
    */

    int linha = linhas(mat);
    int coluna = colunas(mat);
    float vetorValores[linha];

    for(int i = 0; i < linha; i++){

        vetorValores[i] =  acessa(mat, i, coluna-1);

        coluna--;
    }

    printf("\nOs valores da diagonal sao: ");
    imprimeVetor(vetorValores, linha);
}

void mostrarExtremidades(Matriz* mat){

    int linha = linhas(mat);
    int coluna = colunas(mat);
    float vetorValores[4];

    vetorValores[0] = acessa(mat, 0, 0);
    vetorValores[1] =  acessa(mat, 0, coluna-1);
    vetorValores[2] =  acessa(mat, linha-1, 0);
    vetorValores[3] =  acessa(mat, linha -1, coluna-1);

    printf("\nOs valores das extremidades sao: ");
    imprimeVetor(vetorValores, 4);
}

void limpaTela() {
    system("CLS");
}

Matriz* criarMatriz(int linha, int coluna){

    Matriz* mat = cria(linha, coluna);

    return mat;
}

void populaMatriz(Matriz* mat){
    int qtdLinhas = linhas(mat);
    int qtdColunas = colunas(mat);
    int valorAux = 0;
    for(int i = 0; i < qtdLinhas; i++){
            for(int j = 0; j < qtdColunas; j++){
                atribui(mat, i, j, valorAux);
                valorAux++;
                if(valorAux >99){
                    valorAux = 0;
                }
            }
    }
}


int mostraOpcao(){

    printf("1 - Quantidade de linhas?");
    printf("\n2 - Quantidade de colunas?");
    printf("\n3 - Inserir um valor na matriz?");
    printf("\n4 - Buscar um valor dentro da matriz?");
    printf("\n5 - Recriar a matriz?");
    printf("\n6 - Mostrar os valores da diagonal secundária da matriz?");
    printf("\n7 - Mostrar as extremidades da matriz?");
    printf("\n0 - Sair");
    printf("\nEscolha uma opcao: ");
    int valorEscolhido;
    scanf("%d", &valorEscolhido);

    return valorEscolhido;

}


void menu(Matriz* mat){
        int linhaNovaMatriz;
        int colunaNovaMatriz;
        int opcao = mostraOpcao();

        do {

            switch(opcao){
                case 1:
                    limpaTela();

                    printf("Quantidade de linhas: %d \n\n\n", linhas(mat));

                    menu(mat);
                break;

                case 2:
                    limpaTela();

                    printf("Quantidade de colunas: %d \n\n\n", colunas(mat));

                    menu(mat);
                break;

                case 3:
                    limpaTela();

                    int linhaInserir;
                    int colunaInserir;
                    int linhaMax = linhas(mat);
                    int colunaMax = colunas(mat);
                    int valor;

                    printf("Matriz comeca na linha 0 e termina na linha %d \nColunas comeca na 0 e termina na coluna %d", linhaMax, colunaMax);
                    printf("\nQual linha deseja inserir o valor? ");
                    scanf("%d", &linhaInserir);


                    if(linhaInserir > linhaMax){
                        printf("Valor invalido! Escolha um numero menor que: %d e maior que: 0", linhaMax-1);
                    }


                    printf("\nQual coluna deseja inserir o valor? ");
                    scanf("%d", &colunaInserir);

                    if(colunaInserir > colunaMax){
                        printf("Valor invalido! Escolha um numero menor que: %d e maior que: 0", colunaMax-1);
                    }


                    printf("\nQual valor deseja inserir? ");
                    scanf("%d", &valor);

                    atribui(mat, linhaInserir, colunaInserir, valor);

                    printf("\nValor inserido: %d, na linha %d e coluna %d \n\n\n", valor, linhaInserir, colunaInserir);

                    menu(mat);
                break;

                case 4:

                    limpaTela();

                    int linhaBuscar;
                    int colunaBuscar;
                    int valorBuscado;

                    printf("Qual linha deseja buscar o valor? ");
                    scanf("%d", &linhaBuscar);
                    printf("\nQual coluna deseja buscar o valor? ");
                    scanf("%d", &colunaBuscar);

                    valorBuscado = acessa(mat,linhaBuscar, colunaBuscar);

                    printf("\nValor encontrado foi : %d \n\n\n", valorBuscado);

                    menu(mat);

                break;

                case 5:
                    limpaTela();
                    libera(mat);
                    printf("Qual o tamanho da matriz que voce deseja ?  ");
                    printf("\nLinhas: ");
                    scanf("%d", &linhaNovaMatriz);
                    printf("Coluna: ");
                    scanf("%d", &colunaNovaMatriz);

                    mat = criarMatriz(linhaNovaMatriz, colunaNovaMatriz);
                    populaMatriz(mat);

                    printf("\nMatriz criada tamanho linha: %d coluna %d \n\n\n", linhaNovaMatriz, colunaNovaMatriz);

                    menu(mat);

                break;

                case 6:
                    limpaTela();
                    if(linhas(mat)== colunas(mat)){
                        mostrarDiagonalSecundaria(mat);
                        menu(mat);
                    }else{
                        printf("\nSua matriz nao e quadrada, para isto recrie ela. \n\n\n");
                        menu(mat);
                    }

                break;

                case 7:
                    mostrarExtremidades(mat);
                    menu(mat);

                break;

                case 0:
                    libera(mat);
                    exit(1);
                break;

                default:
                    printf("Valor invalido escolhido, escolha outro");
                    opcao = mostraOpcao();

            }

        }while(opcao != 0);


}


 int main(){

    int escolha;

    printf("Desenha criar uma matriz ? Sim (1) Nao (2): ");
    scanf("%d", &escolha);

    if(escolha == 2){
        exit(1);

    }else{

        int linha;
        int coluna;

        printf("Qual o tamanho da matriz que voce deseja ?  ");
        printf("\nLinhas: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);

        Matriz* mat = criarMatriz(linha, coluna);
        populaMatriz(mat);
        limpaTela();
        menu(mat);

        return 0;
    }
 }

  /*
  Implemente a main de forma que todas as funcoes sejam utilizadas amplamente pelo usuario.
  Dados do tipo float.
  Ao executar o programa deve ser solicitado ao usuario se deseja criar a matriz:
    SIM:
      -Executar a funcao de criacao da matriz.
      -Em seguida deve abrir um menu que permita utilizar amplamente as demais funcoes.
      -Implemente uma opcao/funcao que imprime somente os valores da diagonal secundaria,
       essa opcao somente pode funcionar se for quadrada quando a quantidade de linhas
       e colunas sao iguais.
      -Implemente uma opcao/funcao que imprime as quatro extremidades da matriz.
      -O programa devera executar ate que o usuario escolha a opcao sair, liberando a memoria e encerrando a execucao do programa.
    NAO:
      -Encerrar a execucao do programa.
  */



// ################
// # EXERCICIO 02 #
// ################

// Implemente a mesma estrutura de matriz de ponteiros de ponteiros utilizando TADs.

  /*
  Implemente a main de forma que todas as funcoes sejam utilizadas amplamente pelo usuario.
  Dados do tipo int.
  Ao executar o programa deve ser solicitado ao usuario se deseja criar a matriz:
    SIM:
      -Executar a funcao de criacao da matriz.
      -Em seguida deve abrir um menu que permita utilizar amplamente as demais funcoes.
      -Implemente uma opcao/funcao que imprime somente os valores da diagonal secundaria,
       essa opcao somente pode funcionar se for quadrada quando a quantidade de linhas
       e colunas sao iguais.
      -Implemente uma opcao/funcao que imprime as quatro extremidades da matriz.
      -O programa devera executar ate que o usuario escolha a opcao sair, liberando a memoria e encerrando a execucao do programa.
    NAO:
      -Encerrar a execucao do program
*/
