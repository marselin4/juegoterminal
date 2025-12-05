#include <iostream>
#include <limits>
#include <string>
#include <chrono>
#include <random>

//structs
struct Player {
  std::string NAME;
  std::string CLASS;
  int MAXHP;
  int HP;
  int DEF;
  int ATK;
  int WP;
  int ARMR;
  int ACC;
};

struct Player player;

//fuciones
void init(); //inizializa el juego
void seleccionarclase(bool &inclassselection); //seleccion de clase
void menu(); //menu
void aventura(bool &inmenu, bool &inadventure); //seccion de gameplay
void evento(int &random_number); //aca se manejan los eventos.
void pueblo(bool &inmenu, bool &inpueblo);
void pelea();
//void eventoregreso(int &random_number); quizás lo añada;
void estadisticas(bool &inmenu, bool &instats); //seccion de  estadisticas
void limpieza(); //limpia la terminal

int main() {
    init();
    menu();
}

void init() {
    limpieza();
    bool inclassselection = false;
    std::string name;
    std::cout << "\n------------------------\n";
    std::cout << "     Elige tu nombre\n";
    std::cout << "------------------------\n\n";
    std::getline(std::cin, name);

    inclassselection = true;
    seleccionarclase(inclassselection);
    player.NAME = name;
    limpieza();
}

void menu() {
    bool inmenu = true;
    //no se me ocurrio como hacerlo de otra forma
    bool instats = false;
    bool inadventure = false;
    int selection;

    while(inmenu) {
        limpieza();
        std::cout << "\n------------------------\n";
        std::cout << "          Menu\n\n";
        std::cout << "      1 - AVENTURA \n";
        std::cout << "      2 - ESTADISTICAS \n";
        std::cout << "      3 - SALIR \n";
        std::cout << "------------------------\n\n";
        std::cin >> selection;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nEntrada invalida. Intenta de nuevo.\n\n";
        continue;
    }

    switch (selection)
        case 1: {
            limpieza();
            std::cout << "\n------------------------\n";
            std::cout << "  La aventura comienza... \n";
            std::cout << "------------------------\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            inmenu = false;
            inadventure = true;
            aventura(inmenu, inadventure);
            break;
        case 2:
            inmenu = false;
            instats = true;
            limpieza();
            estadisticas(inmenu, instats);
            break;
        case 3:
            inmenu = false;
            limpieza();
            std::cout << "\nBuenas Tardes\n\n";
            break;
        default:
            std::cout << "\nNo es una opción\n\n";
            limpieza();
            break;
        }
    }
}

void aventura(bool &inmenu, bool &inadventure) {
    char selection;
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 6);
    while(inadventure) {
        limpieza();
        int random_number = distribution(generator);
        std::cout << "\n--------------------------------\n";
        std::cout << "En que dirección deseas viajar?\n";
        std::cout << "----------------------------------\n\n";
        std::cout << "w - norte, d - este, a - oeste, s - regresar a casa\n";
        std::cin >> selection;
        selection = tolower(selection);

        switch(selection) {
            case 'w':
                limpieza();
                std::cout << "\n--------------------------------\n";
                std::cout << "      Te diriges al norte...\n";
                std::cout << "----------------------------------\n\n";
                std::cout << "Presiona enter para continuar.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                evento(random_number);
            break;

            case 'd':
                limpieza();
                std::cout << "\n--------------------------------\n";
                std::cout << "      Te diriges al este...\n";
                std::cout << "----------------------------------\n\n";
                std::cout << "Presiona enter para continuar.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                evento(random_number);
            break;

            case 'a':
                limpieza();
                std::cout << "\n--------------------------------\n";
                std::cout << "      Te diriges al oeste...\n";
                std::cout << "----------------------------------\n\n";
                std::cout << "Presiona enter para continuar.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                evento(random_number);
            break;

            case 's':
                limpieza();
                std::cout << "\n--------------------------------\n";
                std::cout << "      Regresas a casa...\n";
                std::cout << "----------------------------------\n\n";
                std::cout << "Presiona enter para continuar.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                inadventure = false;
                inmenu = true;
            break;

            default:
                limpieza();
                std::cout << "\n--------------------------------\n";
                std::cout << "         Opción invalida.\n";
                std::cout << "----------------------------------\n\n";
                std::cout << "Presiona enter para continuar.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                continue;
            break;
        }


    }
}

void evento(int &random_number) {

    if (random_number <= 3) {
        limpieza();
        std::cout << "\n--------------------------------\n";
        std::cout << "        No pasa nada.\n";
        std::cout << "----------------------------------\n\n";
        std::cout << "Presiona enter para continuar.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    if (random_number == 4) {
        limpieza();
        std::cout << "\n--------------------------------\n";
        std::cout << "      Encuentras un pueblo.\n";
        std::cout << "----------------------------------\n\n";
        std::cout << "Presiona enter para continuar.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();


    }

    if (random_number >= 6) {
        limpieza();
        std::cout << "\n--------------------------------\n";
        std::cout << "      Encuentras un enemigo.\n";
        std::cout << "----------------------------------\n\n";
        std::cout << "Presiona enter para continuar.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

}

void estadisticas(bool &inmenu, bool &instats) {
    int totalatk = player.ATK + player.WP;
    int totaldef = player.DEF + player.ARMR;
    int totalhp = player.MAXHP + player.ACC;

    while(instats) {
        std::cout << "\n------------------------\n";
        std::cout << "      Estadisticas\n";
        std::cout << "      NOMBRE: " + player.NAME + "\n";
        std::cout << "      CLASE: " + player.CLASS + "\n";
        std::cout << "      VIDA: " + std::to_string(player.HP) + " | " + std::to_string(totalhp) + "\n";
        std::cout << "      ATAQUE: " + std::to_string(totalatk) + "\n";
        std::cout << "      DEFENSA: " + std::to_string(totaldef) + "\n";
        std::cout << "------------------------\n\n";
        std::cout << "Presiona enter para continuar\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        instats = false;
        inmenu = true;
    }
}

//esta seccion es abominable.
void seleccionarclase(bool &inclassselection) {
    limpieza();
    int selection;
    int selectionclass;
    while(inclassselection) {
        limpieza();
        std::cout << "\n------------------------\n";
        std::cout << "     Elige tu clase\n";
        std::cout << "      1 -  CABALLERO\n";
        std::cout << "      2 -  MAGO\n";
        std::cout << "      3 -  LADRON\n";
        std::cout << "------------------------\n\n";
        std::cin >> selection;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nEntrada invalida. Intenta de nuevo.\n\n";
            continue;
        }

        switch(selection) {
            case 1:
                limpieza();
                std::cout << "\n------------------------\n";
                std::cout << "   Estadisticas del Caballero\n";
                std::cout << "      VIDA: 50\n";
                std::cout << "      ATAQUE: 40\n";
                std::cout << "      DEFENSA: 50\n";
                std::cout << "------------------------\n\n";
                std::cout << "1 - Para aceptar la clase, 2 - Para elegir otra\n";
                std::cin >> selectionclass;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nEntrada invalida. Intenta de nuevo.\n\n";
                continue;
                }
                else if (selectionclass == 1) {
                    std::cout << "\n------------------------\n";
                    std::cout << "Elegiste la clase Caballero";
                    std::cout << "\n------------------------\n";
                    player.CLASS = "Caballero";
                    player.HP = 50;
                    player.MAXHP = 50;
                    player.ATK = 40;
                    player.DEF = 50;
                    player.WP = 0;
                    player.ARMR = 0;
                    player.ACC = 0;
                    inclassselection = false;
                }
                else {
                    limpieza();
                    continue;
                }

                break;
            case 2:
                limpieza();
                std::cout << "\n------------------------\n";
                std::cout << "   Estadisticas del Mago\n";
                std::cout << "      VIDA: 30\n";
                std::cout << "      ATAQUE: 60\n";
                std::cout << "      DEFENSA: 30\n";
                std::cout << "------------------------\n\n";
                std::cout << "1 - Para aceptar la clase, 2 - Para elegir otra\n";
                std::cin >> selectionclass;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nEntrada invalida. Intenta de nuevo.\n\n";
                continue;
                }
                else if (selectionclass == 1) {
                    std::cout << "\n------------------------\n";
                    std::cout << "Elegiste la clase Mago";
                    std::cout << "\n------------------------\n";
                    player.CLASS = "Mago";
                    player.HP = 30;
                    player.MAXHP = 30;
                    player.ATK = 60;
                    player.DEF = 30;
                    player.WP = 0;
                    player.ARMR = 0;
                    player.ACC = 0;
                    inclassselection = false;
                }
                else {
                    limpieza();
                    continue;
                }
                break;
            case 3:
                limpieza();
                std::cout << "\n------------------------\n";
                std::cout << "   Estadisticas del Ladron\n";
                std::cout << "      VIDA: 40\n";
                std::cout << "      ATAQUE: 50\n";
                std::cout << "      DEFENSA: 20\n";
                std::cout << "------------------------\n\n";
                std::cout << "1 - Para aceptar la clase, 2 - Para elegir otra\n";
                std::cin >> selectionclass;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nEntrada invalida. Intenta de nuevo.\n\n";
                continue;
                }
                else if (selectionclass == 1) {
                    std::cout << "\n------------------------\n";
                    std::cout << "Elegiste la clase Ladron";
                    std::cout << "\n------------------------\n";
                    player.CLASS = "Ladron";
                    player.HP = 40;
                    player.MAXHP = 40;
                    player.ATK = 50;
                    player.DEF = 20;
                    player.WP = 0;
                    player.ARMR = 0;
                    player.ACC = 0;
                    inclassselection = false;
                }
                else {
                    limpieza();
                    continue;
                }
                break;

        }
    }
}


void limpieza() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
