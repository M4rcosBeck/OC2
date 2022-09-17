# MEMÓRIA COMPARTILHADA

* Permite que dois  ou mais processos compartilhem uma dada região de memória.
* É a forma mais rápida de IPC, uma vez que os dados não precisam ser copiados de um processo para o outro.
* **Problema:** dependendo da aplicação é preciso sincornizar o acesso a esta região de memória para evitar condições de corrida.

```
#include <sys/shm.h>
int shmget(key_t, size_t size, int flag);
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

* Uma vez criado o segmento de memória compartilhada, um processo utiliza esta função para associar um endereço do seu espaço de endereçamento ao segmento.
* Se `addr` == 0, é retornado o primeiro endereço disponível.
* Se `addr` <> 0 e `SHM_RND` não é especificado em flag, o segmento é associado ao endereço dado em `addr`.
* Se `addr` <> 0 e `SHM_RND`é especificado, o segmento é associado ao endereço dado por `(addr - (addr % SHMLBA))`.
* Se `SHM_RDONLY` é especificado em flag, o processo só terá permissão de leitura. Caso contrário, terá permissão de leitura e escrita.
---
```
#include <sys/shm.h>
int shmctl(int shmid, ind cmd, struct shmid_ds *buf);
```
* Função utilizada para solicitar várias operações sobre memória compartilhada.
* O argumento `cmd`especifica 5 comandos:
    1. `IPC_STAT` - Busca a estrutura `shmid_ds` e armazena na estrutura apontanda por buf.
    2. `IPC_SET` - Seta a permissão.
    3. `IPC_RMID` - Remove a memória.
    4. `SHM_LOCK` - *Grampeia* a memória compartilhada na memória (superusuário).
    5. `SHM_UNLOCK` - *Desgrampeia* a memória. Só pode ser executado pelo superusuário.