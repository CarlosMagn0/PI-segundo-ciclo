#include <stdio.h>
#include <string.h>

// Estrutura para armazenar dados do usuário
struct Usuario {
    char nome[100];
    int idade;
    float peso;
    char objetivo[50];
};

// Função para cadastrar um novo usuário
struct Usuario cadastrarUsuario() {
    struct Usuario u;

    printf("=== Cadastro de Usuario ===\n");

    printf("Nome: ");
    fgets(u.nome, sizeof(u.nome), stdin);
    u.nome[strcspn(u.nome, "\n")] = 0; // Remove '\n'

    printf("Idade: ");
    scanf("%d", &u.idade);

    printf("Peso (kg): ");
    scanf("%f", &u.peso);

    getchar(); // Limpa buffer do scanf

    printf("Objetivo (ex: emagrecer, ganhar massa, manter): ");
    fgets(u.objetivo, sizeof(u.objetivo), stdin);
    u.objetivo[strcspn(u.objetivo, "\n")] = 0;

    return u;
}

// Recomendação personalizada de treino
void recomendarTreino(struct Usuario u) {
    printf("\n=== Recomendacao de Treino para %s ===\n", u.nome);

    if (strcmp(u.objetivo, "emagrecer") == 0) {
        printf("Recomenda-se:\n- 5 dias/semana\n- Exercicios aerobicos e HIIT\n- 45 min por sessao\n");
    } else if (strcmp(u.objetivo, "ganhar massa") == 0) {
        printf("Recomenda-se:\n- 4 dias/semana\n- Treino de forca + dieta hipercalorica\n- 1h por sessao\n");
    } else {
        printf("Recomenda-se:\n- 3 dias/semana\n- Exercicios leves e alongamentos\n- 30 min por sessao\n");
    }
}

// Exibe lembretes simulados
void exibirLembretes() {
    printf("\n=== Lembretes de Saude ===\n");
    printf("- Tome agua a cada 1h\n");
    printf("- Proximo treino: amanha as 7h\n");
    printf("- Consulta com nutricionista: 12/05 as 15h\n");
}

// Simula o progresso com base no peso
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

// Função principal
int main() {
    struct Usuario user = cadastrarUsuario();
    recomendarTreino(user);
    exibirLembretes();

    float pesoAtual;
    printf("\nDigite seu peso atual: ");
    scanf("%f", &pesoAtual);

    progressoUsuario(user.peso, pesoAtual);

    return 0;
}
