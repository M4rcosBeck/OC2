# INTRODUÇÃO À PTHREADS

* Uma API do padrão POSIX (IEEE 1003.1C) para crição e sinconismo de threads.
* A API especifica o comportmento da biblioteca de threads. A implementação cabe ao desenvolvimento da biblioteca.
* Comuns nos sistemas operacionais UNIX (Solaris, Linux, Mac OS X).
* Toda thread possui uma thread ID (TID), que tem sentido no contexto do processo.
* TID é representado pela estrutura de dados `pthread_t`.
* A função `pthread_equal` é usada para comparar dois TIDs.
* Uma thread pode obter seu TID chamando a função `pthread_self`.

```
#include <pthread.h>

int pthread_equal(pthread_t tid1, pthread_t tid2);
pthread_t pthread_self(void);
```

## PTHREADS
* Um programa inicia sua execução como um processo com uma única thread de controle.
* Threads adicionais podem ser criadas chamando a função `pthread_create`.
`int pthread_create(pthread_t *tidp, const pthread_attr_t *attr, void *(*start_rtn)(void), void *arg);`

* *tidp* aponta para o TID da nova thread criada.
* O argumento *attr* é usado para customizar vários atributos. Para utilizar os atributos *default*, este parâmetro deve ser `NULL`;
`int pthread_create(pthread_t *tidp, const pthread_attr_t *attr, void *(*start_rtn)(void), void *arg);`

* A nova thread inicia executanto a função `start_rtn`.
* Esta função recebe um único argumento (*arg*). Caso seja necessário passar mais do que um argumento, deve-se armazená-los e uma estrutura e passar o endereço da estrutura em *arg*.
`int pthread_create(pthread_t *tidp, const pthread_attr_t *attr, void *(*start_rtn)(void), void *arg);`

## TÉRMINO DE PTHREADS
* Se qualquer thread de um processo chamar `exit` ou `_exit`, o processo inteiro termina.
* Uma thread pode terminar seu fluxo de controle sem terminar o processo inteiro de três formas:
    1. A thread pode retornar da rotina inicial (o valor de retorno é o código de saída da thread).
    2. A thread pode ser cancelada por outra thread do mesmo processo.

```
#inlcude <pthread.h>
void pthread_exit(void *rval_ptr);
int pthread_join(pthread_t thread, void **rval_ptr);
int pthread_cancel(pthread_t tid);
```
* O `rval_ptr` é um ponteiro disponibilizado a outras threads do processo através da chamada à função `pthread_join`;
* Ao chamar `pthread_join`, a thread é bloqueada até da thread especificada terminar.
* Se a thread retornar da sua rotina inicial, `rval_ptr` irá conter o código de retorno.
* Se a thread foi cancelada, será retornado o valor `PTHREAD_CANCELED`.
* Uma thread pode cancelar outra thread do mesmo processo através da função `pthread_cancel`.