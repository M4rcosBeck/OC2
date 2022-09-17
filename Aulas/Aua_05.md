# MEMÓRIA COMPARTILHADA

* Permite que dois  ou mais processos compartilhem uma dada região de memória.
* É a forma mais rápida de IPC, uma vez que os dados não precisam ser copiados de um processo para o outro.
* **Problema:** dependendo da aplicação é preciso sincornizar o acesso a esta região de memória para evitar condições de corrida.

```
#include <sys/shm.h>
int shmget(kkey_t, size_t size, int flag);
```

* Primeira função a ser chamada para obter um identificador de memória compartilhada.
* Size é o tamanho mínimo do segmento de memória compartilhado. Se um novo segmento está sendo criado precisa-se especificar o seu tamanho. Se estamos referenciando um segmento já existente especifica-se o tamanho
como 0 (zero).
* O campo flag é inicializado de acordo com as permissões (Escrita/Leitura);
* Cada estrutura IPC (ex.: segmento de memória compartilhada) é referenciada no kernel através de um identificador.
* O identificador é um nome interno. Os processos cooperativo precisam de um esquema de nomeação externo, que é dado através de uma key.
* O processo pai cria uma nova estrutura IPC especificando `IPC_PRIVATE` como key.
* Dois processos podem concordar com um *pathname* e um *projectID* (valor entre 0 e 255) e chamar a função `ftok` para converter esses valores em uma key.

```
#include <sys/ipc.h>
key_t ftok(const *path, int id);
```

```
#include <sys/shm.h>
void *shmat(int shmid, const void *addr, int flag);
```

* Uma vez criado o segmento de memória compartilhada,, um processo utiliza esta função para associar um endereço do seu espaço de endereçamento ao segmento.
