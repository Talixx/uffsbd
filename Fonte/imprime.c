//BufferPool
#include "buffend.h"

/* ----------------------------------------------------------------------------------------------
    Objetivo:   Utilizada para impressão de tabelas (select * from table;).
    Parametros: Nome da tabela (char).
    Retorno:    void.
   ---------------------------------------------------------------------------------------------*/

void imprime(rc_parser globalParserSelect,rc_select globalDataSelect) {

    int j,erro, x, p, cont=0;
    struct fs_objects objeto;

    


    if(!verificaNomeTabela(globalDataSelect.objName)){
        printf("\nERROR: relation \"%s\" was not found.\n\n\n", globalDataSelect.objName);
        return;
    }

    objeto = leObjeto(globalDataSelect.objName);

    tp_table *esquema = leSchema(objeto);

    if(esquema == ERRO_ABRIR_ESQUEMA){
        printf("ERROR: schema cannot be created.\n");
        free(esquema);
        return;
    }

    tp_buffer *bufferpoll = initbuffer();

    if(bufferpoll == ERRO_DE_ALOCACAO){
        free(bufferpoll);
        free(esquema);
        printf("ERROR: no memory available to allocate buffer.\n");
        return;
    }

    erro = SUCCESS;
    for(x = 0; erro == SUCCESS; x++)
        erro = colocaTuplaBuffer(bufferpoll, x, esquema, objeto);

    int ntuples = --x;
	p = 0;

printf("adsas\n");
    for(j=0; j < globalParserSelect.col_count; j++){
        printf("%s\n",esquema->nome);
    }

    if(!(globalDataSelect.columnName[0][0] == '*')){
        tp_table *aux,*aux2;
        tp_table *novoEsquema;

        int i=0;
        for(aux = esquema; aux != NULL; aux = aux->next){
            for(i=0;i<globalParserSelect.col_count;i++){
                if(!strcmp(aux->nome,globalDataSelect.columnName[i])){
                    printf("%s----%s\n",aux->nome,globalDataSelect.columnName[i]);
        

                    if(novoEsquema->first==NULL){
                        aux2  = malloc(sizeof(tp_table));
                        aux2 ->next = NULL;
                        novoEsquema->first = aux2;

                        printf("%s----\n",novoEsquema->nome);
                    }else{
                        aux2  = malloc(sizeof(tp_table));
                        aux2 -> next = NULL;
                        aux2 = aux;
                        novoEsquema->next = aux2;

                        printf("%s----2\n",novoEsquema->nome);

                    }

                    


                    //novoEsquema = aux;

                    /*char nome[TAMANHO_NOME_CAMPO];  // Nome do Campo.                    40bytes
                    char tipo;                      // Tipo do Campo.                     1bytes
                    int tam;                        // Tamanho do Campo.                  4bytes
                    int chave;                      // Tipo da chave                      4bytes
                    char tabelaApt[TAMANHO_NOME_TABELA]; //Nome da Tabela Apontada        20bytes
                    char attApt[TAMANHO_NOME_CAMPO];    //Nome do Atributo Apontado       40bytes
                    struct tp_table *next;          // Encadeamento para o próximo campo.*/
                }
            }
        }
        //esquema = novoEsquema->first;
        //objeto.qtdCampos = globalParserSelect.col_count;
        for(aux = novoEsquema->first; aux != NULL; aux = aux->next){
            printf("####%s\n",aux->nome);
            printf("***%c\n",aux->tipo);
            printf("***%d\n",aux->tam);
            printf("***%d\n",aux->chave);

        }


    }

    printf("auqi\n");
	while(x){
	    column *pagina = getPage(bufferpoll, esquema, objeto, p);
	    if(pagina == ERRO_PARAMETRO){
            printf("ERROR: could not open the table.\n");
            free(bufferpoll);
            free(esquema);
            return;
	    }
	    if(!cont) {
	        for(j=0; j < objeto.qtdCampos; j++){
	            if(pagina[j].tipoCampo == 'S')
	                printf(" %-20s ", pagina[j].nomeCampo);
	        	else
	                printf(" %-10s ", pagina[j].nomeCampo);
	            if(j<objeto.qtdCampos-1)
	            	printf("|");
	        }
	        printf("\n");
	        for(j=0; j < objeto.qtdCampos; j++){
	            printf("%s",(pagina[j].tipoCampo == 'S')? "----------------------": "------------");
	            if(j<objeto.qtdCampos-1)
	            	printf("+");
	        }
	        printf("\n");
	    }
	    cont++;
		for(j=0; j < objeto.qtdCampos*bufferpoll[p].nrec; j++){
        	if(pagina[j].tipoCampo == 'S')
            	printf(" %-20s ", pagina[j].valorCampo);
        	else if(pagina[j].tipoCampo == 'I'){
            	int *n = (int *)&pagina[j].valorCampo[0];
            	printf(" %-10d ", *n);
        	} else if(pagina[j].tipoCampo == 'C'){
            	printf(" %-10c ", pagina[j].valorCampo[0]);
        	} else if(pagina[j].tipoCampo == 'D'){
            	double *n = (double *)&pagina[j].valorCampo[0];
    	        printf(" %-10f ", *n);
        	}
            if(j>=1 && ((j+1)%objeto.qtdCampos)==0)
            	printf("\n");
        	else
        		printf("|");
    	}
    	x-=bufferpoll[p++].nrec;
    }
    printf("\n(%d %s)\n\n",ntuples,(1>=ntuples)?"row": "rows");

    free(bufferpoll);
    free(esquema);
}
