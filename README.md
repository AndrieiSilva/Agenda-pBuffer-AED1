# Trabalho prático 2 de AED1

**Nome: Andriei Roshild da Silva**

**Disciplina: Algoritmos e Estruturas de Dados 1**

**Turma: M2**

**Instituição de Ensino: Universidade Federal de Pelotas**

# Exercício: Agenda pBuffer
## Descrição do exercício:
Faça uma agenda com o seguinte menu:

1- Adicionar Pessoa (Nome, Idade, email)

2- Remover Pessoa

3- Buscar Pessoa

4- Listar todos

5- Sair
 
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.
 
Regras:
Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.

Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.

Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)

Não pode usar struct em todo o programa.

## Realização do exercício:

O código funciona como deveria (o que não funciona direito é o VS CODE, que fica dando pause durante a execução, fica escrito no debugger "Pause on Pause");

Testei o código adicionando pessoas, removendo, buscando e listando pessoas da lista. Funcionou certo. 
### **OBS :** _O código não verifica a entrada, ou seja, ele supõe que o usuário seja "bonzinho"._
