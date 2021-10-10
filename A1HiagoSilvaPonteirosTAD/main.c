#include <stdlib.h>
#include <stdio.h>

// Estrutura criada da matriz em struct para manipulacao utilizando TAD
struct matriz{

  int linha;
  int coluna;
};

typedef struct matriz Matriz;

int** criaMatriz(int m, int n){
    int** matriz;

    matriz = (int **)malloc( m * sizeof(int *));
    for(int i=0; i<m; i++ ){
        matriz[i] = (int *)malloc( n * sizeof(int));
    }

    return matriz;
}

Matriz* criaStructMatriz(int m, int n){
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));

    if (mat == NULL){
    printf("Memoria insuficiente!\n");
    exit(1);
    }

    mat->linha = m;
    mat->coluna = n;

    return mat;
}

// Observe a funcao e explique o funcionamento?
void libera(int **matriz, Matriz* mat){

    for(int i=0; i<mat->coluna; i++ ){
        free(matriz[i]);
    }
    free(matriz);
}

// Observe a funcao e explique o funcionamento?
float acessa(int **matriz, int linhaRecebida, int colunaRecebida) {

  return matriz[linhaRecebida][colunaRecebida];

}

// Observe a funcao e explique o funcionamento?
void atribui(int** matriz, int linhaRecebida, int colunaRecebida, int valor) {
    matriz[linhaRecebida][colunaRecebida] = valor;
}

// Observe a funcao e explique o funcionamento?
int linhas(Matriz* mat){

    return mat->linha;
}

//Observe a funcao e explique o funcionamento?
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


void mostrarDiagonalSecundaria(int** matriz, Matriz* mat){
    int linha = mat->linha;
    int coluna = mat->coluna;
    float vetorValores[linha];

    for(int i = 0; i < linha; i++){

        vetorValores[i] =  acessa(matriz, i, coluna-1);

        coluna--;
    }

    printf("\nOs valores da diagonal sao: ");
    imprimeVetor(vetorValores, linha);
}


void mostrarExtremidades(int** matriz, Matriz* mat){
    float vetorValores[4];

    vetorValores[0] = acessa(matriz, 0, 0);
    vetorValores[1] =  acessa(matriz, 0, mat->coluna-1);
    vetorValores[2] =  acessa(matriz, mat->linha-1, 0);
    vetorValores[3] =  acessa(matriz, mat->linha-1, mat->coluna-1);

    printf("\nOs valores das extremidades sao: ");
    imprimeVetor(vetorValores, 4);
}

void limpaTela() {
    system("CLS");
}

Matriz* criarNovaStructMatriz(int linha, int coluna){

    Matriz* mat = criaStructMatriz(linha, coluna);

    return mat;
}

int** criarNovaMatriz(int linha, int coluna){

    int** matriz = criaMatriz(linha, coluna);

    return matriz;
}

void populaMatriz(int** matriz, Matriz* mat){
    int valorAux = 0;
    for(int i = 0; i < mat->linha; i++){
            for(int j = 0; j < mat->coluna; j++){
                atribui(matriz, i, j, valorAux);
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


void menu(int** matriz, Matriz* mat){
        int linhaNovaMatriz;
        int colunaNovaMatriz;
        int opcao = mostraOpcao();

        do {

            switch(opcao){
                case 1:
                    limpaTela();

                    printf("Quantidade de linhas: %d \n\n\n", linhas(mat));

                    menu(matriz, mat);
                break;

                case 2:
                    limpaTela();

                    printf("Quantidade de colunas: %d \n\n\n", colunas(mat));

                    menu(matriz, mat);
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

                    atribui(matriz, linhaInserir, colunaInserir, valor);

                    printf("\nValor inserido: %d, na linha %d e coluna %d \n\n\n", valor, linhaInserir, colunaInserir);

                    menu(matriz, mat);
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

                    valorBuscado = acessa(matriz,linhaBuscar, colunaBuscar);

                    printf("\nValor encontrado foi : %d \n\n\n", valorBuscado);

                    menu(matriz, mat);

                break;

                case 5:
                    limpaTela();
                    libera(matriz, mat);
                    printf("Qual o tamanho da matriz que voce deseja ?  ");
                    printf("\nLinhas: ");
                    scanf("%d", &linhaNovaMatriz);
                    printf("Coluna: ");
                    scanf("%d", &colunaNovaMatriz);

                    mat = criarNovaStructMatriz(linhaNovaMatriz, colunaNovaMatriz);
                    matriz = criarNovaMatriz(linhaNovaMatriz, colunaNovaMatriz);
                    populaMatriz(matriz, mat);

                    printf("\nMatriz criada tamanho linha: %d coluna %d \n\n\n", linhaNovaMatriz, colunaNovaMatriz);

                    menu(matriz, mat);

                break;

                case 6:
                    limpaTela();
                    if(linhas(mat)== colunas(mat)){
                        mostrarDiagonalSecundaria(matriz, mat);
                        menu(matriz, mat);
                    }else{
                        printf("\nSua matriz nao e quadrada, para isto recrie ela. \n\n\n");
                        menu(matriz, mat);
                    }

                break;

                case 7:
                    limpaTela();
                    mostrarExtremidades(matriz, mat);
                    menu(matriz, mat);

                break;

                case 0:
                    libera(matriz, mat);
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

        int** matriz = criaMatriz(linha, coluna);
        Matriz* mat = criaStructMatriz(linha, coluna);
        populaMatriz(matriz, mat);
        limpaTela();
        menu(matriz, mat);

        return 0;
    }
 }
