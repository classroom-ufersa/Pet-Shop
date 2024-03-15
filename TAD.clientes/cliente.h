/* Definição de um novo tipo: Cliente
*/
typedef struct cliente Cliente;

/* Função que aloca memoria dinamicamente para um struct Aluno
e recebe dados do cliente via teclado
*/
Cliente * cria_cliente(char nome[], int telefone, char endereco, char animais);

/* Função que abre um arquivo e imprime nele os dados das frutas cadastradas
*/
void imprime_clientes (Cliente * consumidor, int num_clientes);

/* Função que imprime os dados dos clientes no arquivo "clientes.txt"
*/
void imprime_clientes (Cliente * consumidor, int num_clientes);


