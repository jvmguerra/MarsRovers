#include<stdio.h>
#include<string.h>

//Problema: Mars Rover
//Autor: Jose Victor Martins Guerra

//Caso excessao: mover alem do mapeado(passar o mapa)
int possivelMover(int locy,int locx, char ori, int mapy, int mapx){
	switch(ori){
		case 'N':				//Verificar se ultrapassa o limite superior
			if ((locx+1)>mapx)
				return 0;
			return 1;
		case 'S':				//Verificar se ultrapassa o limite inferior
			if ((locx-1)<0)
				return 0;
			return 1;
		case 'E':				//Verificar se ultrapassa o limite da direita
			if ((locy+1)>mapy)
				return 0;
			return 1;
		case 'W':				//Verificar se ultrapassa o limite da esquerda
			if ((locx-1)<0)
				return 0;
			return 1;
	}
	return 0;
}

//Funcao principal
int main(){
	int mapy,mapx;									//Variáveis para mapeamento
	int count,len,flag=1;							//Utilizados em loops, count para avancar a string, len para tamanho de string
	int locy,locx;									//Guardar localização inicial
	char ori, mov[255];								//Guardar orientação inicial e string de movimento


	scanf("%d %d",&mapy, &mapx);					//Receber o tamanho do mapa a ser gerado

	while(scanf("%d %d %c", &locy,&locx,&ori)!=EOF){
		count=0;						//Reseta o contador para um novo movimento
		flag=1;							//Reseta a flag que imprime o resultado
		scanf("%s", mov);				//Receber movimento realizado pelo rover
		len=strlen(mov)-1;				//Receber tamanho da string de movimento

		while(count<=len){				//Loop para navegar pela string de movimento
			if(mov[count]=='L'){		//Tratar mudança de orientacao para a esquerda
				switch(ori){
					case 'N':
						ori='W';
						break;
					case 'W':
						ori='S';
						break;
					case 'S':
						ori='E';
						break;
					case 'E':
						ori='N';
						break;
				}
			}
			else if(mov[count]=='R'){	//Tratar mudança de orientacao para a direita
				switch(ori){
					case 'N':
						ori='E';
						break;
					case 'E':
						ori='S';
						break;
					case 'S':
						ori='W';
						break;
					case 'W':
						ori='N';
						break;
				}
			}	
			else{						//Tratar movimentacao
				if(!possivelMover(locy,locx,ori,mapy,mapx)){	//Verificar se eh possivel movimentar, considerando orientacao
					printf("O Rover nao pode mover para o local desejado\n");	//Mensagem de erro
					flag=0;				//Flag para nao imprimir movimentacao
					break;
				}
				switch(ori){
					case 'N':
						locx++;
						break;
					case 'S':
						locx--;
						break;
					case 'E':
						locy++;
						break;
					case 'W':
						locy--;
						break;
				}
			}
			count++;          //Caminhar na string de movimentos
		}
		if(flag)            //Se o rover pode mover para o destino final, imprimir resultado
			printf("%d %d %c\n", locy,locx,ori);
	}
	return 0;
}
