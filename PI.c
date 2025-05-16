#include <stdio.h>      // Biblioteca padrão de entrada e saída
#include <string.h>     // Biblioteca para manipulação de strings (como strcmp, strcspn, etc.)

// Estrutura para armazenar dados do usuário
struct Usuario {
    char nome[100];     // Nome do usuário (string de até 99 caracteres)
    int idade;          // Idade do usuário
    float peso;         // Peso inicial do usuário
    char objetivo[50];  // Objetivo (ex: emagrecer, ganhar massa, manter)
};

// Função para cadastrar um novo usuário
struct Usuario cadastrarUsuario() {
    struct Usuario u;   // Declara uma variável do tipo Usuario

    printf("=== Cadastro de Usuario ===\n");

    // Captura o nome do usuário
    printf("Nome: ");
    fgets(u.nome, sizeof(u.nome), stdin);
    u.nome[strcspn(u.nome, "\n")] = 0; // Remove o caractere '\n' inserido pelo fgets

    // Captura a idade
    printf("Idade: ");
    scanf("%d", &u.idade);

    // Captura o peso inicial
    printf("Peso (kg): ");
    scanf("%f", &u.peso);

    getchar(); // Limpa o buffer do teclado (remove o '\n' deixado pelo scanf)

    // Captura o objetivo do usuário
    printf("Objetivo (ex: emagrecer, ganhar massa, manter): ");
    fgets(u.objetivo, sizeof(u.objetivo), stdin);
    u.objetivo[strcspn(u.objetivo, "\n")] = 0; // Remove o '\n' do final da string

    return u; // Retorna o usuário preenchido
}

// Função que recomenda um treino com base no objetivo
void recomendarTreino(struct Usuario u) {
    printf("\n=== Recomendacao de Treino para %s ===\n", u.nome);

    // Compara o objetivo e fornece uma recomendação personalizada
    if (strcmp(u.objetivo, "emagrecer") == 0) {
        printf("Recomenda-se:\n- 5 dias/semana\n- Exercicios aerobicos e HIIT\n- 45 min por sessao\n");
    } else if (strcmp(u.objetivo, "ganhar massa") == 0) {
        printf("Recomenda-se:\n- 4 dias/semana\n- Treino de forca + dieta hipercalorica\n- 1h por sessao\n");
    } else {
        // Objetivo "manter" ou qualquer outro não especificado
        printf("Recomenda-se:\n- 3 dias/semana\n- Exercicios leves e alongamentos\n- 30 min por sessao\n");
    }
}

// Função que simula lembretes para o usuário
void exibirLembretes() {
    printf("\n=== Lembretes de Saude ===\n");
    printf("- Tome agua a cada 1h\n");
    printf("- Proximo treino: amanha as 7h\n");
    printf("- Consulta com nutricionista: 12/05 as 15h\n");
}

// Função que compara o peso inicial e o peso atual para mostrar progresso
void progressoUsuario(float pesoInicial, float pesoAtual) {
    printf("\n=== Acompanhamento de Progresso ===\n");
    float diferenca = pesoInicial - pesoAtual;

    if (diferenca > 0)
        printf("Voce perdeu %.2f kg desde o inicio do acompanhamento.\n", diferenca);
    else if (diferenca < 0)
        printf("Voce ganhou %.2f kg desde o inicio do acompanhamento.\n", -diferenca);
    else
        printf("Seu peso permaneceu o mesmo desde o inicio.\n");
}

// Função principal do programa
int main() {
    struct Usuario user = cadastrarUsuario();   // Cadastra o usuário e armazena em 'user'
    recomendarTreino(user);                     // Mostra a recomendação de treino com base no objetivo
    exibirLembretes();                          // Exibe lembretes de saúde

    float pesoAtual;
    printf("\nDigite seu peso atual: ");
    scanf("%f", &pesoAtual);                    // Lê o peso atual do usuário

    progressoUsuario(user.peso, pesoAtual);     // Compara com o peso inicial e exibe o progresso

    return 0;   // Fim da execução do programa
}
