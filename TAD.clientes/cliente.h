/* Definição de um novo tipo: Cliente
*/
typedef struct cliente Cliente;

/* Função que aloca memoria dinamicamente para um struct Aluno
e recebe dados do cliente via teclado
*/
Cliente * cria_cliente(char nome[], int telefone, char endereco, char animais);
