# CRIAÇÃO DE PROCESSOS
---
* Os processos (pai) podem criar outros processos (filhos), que, por sua vez criam outros processos, formando uma árvore de processos.
* **Execução:** Pais e Filhos são executados concorrentementes.
* Espaços de Endereços:
    * Filho é uma duplicata do pai.
    * Filho tem um programa carregado  nele.
* Exemplos do UNIX:
    * Chamada de sistema **fork** cria um novo processo.

## FORK
```
#include <unistd.h>
pid_t fork(void);
```
* Quando um processo é *"forked"* (bifurcado), um novo  processo é criado.
* O segmento de dados e códigoss do novo processo é o mesmo do original.
* Uma entrada na tabela de processos é criada para o novo processo.
* Valor de Retorno:
    * ZERO no processo filho.
    * O ID do processo filho (PID) no processo pai.
* Use o valor de retorno para identificar aonde o processo está.

```
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    if(fork() == 0){
        printf("Eu sou o processo filho!\n");
    }else{
        printf("Eu sou o processo pai!\n");
    }
}
```

## TÉRMINO DE PROCESSO
* O processo executa  sua instrução final e pede ao sistema operacional que o termine `exit()`.
* Os recursos do processo são desalocados pelo sistema operacional.

```
#include <stdlib.h>
int exit(int status);
```

* Realiza alguma limpeza e em seguida retorna.
* Possui um argumento inteiro, o exit status.
* Retorna um valor inteiro da função *main*, é equivalente a chamar *exit* com o mesmo valor.