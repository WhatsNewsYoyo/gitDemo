#include <iostream>
using namespace std;

void CrearAmisatad1() {
    cout << "Escriba el nombre de las 2 personas que quiera crear una amistad\n";
}

void AgregarContenido2() {
    cout << "Escriba el nombre del contenido:\n";
}

void Agregarinteres3() {
    cout << "Añádale algún interés a cualquier usuario:\n";
}

void VerRecomendaciones4() {
    cout << "A continuación las recomendaciones:\n";
}

void AgregarUsuario5() {
    cout << "Escriba el nombre del usuario al que quiera añadir: \n";
}

int main() {
    int opcion;

    do {
        // Mostrar menú
        cout << "===== MENÚ =====\n";
        cout << "1. Crear amistad\n";
        cout << "2. Agregar contenido\n";
        cout << "3. Agregar interés a un usuario\n";
        cout << "4. Ver recomendaciones\n";
        cout << "5. Agregar usuario\n";
        cout << "6. Salir ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                CrearAmisatad1();
                break;
            case 2:
                AgregarContenido2();
                break;
            case 3:
                Agregarinteres3();
            case 4:
                VerRecomendaciones4();
                break;
            case 5:
                AgregarUsuario5();
            case 6:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no valida. Por favor, intenta de nuevo.\n";
        }

        cout << endl; // Separador para mejor visualización
    } while (opcion != 6);

    return 0;
}
