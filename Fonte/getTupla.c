//BufferPool
#include "buffend.h"

// INSERE UMA TUPLA NO BUFFER!
char *getTupla(tp_table *campos,struct fs_objects objeto, int from){ //Pega uma tupla do disco a partir do valor de from

    int tamTpl = tamTupla(campos, objeto);
    int i;
    char *linha=(char *)malloc(sizeof(char)*tamTpl);
    memset(linha, '\0', tamTpl);

    FILE *dados;

    from = from * tamTpl;

	char directory[LEN_DB_NAME*2];
    strcpy(directory, connected.db_directory);
    strcat(directory, objeto.nArquivo);

    dados = fopen(directory, "r");

    if (dados == NULL) {
        free(linha);
        return ERRO_DE_LEITURA;
    }

    /*fseek(dados, from, 1);
    if(fgetc (dados) != EOF){
        fseek(dados, -1, 1);
        fread(linha, sizeof(char), tamTpl, dados); //Traz a tupla inteira do arquivo
    } else {       //Caso em que o from possui uma valor inválido para o arquivo de dados
        fclose(dados);
        free(linha);
        return ERRO_DE_LEITURA;
    }*/
    for (i = 0; i < objeto.qtdCamposSelect; ++i){
        fseek(dados, (campos[i].tam*campos[i].pos),SEEK_SET);
        campos[i].valor = malloc(sizeof(char)*campos[i].tam);
        fread(campos[i].valor,sizeof(char),campos[i].tam,dados);
        strcat(linha,campos[i].valor);
    }   

    fclose(dados);
    return linha;
}