#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50

typedef struct {
    char marca[50];
    char site[50];
    char telefone[15];
    char uf[3];
} Fabricante;

typedef struct {
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    Fabricante fabricante;
} Produto;

int numFabricantes = 0;
Fabricante fabricantes[MAX_FABRICANTES];

int numProdutos = 0;
Produto produtos[MAX_PRODUTOS];

void cadastrarFabricante() {
    if (numFabricantes >= MAX_FABRICANTES) {
        printf("Numero maximo de fabricantes atingido.\n");
        return;
    }

    Fabricante fabricante;
    printf("Fabricante %d:\n", numFabricantes + 1);
    printf("Marca: ");
    fgets(fabricante.marca, sizeof(fabricante.marca), stdin);
    fabricante.marca[strcspn(fabricante.marca, "\n")] = '\0';
    fgets(fabricante.marca, sizeof(fabricante.marca), stdin);
    fabricante.marca[strcspn(fabricante.marca, "\n")] = '\0';

    printf("Site: ");
    fgets(fabricante.site, sizeof(fabricante.site), stdin);
    fabricante.site[strcspn(fabricante.site, "\n")] = '\0';

    printf("Telefone: ");
    fgets(fabricante.telefone, sizeof(fabricante.telefone), stdin);
    fabricante.telefone[strcspn(fabricante.telefone, "\n")] = '\0';

    printf("UF: ");
    fgets(fabricante.uf, sizeof(fabricante.uf), stdin);
    fabricante.uf[strcspn(fabricante.uf, "\n")] = '\0';

    fabricantes[numFabricantes++] = fabricante;
}

void cadastrarProduto() {
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Numero maximo de produtos atingido.\n");
        return;
    }

    printf("========================================================\n");
    printf("              CADASTRO DE PRODUTO                \n");
    printf("========================================================\n");

    Produto produto;
    printf("Produto %d:\n", numProdutos + 1);
    printf("Descricao: ");
    fgets(produto.descricao, sizeof(produto.descricao), stdin);
    produto.descricao[strcspn(produto.descricao, "\n")] = '\0';
    fgets(produto.descricao, sizeof(produto.descricao), stdin);
    produto.descricao[strcspn(produto.descricao, "\n")] = '\0';

    printf("Peso: ");
    scanf("%f", &produto.peso);

    printf("Valor de compra: ");
    scanf("%f", &produto.valorCompra);

    printf("Valor de venda: ");
    scanf("%f", &produto.valorVenda);

    produto.valorLucro = produto.valorVenda - produto.valorCompra;
    produto.percentualLucro = (produto.valorLucro / produto.valorCompra) * 100;

    printf("Fabricante: \n");
    int escolha;
    for (int i = 0; i < numFabricantes; i++) {
        printf("[%d] %s\n", i + 1, fabricantes[i].marca);
    }
    printf("Escolha um fabricante: ");
    scanf("%d", &escolha);
    if (escolha >= 1 && escolha <= numFabricantes) {
        produto.fabricante = fabricantes[escolha - 1];
    } else {
        printf("Escolha invalida. O produto nao tera fabricante definido.\n");
        produto.fabricante.marca[0] = '\0';
    }

    getchar();  // Limpar o buffer do teclado

    produtos[numProdutos++] = produto;
}

void listarMarcas() {
    printf("========================================================\n");
    printf("            RELATORIO - LISTA DE TODAS AS MARCAS        \n");
    printf("========================================================\n");
    printf("Marca                | Site                   | Telefone           | UF\n");
    printf("----------------------+------------------------+---------------------+----\n");
    for (int i = 0; i < numFabricantes; i++) {
        printf("%-20s | %-22s | %-18s | %s\n",
               fabricantes[i].marca,
               fabricantes[i].site,
               fabricantes[i].telefone,
               fabricantes[i].uf);
    }

    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

void listarProdutos() {
    printf("========================================================\n");
    printf("           RELATORIO - LISTA DE TODOS OS PRODUTOS       \n");
    printf("========================================================\n");
    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");

    for (int i = 0; i < numProdutos; i++) {
        printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
               produtos[i].descricao,
               produtos[i].peso,
               produtos[i].valorCompra,
               produtos[i].valorVenda,
               produtos[i].valorLucro,
               produtos[i].percentualLucro,
               produtos[i].fabricante.marca,
               produtos[i].fabricante.site,
               produtos[i].fabricante.telefone,
               produtos[i].fabricante.uf);
    }

    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}


void listarProdutosEstado() {
    char estado[3];

    printf("========================================================\n");
    printf("       RELATORIO - PRODUTOS POR ESTADO              \n");
    printf("========================================================\n");

    printf("Digite o estado (UF): ");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';

    printf("========================================================\n");
    printf("              PRODUTOS NO ESTADO %s              \n", estado);
    printf("========================================================\n");
    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");
    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.uf, estado) == 0) {
            encontrou = 1;
            printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
                   produtos[i].descricao,
                   produtos[i].peso,
                   produtos[i].valorCompra,
                   produtos[i].valorVenda,
                   produtos[i].valorLucro,
                   produtos[i].percentualLucro,
                   produtos[i].fabricante.marca,
                   produtos[i].fabricante.site,
                   produtos[i].fabricante.telefone,
                   produtos[i].fabricante.uf);

            encontrou++;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto encontrado para o estado %s.\n", estado);
    }
    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

void listarProdutosMarca() {
    char marca[50];
    printf("========================================================\n");
    printf("       RELATORIO - PRODUTOS POR MARCA              \n");
    printf("========================================================\n");

    printf("Escolha a marca: ");
    fgets(marca, sizeof(marca), stdin);
    marca[strcspn(marca, "\n")] = '\0';
    fgets(marca, sizeof(marca), stdin);
    marca[strcspn(marca, "\n")] = '\0';

    printf("========================================================\n");
    printf("              PRODUTOS DA MARCA %s              \n", marca);
    printf("========================================================\n");
    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");
    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.marca, marca) == 0) {
            encontrou = 1;
            printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
                   produtos[i].descricao,
                   produtos[i].peso,
                   produtos[i].valorCompra,
                   produtos[i].valorVenda,
                   produtos[i].valorLucro,
                   produtos[i].percentualLucro,
                   produtos[i].fabricante.marca,
                   produtos[i].fabricante.site,
                   produtos[i].fabricante.telefone,
                   produtos[i].fabricante.uf);

            encontrou++;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto encontrado para a marca %s.\n", marca);
    }

    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

void produtoMaisCaro() {
    float valorMaximo = 0;
    printf("========================================================\n");
    printf("   RELATORIO - ESTADO(S) COM PRODUTO MAIS CARO    \n");
    printf("========================================================\n");
    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");


    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda > valorMaximo) {
            valorMaximo = produtos[i].valorVenda;
        }
    }

    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda == valorMaximo) {
            encontrou = 1;
            printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
                   produtos[i].descricao,
                   produtos[i].peso,
                   produtos[i].valorCompra,
                   produtos[i].valorVenda,
                   produtos[i].valorLucro,
                   produtos[i].percentualLucro,
                   produtos[i].fabricante.marca,
                   produtos[i].fabricante.site,
                   produtos[i].fabricante.telefone,
                   produtos[i].fabricante.uf);
        }
    }
    if (!encontrou) {
        printf("Nenhum produto encontrado.\n");
    }

    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

void produtoMaisBarato() {
    float valorMinimo = produtos[0].valorVenda;
    printf("========================================================\n");
    printf("   RELATORIO - FABRICANTE(S) COM PRODUTO MAIS BARATO   \n");
    printf("========================================================\n");
    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");

    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].valorVenda < valorMinimo) {
            valorMinimo = produtos[i].valorVenda;
        }
    }

    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda == valorMinimo) {
            encontrou = 1;
            printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
                   produtos[i].descricao,
                   produtos[i].peso,
                   produtos[i].valorCompra,
                   produtos[i].valorVenda,
                   produtos[i].valorLucro,
                   produtos[i].percentualLucro,
                   produtos[i].fabricante.marca,
                   produtos[i].fabricante.site,
                   produtos[i].fabricante.telefone,
                   produtos[i].fabricante.uf);
        }
    }
    if (!encontrou) {
        printf("Nenhum produto encontrado.\n");
    }
    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

void ordenarPorValor() {
    printf("========================================================\n");
    printf("     RELATORIO - PRODUTOS EM ORDEM CRESCENTE DE VALOR    \n");
    printf("========================================================\n");

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");

    for (int i = 0; i < numProdutos; i++) {
        printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
               produtos[i].descricao,
               produtos[i].peso,
               produtos[i].valorCompra,
               produtos[i].valorVenda,
               produtos[i].valorLucro,
               produtos[i].percentualLucro,
               produtos[i].fabricante.marca,
               produtos[i].fabricante.site,
               produtos[i].fabricante.telefone,
               produtos[i].fabricante.uf);
    }

    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

void ordenarPorLucro() {
    printf("========================================================\n");
    printf("   RELATORIO - PRODUTOS EM ORDEM CRESCENTE DE LUCRO   \n");
    printf("========================================================\n");

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");

    for (int i = 0; i < numProdutos; i++) {
        printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
               produtos[i].descricao,
               produtos[i].peso,
               produtos[i].valorCompra,
               produtos[i].valorVenda,
               produtos[i].valorLucro,
               produtos[i].percentualLucro,
               produtos[i].fabricante.marca,
               produtos[i].fabricante.site,
               produtos[i].fabricante.telefone,
               produtos[i].fabricante.uf);
    }

    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

void ordenarPorPercentualLucro() {
    printf("========================================================\n");
    printf("RELATORIO - PRODUTOS EM ORDEM CRESCENTE DE PERCENTUAL LUCRO\n");
    printf("========================================================\n");

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].percentualLucro > produtos[j + 1].percentualLucro) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("Descricao         | Peso   | Valor Compra | Valor Venda | Valor Lucro | Percentual Lucro | Marca                | Site                    | Telefone        | UF\n");
    printf("------------------+--------+--------------+-------------+--------------+------------------+----------------------+-------------------------+-----------------+----\n");


    for (int i = 0; i < numProdutos; i++) {
        printf("%-18s | %-6.2f | R$%-10.2f | R$%-9.2f | R$%-9.2f | %-16.2f | %-20s | %-24s | %-15s | %s\n",
               produtos[i].descricao,
               produtos[i].peso,
               produtos[i].valorCompra,
               produtos[i].valorVenda,
               produtos[i].valorLucro,
               produtos[i].percentualLucro,
               produtos[i].fabricante.marca,
               produtos[i].fabricante.site,
               produtos[i].fabricante.telefone,
               produtos[i].fabricante.uf);
    }

    printf("========================================================\n");
    printf("- [9] Voltar para tela principal\n");
    printf("- [0] Sair do programa\n");
    printf("========================================================\n");

    int opcao;
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 9:
            system("cls");
            return;
        case 0:
            printf("Saindo do programa...\n");
            system("cls");
            exit(0);
        default:
            printf("Opcao invalida. Retornando para tela principal...\n");
            system("cls");
            return;
    }

}

int main() {
    int opcao;

    do {
        printf("========================================================\n");
        printf("                  SISTEMA DE PRODUTOS              \n");
        printf("========================================================\n");
        printf("[1] Cadastrar Fabricantes\n");
        printf("[2] Cadastrar produtos\n");
        printf("[3] Listar todas as marcas\n");
        printf("[4] Listar todos os produtos\n");
        printf("[5] Listar os produtos de um determinado estado\n");
        printf("[6] Listar os produtos de uma determinada marca\n");
        printf("[7] Apresentar o(s) estado(s) onde esta registrado o produto mais caro\n");
        printf("[8] Apresentar o(s) fabricante(s) onde esta registrado o produto mais barato\n");
        printf("[9] Listar todos os produtos em ordem crescente de valor\n");
        printf("[10] Listar todos os produtos em ordem crescente de maior 'valor do lucro'\n");
        printf("[11] Listar todos os produtos em ordem crescente de maior 'percentual de lucro'\n");
        printf("[0] Sair do programa\n");
        printf("========================================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 2:
                cadastrarProduto();
                break;
            case 3:
                listarMarcas();
                break;
            case 4:
                listarProdutos();
                break;
            case 5:
                listarProdutosEstado();
                break;
            case 6:
                listarProdutosMarca();
                break;
            case 7:
                produtoMaisCaro();
                break;
            case 8:
                produtoMaisBarato();
                break;
            case 9:
                ordenarPorValor();
                break;
            case 10:
                ordenarPorLucro();
                break;
            case 11:
                ordenarPorPercentualLucro();
                break;
            case 1:
                cadastrarFabricante();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}
