#include <iostream>
#include <locale.h>
#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

struct Personagens {

    string nome;
    string classe;
    vector<int> atributos; //Vida - Força - Destreza - Inteligência
    int vida;
};

struct Inimigos {

    string nome;
    vector<int> atributos;
    int vida;
};

//Função de obtençao de classe e informação de jogador
void funcClasse(int nclasse, string& nome, string& classe0, int& vida, vector<int>& atributos0) {

    string classe;
    vector<int> atributos;

    switch (nclasse)
    {
    default:
        break;

    case 1:
        classe = "Guerreiro";
        atributos = { 9,7,2,2 }; // 20 pontos de habilidade para cada classe
        break;
    case 2:
        classe = "Mago";
        atributos = { 4,1,3,12 };

        break;
    case 3:
        classe = "Ladrao";
        atributos = { 5,2,10,3 };

        break;
    case 4:
        classe = "Piromante";
        atributos = { 5,1,5,9 };

        break;
    case 5:
        classe = "Paladino";
        atributos = { 7,6,5,2 };
        break;

    }

    vida = atributos[0] * 100;
    cout << "======"
        << "\nClasse: " + classe << endl;
    classe0 = classe;
    cout << "\n"
        << "Status: \n"
        << "Pontos de vida: " << "[" << vida << "]" << endl
        << "Vida: [" << atributos[0] << "] "
        << "Forca: [" << atributos[1] << "] "
        << "Destreza: [" << atributos[2] << "] "
        << "Inteligencia: [" << atributos[3] << "] "
        << endl << endl;
    atributos0 = atributos;


    cout << "Aperte um botao para comecar" << endl;
    cin.ignore();
    cin.get();

    system("cls");
    cout << "Informacao do jogador: \n"
        << "=====================" << endl
        << "Nome: " << nome << endl
        << "Classe: " << classe << endl
        << "---------------------" << endl;

    cout << "Status do jogador: " << endl
        << "Pontos de vida: " << "[" << vida << "]" << endl
        << "Vida: [" << atributos[0] << "] " << endl
        << "Forca: [" << atributos[1] << "] " << endl
        << "Destreza: [" << atributos[2] << "] " << endl
        << "Inteligencia: [" << atributos[3] << "] "
        << endl
        << "=====================" << endl;

}
void printInfo(Personagens& personagem) {

    cout << "=====================" << endl
        << "Nome: " << personagem.nome << endl
        << "Classe: " << personagem.classe << endl
        << "---------------------" << endl
        << "Status do jogador: " << endl
        << "Pontos de vida: " << "[" << personagem.vida << "]" << endl
        << "Vida: [" << personagem.atributos[0] << "] " << endl
        << "Forca: [" << personagem.atributos[1] << "] " << endl
        << "Destreza: [" << personagem.atributos[2] << "] " << endl
        << "Inteligencia: [" << personagem.atributos[3] << "] "
        << endl
        << "=====================" << endl;
}

void creditos() {
    system("cls");
    cout << "Agradecimentos aos desenvolvedores: \n\n"
        << "Caique Lima de Castro \n"
        << "Raissa Barbosa Dias de Oliveira\n"
        << "Taissa Vitoria Vieira dos Santos\n"
        << "=======================================\n\n"

        << "Para voltar ao menu aperte um botao\n";

    cin.ignore();
    cin.get();
    system("cls");

}

void salvarJogo(const string& nomeArquivo, const Personagens& personagem) {
    ofstream arquivo(nomeArquivo, ios::binary);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo para salvar o jogo!" << endl;
        return;
    }

    // Salva o nome
    size_t tamanhoNome = personagem.nome.size();
    arquivo.write(reinterpret_cast<const char*>(&tamanhoNome), sizeof(tamanhoNome));
    arquivo.write(personagem.nome.data(), tamanhoNome);

    // Salva a classe
    size_t tamanhoClasse = personagem.classe.size();
    arquivo.write(reinterpret_cast<const char*>(&tamanhoClasse), sizeof(tamanhoClasse));
    arquivo.write(personagem.classe.data(), tamanhoClasse);

    // Salva o vetor de atributos
    int tamanhoAtributos = personagem.atributos.size();
    arquivo.write(reinterpret_cast<const char*>(&tamanhoAtributos), sizeof(tamanhoAtributos));
    arquivo.write(reinterpret_cast<const char*>(personagem.atributos.data()), tamanhoAtributos * sizeof(int));

    // Salva a variável de vida
    arquivo.write(reinterpret_cast<const char*>(&personagem.vida), sizeof(personagem.vida));

    arquivo.close();
    
}

void priCenario(Personagens& p1, Personagens& p2, Inimigos& guardiaoDasSombras) {
    cin.ignore();

    cout << "A bordo de seu navio, " << p1.nome << " e seu companheiro " << p2.nome << " navegam em direção a uma ilha misteriosa." << endl
        << "# Chegando à ilha: " << endl << endl
        << "A ilha é tropical, e eles se aventuram por uma floresta densa e cheia de criaturas estranhas." << endl
        << "O ar está abafado e as árvores parecem sussurrar." << endl << endl
        << p2.nome + " encontra marcas nas árvores, indicando o caminho certo." << endl
        << "No entando, algo estranho os espreita - de repente o terreno se torna traicoeiro" << endl << endl
        << "#Enfrentando o Guardião das Sombras" << endl << endl
        << "Voces foram escolhidos para enfrentar o Guardiao das Sombras!" << endl;
    cin.ignore();


    guardiaoDasSombras.nome = "Guardiao das Sombras";
    guardiaoDasSombras.atributos = { 15,6,2,7 };
    guardiaoDasSombras.vida = guardiaoDasSombras.atributos[0] * 50;
}

void secCenario(Personagens& p1, Personagens& p2, Inimigos& Korr) {
    cin.ignore();
    system("cls");
    cout << " Você conseguiu UMA das três chaves!!" << endl
        << p1.nome + " e " + p2.nome << " decidem continuar devastando a densa floresta, encontrando, então, um pequeno vilarejo" << endl;
    cin.ignore();



    cout << "Com a primeira chave em mãos, o grupo partiu em direção a uma cidade portuária, onde se dizia que a segunda chave estava guardada no fundo de um bar subterrâneo. Em uma região de má fama, se encontrava a taverna conhecida como Fangar." << endl << "- Este lugar não me agrada - disse " + p2.nome << " olhando desconfortavelmente para os homens que preenchiam o bar." << endl
        << p2.nome + " com sua magia oculta, utilizou um feitiço de invisibilidade para que ele e " + p1.nome + " pudessem se infiltrar." << endl
        << "Lá, eles encontraram um homem misterioso chamado Korr, o responsável pela guarda da chave." << endl
        << "#Enfretando Korr" << endl
        << "Você foi escolhido para enfrentar o Korr, o detentor da Segunda Chave!\n";
    cin.ignore();

    Korr.nome = "Korr";
    Korr.atributos = { 14,8,2,5 };
    Korr.vida = Korr.atributos[0] * 50;
}

void terCenario(Personagens& p1, Personagens& p2, Inimigos& Arkthor) {
    cin.ignore();
    system("cls");
    cout << " Você conseguiu DUAS das três chaves!" << endl;
    cin.ignore();

    cout << "\nCom duas chaves conquistadas, " + p1.nome + " e " + p2.nome + " partiram para o último local onde a terceira chave estava escondida." << endl
        << "Eles navegaram por águas perigosas até chegar a uma ilha perdida, onde a chave estava guardada em uma antiga tumba." << endl
        << "# Enfrentando o fantasma de Ark'thor:" << endl
        << "O velho fantasma de Ark'thor havia jurado proteger seu tesouro a todo custo." << endl
        << "Por isso, escolha o melhor jogador para derrotar o inimigo final." << endl;
    cin.ignore();

    Arkthor.nome = "Ark'thor";
    Arkthor.atributos = { 18,15,19,15 };
    Arkthor.vida = Arkthor.atributos[0] * 60;
}

void quarCenario(Personagens& p1, Personagens& p2, Inimigos& Arkthor) {
    cin.ignore();
    system("cls");
    cout << " Você conseguiu todas as chaves!!!" << endl;
    cin.ignore();

    cout << "\n\nCom todas as chaves em mãos, " + p1.nome + " abriu o baú. Dentro, não havia apenas ouro e jóias, mas um antigo artefato que concedia poder absoluto sobre o oceano." << endl
        << p1.nome + ", observando o artefato que brilhava sob a luz da lua, disse: - Com isso, podemos navegar para qualquer lugar, fazer o que quisermos." << endl
        << p2.nome + " exclamou: - O que estamos esperando? Vamos desbravar o mundo!" << endl
        << "# Preparando-se para a grande navegação:" << endl
        << "Com o artefato em mãos, " + p1.nome + " e " + p2.nome + " partiram em uma grande aventura em alto mar, prontos para desbravar terras desconhecidas e enfrentar o que viesse pelo caminho." << endl;
    cin.ignore();
}

void combate(Personagens& p1, Personagens& p2, Inimigos inimigo, bool& controle) {

    controle = true;
    Personagens* jogadorAtual = &p1;
    Personagens* jogadorReserva = &p2;

    p1.vida = p1.atributos[0] * 100;
    p2.vida = p2.atributos[0] * 100;

    cout << "Selecione o seu jogador inicial: \n"
        << "1.: " + p1.nome << endl
        << "2.: " + p2.nome << endl;

    int escolha;
    cin >> escolha;
    if (escolha == 2) {
        swap(jogadorAtual, jogadorReserva);
    }

    cout << "Você escolheu: " + jogadorAtual->nome << endl
        << "#Começando a batalha: \n";

    while (inimigo.vida >= 0 && (p1.vida >= 0 || p2.vida >= 0)) {

        cout << "Vida de " + inimigo.nome << ": " << inimigo.vida << endl;
        cout << "Vida de " + jogadorAtual->nome << ": " << jogadorAtual->vida << endl << endl;

        if (jogadorAtual->vida <= 0) {
            cout << jogadorAtual->nome << " foi derrotado!" << endl;

            if (jogadorReserva->vida > 0) {
                cout << jogadorReserva->nome << " entra na batalha!" << endl;
                swap(jogadorAtual, jogadorReserva);
            }
            else {
                cout << "Infelizmente, sem a última chave não será possível abrir o baú e desfrutar do grande e misterioso terouro." << endl;
                controle = false;
                break;
            }
        }
        if (jogadorAtual->classe == "Guerreiro") {
            cout << "Escolha entre as habilidades: \n"
                << "1. Porrada\n"
                << "2. Obliterar\n";
            int escolhahab;
            cin >> escolhahab;
            if (escolhahab == 1) {
                inimigo.vida -= jogadorAtual->atributos[1] * 30; // Dano baseado na força
            }
            else if (escolhahab == 2) {
                jogadorAtual->atributos[1] += 4; // Aumenta força temporariamente
            }
            jogadorAtual->vida -= inimigo.atributos[1] * 25; // Dano do inimigo
        }
        else if (jogadorAtual->classe == "Mago") {
            cout << "Escolha entre as habilidades: \n"
                << "1. Bola de Fogo\n"
                << "2. Barreira Mágica\n";
            int escolhahab;
            cin >> escolhahab;
            if (escolhahab == 1) {
                inimigo.vida -= jogadorAtual->atributos[3] * 40; // Dano baseado na inteligência
            }
            else if (escolhahab == 2) {
                jogadorAtual->vida += jogadorAtual->atributos[0] * 20; // Recupera vida
            }
            jogadorAtual->vida -= inimigo.atributos[1] * 20; // Dano sofrido
        }
        else if (jogadorAtual->classe == "Ladrao") {
            cout << "Escolha entre as habilidades: \n"
                << "1. Golpe Furtivo\n"
                << "2. Esquiva Rápida\n";
            int escolhahab;
            cin >> escolhahab;
            if (escolhahab == 1) {
                inimigo.vida -= jogadorAtual->atributos[2] * 35; // Dano baseado na destreza
                jogadorAtual->vida -= inimigo.atributos[1] * 20;
            }
            else if (escolhahab == 2) {
                jogadorAtual->vida -= inimigo.atributos[0] * 1; // Reduz dano
                inimigo.vida -= inimigo.atributos[2] * 26; // Contra-ataque
            }
        }
        else if (jogadorAtual->classe == "Piromante") {
            cout << "Escolha entre as habilidades: \n"
                << "1. Chamas Devastadoras\n"
                << "2. Escudo de Fogo\n";
            int escolhahab;
            cin >> escolhahab;
            if (escolhahab == 1) {
                inimigo.vida -= jogadorAtual->atributos[3] * 45; // Dano elevado baseado na inteligência
            }
            else if (escolhahab == 2) {
                jogadorAtual->vida += jogadorAtual->atributos[3] * 15; // Recupera vida
            }
            jogadorAtual->vida -= inimigo.atributos[1] * 20; // Dano sofrido
        }
        else if (jogadorAtual->classe == "Paladino") {
            cout << "Escolha entre as habilidades: \n"
                << "1. Golpe da Justiça\n"
                << "2. Repelir\n";
            int escolhahab;
            cin >> escolhahab;
            if (escolhahab == 1) {
                inimigo.vida -= (jogadorAtual->atributos[1] * 25 + jogadorAtual->atributos[2] * 25); // Dano baseado na força e destreza
            }
            else if (escolhahab == 2) {
                jogadorAtual->vida -= jogadorAtual->atributos[2] * 2; // Repele dano e recupera vida
                inimigo.vida -= inimigo.atributos[1] * 20;
                // Sofre dano menor
            }
        }
    }
}

bool carregarJogo(const string& nomeArquivo, Personagens& personagem) {

    ifstream arquivo(nomeArquivo, ios::binary);
    if (!arquivo) {
        cerr << "Arquivo não encontrado ou erro ao abrir para leitura!" << endl;
        return false;
    }

    // Carrega o nome
    size_t tamanhoNome;
    arquivo.read(reinterpret_cast<char*>(&tamanhoNome), sizeof(tamanhoNome));
    personagem.nome.resize(tamanhoNome);
    arquivo.read(&personagem.nome[0], tamanhoNome);

    // Carrega a classe
    size_t tamanhoClasse;
    arquivo.read(reinterpret_cast<char*>(&tamanhoClasse), sizeof(tamanhoClasse));
    personagem.classe.resize(tamanhoClasse);
    arquivo.read(&personagem.classe[0], tamanhoClasse);

    // Carrega o vetor de atributos
    int tamanhoAtributos;
    arquivo.read(reinterpret_cast<char*>(&tamanhoAtributos), sizeof(tamanhoAtributos));
    personagem.atributos.resize(tamanhoAtributos);
    arquivo.read(reinterpret_cast<char*>(personagem.atributos.data()), tamanhoAtributos * sizeof(int));

    // Carrega o int vida
    arquivo.read(reinterpret_cast<char*>(&personagem.vida), sizeof(personagem.vida));

    if (!arquivo) {
        cerr << "Erro ao ler o arquivo ou arquivo corrompido!" << endl;
        return false;
    }

    arquivo.close();
    return true;
}


int main()
{
    setlocale(LC_ALL, "UTF-8");
#ifdef _WIN32
    // No Windows, configura o console para aceitar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    Personagens p1, p2;
    Inimigos inimigo;
    string savejogador1 = "dadosjogador1.bin";
    string savejogador2 = "dadosjogador2.bin";
    int escolha = 0;
    int wcontrol = 0;

    while (wcontrol == 0) {
        cout << "SEJA BEM-VINDO AO RPG:::: AS TRÊS CHAVES MÁGICAS \n"
            << "Escolha uma opcao do Menu:\n"
            << "--------------------------------------\n"
            << "1. Novo Jogo\n"
            << "2. Carregar dados dos últimos vencedores\n"
            << "3. Créditos\n"
            << "4. Sair do Jogo\n"
            << "=======================================\n";

        cin >> escolha;
        cout << "=======================================\n";

        // Condição de novo jogo
        switch (escolha)
        {

        default:
            break;

        case 1:
            wcontrol = 1;
            int escolhaClasse;
            cout << "Crie o personagem principal: \n\n"
                << "Nome: ";
            cin >> p1.nome;
            cout << "----------------------------"
                << "\nEscolha entre as classes:\n1. Guerreiro\n2. Mago\n3. Ladrao\n4. Piromante\n5. Paladino"
                << "\n==========================="
                << endl;
            cin >> escolhaClasse;
            cout << endl;

            funcClasse(escolhaClasse, p1.nome, p1.classe, p1.vida, p1.atributos); //função de escolha de classe

            cout << "Insira o nome do seu companheiro: \n";
            cin >> p2.nome;
            cout << "Insira a classe de " << p2.nome << ":" << endl
                << "\n1. Guerreiro\n2. Mago\n3. Ladrao\n4. Piromante\n5. Paladino\n";


            escolha = 0;

            cin >> escolha;
            switch (escolha)
            {
            default:
                break;

            case 1:
                p2.classe = "Guerreiro";
                p2.atributos = { 9,7,2,2 }; // 20 pontos de habilidade para cada personagem
                break;
            case 2:
                p2.classe = "Mago";
                p2.atributos = { 4,1,3,12 };

                break;
            case 3:
                p2.classe = "Ladrao";
                p2.atributos = { 5,2,10,3 };

                break;
            case 4:
                p2.classe = "Piromante";
                p2.atributos = { 5,1,5,9 };

                break;
            case 5:
                p2.classe = "Paladino";
                p2.atributos = { 7,6,5,2 };
                break;

            }

            p2.vida = p2.atributos[0] * 100;
            system("cls");
            cout << "Informacao de " + p2.nome + ": \n";
            printInfo(p2);
            system("cls");


            bool control;
            priCenario(p1, p2, inimigo);
            combate(p1, p2, inimigo, control);

            if (control == true) {
                secCenario(p1, p2, inimigo);
                combate(p1, p2, inimigo, control);

                if (control == true) {

                    terCenario(p1, p2, inimigo);
                    combate(p1, p2, inimigo, control);
                    if (control == true)
                    {
                        quarCenario(p1, p2, inimigo);
                        salvarJogo(savejogador1, p1);
                        salvarJogo(savejogador2, p2);
                    }

                }
            }

            break;

        case 2:
            wcontrol = 1;

                carregarJogo(savejogador1, p1);
                printInfo(p1);
                cout << endl << endl;
                carregarJogo(savejogador2, p2);
                printInfo(p2);

            
            cout << "\nDados dos personagens carregados\n";
            break;

        case 3:

            creditos();

            break;

        case 4:
            wcontrol = 1;
            cout << "Saindo do jogo\n";

            break;
        }
    }
    return 0;

}
