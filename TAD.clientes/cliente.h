/* Definição de um novo tipo: Cliente
*/
typedef struct cliente Cliente;

/* Função que aloca memoria dinamicamente para um struct Aluno
e recebe dados do cliente via teclado
*/
Cliente * cria_cliente(void);

/* Função que realiza o cadastro de N clientes
*/
Cliente * cadastra_cliente(int num_clientes);

/* Função que abre um arquivo e imprime nele os dados dos clientes cadastradas
*/
void imprime_clientes (Cliente * consumidor, int num_clientes);