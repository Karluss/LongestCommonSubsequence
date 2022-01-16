//Carlos Manoel Pedrosa de Oliveira - TIA: 32068549
//Felipe Padilha Ferreira - TIA: 32013434
//Pedro Galvão Barretto - TIA: 32016591

#include <stdio.h>
#include <string.h>

void LongestCommonSubsequence(char x[], char y[]){
    int m = strlen(x);
    int n = strlen(y);
    int table[m+1][n+1]; //cria uma tabela com a sequência X na vertical e a sequência Y na horizontal

    //Define a primeira coluna e a primeira linha com zeros.
    for (int i = 0; i <= m; i++){
        table[i][0] = 0;
    }
    for (int j = 0; j <= n; j++){
        table[0][j] = 0;
    }

    //Resolve a tabela para achar a subsequência mais longa.
    for (int i = 1; i <=m; i++){
        for(int j = 1; j <= n; j++){
            if (x[i-1] == y[j-1]){
                table[i][j] = table[i-1][j-1]+1;
            }
            else if (table[i-1][j] >= table[i][j-1]){
                table[i][j] = table[i-1][j];
            }
            else{
                table[i][j] = table[i][j-1];
            }
        }
    }

    //Mostra a tabela montada:
    printf("\nTABELA MONTADA PARA ACHAR A SUBSEQUENCIA MAIS LONGA :\n");
    int row, columns;
    for (row=0; row<m; row++)
    {
        for(columns=0; columns<n; columns++)
        {
             printf("%d     ", table[row][columns]);
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------");

    int size = table[m][n]; // O tamanho da LCS é definido pelo valor encontrado no extremo inferior direito.
    char subsequence[size+1]; //Cria vetor pra armazenar a LCS.
    subsequence[size] = '\0'; //Para o código saber quando termina a string.

    //Armazena a LCS em um vetor.
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            subsequence[size - 1] = x[i - 1];
            i--;
            j--;
            size--;
        }
        else if (table[i - 1][j] > table[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
  }
  printf("\nSubsequencia mais longa: %s\n", subsequence);


}

int main(){
    char sequencia1[] = "ABCDAB";
    char sequencia2[] = "BDCABA";
    printf("Sequencia 1: %s\n", sequencia1);
    printf("Sequencia 2: %s\n", sequencia2);
    printf("------------------------------------------------------------------");
    LongestCommonSubsequence(sequencia1,sequencia2);
    return 0;
}
