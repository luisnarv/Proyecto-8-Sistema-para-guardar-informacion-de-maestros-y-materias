#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstring>
//  #include <string.h>

using namespace std;

int Menu()
{ // Menu principal
    int opcion;
    cout << endl
         << endl
         << "                  MENÚ       " << endl;
    cout << " 1. Agreagar Maestro" << endl;
    cout << " 2. Buscar cursos por Maestro." << endl;
    cout << " 3. Buscar cursos por Especialidad." << endl;
    cout << " 4. Buscar cursos por tiempo brindado por el usuario." << endl; ///-------------------------------
    cout << " 5. Actualizar datos" << endl;
    cout << " 6. Ver lista de Maestro" << endl;
    cout << " 7. Salir" << endl;
    cout << "         Ingrese su opción: ";
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

int MenuEspecialidades()
{ // Menu para agregar especialdiades
    int opcion;

    cout << endl
         << endl
         << "                   MENÚ       " << endl;
    cout << "Ingrese 1 para agregar un lenguaje de programcion " << endl;
    cout << "Ingrese 2 para elegir una Base de Datos " << endl;
    cout << "Ingrese 3 para elegir un servidor " << endl;
    cout << "Ingrese 4 para continuar con el formulario " << endl
         << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

int MenuUpdate()
{ // Menu para actualizar datos
    int opcion;
    cout << endl
         << endl;
    cout << "Ingrese 1 para actualizar datos personales" << endl;
    cout << "Ingrese 2 para actualizar datos referente a cursos " << endl;
    cout << "Ingrese 3 para salir " << endl
         << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

// Estructura del Maestro.
struct Maestro
{
    // nombre, edad, país,
    char nombre[20], pais[20];
    int edad, contador;
};

// Estructura Especialidad
struct Especialidad
{
    // programación, base de datos y servidores.
    char programación[50], DB[50], servidores[50];
};

// Estructura de Curso.
struct Curso
{
    // maestro, especialidad, y
    string clases[50];
    int cantidad;
};
// Estructura de newFechaa.
struct Fecha
{
    //  newFechaa. newFechaa: día, mes y año.
    // int dia, mes, anio;
    string dia[10], mes[10], anio[10];
};

struct Registro
{
    Maestro newMaestro;
    Especialidad newEspecialidad;
    Curso newCurso;
    Fecha newFecha;
};

void agreagarUsusario(Registro newRegistro[20], int &contador, int Cantidades, int opcion, int usuarios) ///-------------------------------
{
    cout << "      Agregar nuevo Empleado. " << endl;
    cout << "*     Ingrese el numero de empleados que quiere agregar: ";
    cin >> usuarios; 
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << endl
         << endl
         << endl;
    /*contador varaible que guarda el numero de empleados creados se compara con
     usuarios para verificar que el numero de usuarios qu se quieren ingresar no supere el maximo de 20
     */
    if (contador + 1 == 20 || usuarios > 20 || usuarios + contador > 20) 
    // if (userCount + 1 == 20 || usuarios > 20 || usuarios + userCount > 20)
    {
        cout << "<----------------ERROR--------------->" << endl;
        cout << "Solo se pueden ingresar 20 empleados" << endl;
        cout << endl
             << endl
             << "Empleados agregados :" << contador << endl;
    }
    else
    {
        /*Si no supera el maximo se empieza a recorrer con un cilco for para crear a los usuarios  */
        usuarios = usuarios + contador; 

        for (int i = contador; i < usuarios; i++) 
        {
            contador = contador + 1;
            // Limpia Búfer de datos.
          //  fflush(stdin);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "-- Registro " << contador << " --" << endl;
            cout << endl
                 << endl
                 << "* Ingrese Nombre: ";
            // cin.getline(maestro.nombre, 20);
            cin.getline(newRegistro[i].newMaestro.nombre, 20);
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "* Ingrese Pais : ";
            // cin.getline(maestro.pais, 20);
            cin.getline(newRegistro[i].newMaestro.pais, 20);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "* Ingrese edad: ";
            // cin >> maestro.edad;
            cin >> newRegistro[i].newMaestro.edad;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << endl
                 << endl;
            //-------------------------------------------------------------------------------------//----
            // opcion = 0;
            //fflush(stdin);
            cout << "Ingrese especialidad: ";
            /*Aqui se agregara la especilidad del empleado con un clico do while */
            do
            {
                opcion = MenuEspecialidades();
                switch (opcion)
                {
                case 1:
                    cout << endl
                         << endl;
                    cout << "Ingrese lenguaje de Programación: ";
                    //fflush(stdin);
                    cin.getline(newRegistro[i].newEspecialidad.programación, 50);
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    //   cin >> newRegistro[i].newEspecialidad.programación;
                    break;

                case 2:
                    cout << endl
                         << endl;
                    cout << "Ingrese DB: ";
                    //fflush(stdin);
                    // cin.getline(especialidad.DB, 50);
                    cin.getline(newRegistro[i].newEspecialidad.DB, 50);
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;

                case 3:
                    cout << endl
                         << endl;
                    cout << "Ingrese Servidors: ";
                    //fflush(stdin);
                    // cin.getline(especialidad.servidores, 50);
                    cin.getline(newRegistro[i].newEspecialidad.servidores, 50);
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;

                case 4:
                    cout << "/--------------------------------------------------------------/" << endl;
                    break;

                default:
                    cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                    break;
                }
            } while (opcion != 4);

            /*En caso se complete se volvera a mostrar el menu para elegir la opcion deseada*/

            //fflush(stdin);
            // Cantidades = 0;

            /*Se hace uso de otro ciclo do while para crear las clases con la fecha
            si cantidades ya tiene un valor pasa a ingresar el curso directamente sin preguntar la cantidad*/
            do
            {
                if (Cantidades > 0)
                {
                    opcion = 1;
                }
                else
                {
                    cout << endl
                         << endl;
                    cout << "----------- Agregar cursos -----------" << endl;
                    cout << " Inngrese 1 para agregar un nuevo curso" << endl;
                    cout << " Ingrese 2 para continuar con el formulario " << endl;
                    cout << "* Opcion: ";
                    cin >> opcion;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                switch (opcion)
                {
                case 1: // En este caso se ingresa la cantidad de cursos
                    /*se guarda el valor en una varaible y se recorre para crear los cursos deseados
                    con su fecha se guarda la cantidad de cursos creados para luego poder recorrerlos*/
                    if (Cantidades == 0)
                    {
                        cout << endl
                             << "* Ingrese la cantidad de Cursos: ";
                        cin >> Cantidades;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        Cantidades = Cantidades + newRegistro[i].newCurso.cantidad;
                        cout << endl
                             << endl;
                    }

                    for (int j = newRegistro[i].newCurso.cantidad; j < Cantidades; j++)
                    {
                        //fflush(stdin);
                        cout << "* Ingrese Nombre del curso: ";
                        cin >> newRegistro[i].newCurso.clases[j];
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                       // fflush(stdin);
                        cout << "* Ingrese el dia del curso : ";
                        cin >> newRegistro[i].newFecha.dia[j];
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                       // fflush(stdin);
                        cout << "* Ingrese el mes del curso: ";
                        cin >> newRegistro[i].newFecha.mes[j];
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        //fflush(stdin);
                        cout << "* Ingrese el anio del curso: ";
                        cin >> newRegistro[i].newFecha.anio[j];
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << endl;
                    }
                    newRegistro[i].newCurso.cantidad = Cantidades;

                    Cantidades = 0;

                    break;
                case 2:
                    cout << "/--------------------------------------------------------------/" << endl
                         << endl;

                    cout << "                    Usuario creado correctamente" << endl
                         << endl;
                    break;
                default:
                    cout << "      Opción inválida. Por favor, seleccione una opción válida." << endl;
                    break;
                }
            } while (opcion != 2);
        }
    }
}

void busquedaMaestro(Registro newRegistro[20], int &contador, int &bandera, char Search[20])
{
    // int bandera = 0;
    // char Search[20];
    cout << endl
         << endl
         << "      Buscar cursos por maestro." << endl;
    cout << "* Ingresa el nombre del maestro: ";
   // fflush(stdin);
    cin.getline(Search, 20);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /*Se pide el nombre para realizar la busqueda luego se recorre la estructura con un ciclo for  hasta encontrar
    donde coincida  luego muestra los cursos encontrados*/
    for (int i = 0; i < contador; i++)
    {
        strupr(newRegistro[i].newMaestro.nombre);
        strupr(Search);
        if (strcmp(newRegistro[i].newMaestro.nombre, Search) == 0)
        {
            int count = newRegistro[i].newCurso.cantidad;
            cout << endl
                 << "--- Cursos encontrados ---" << endl;
            cout << "Maestro " << newRegistro[i].newMaestro.nombre << "." << endl
                 << endl;
            for (int j = 0; j < count; j++)
            {
                cout << "# Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " ";
                cout << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
                bandera++;
            }
        }
    }
    if (bandera == 0)
    {
        cout << endl
             << "Not found" << endl;
    }
}

void busquedaEspecialidad(Registro newRegistro[20], int &contador, int bandera, int opcion)
{
    //  int bandera = 0, opcion;
    cout << endl
         << endl
         << "       Buscar cursos por especialidad." << endl
         << endl;

    do
    {
        cout << "Ingrese 1 para buscar por especialidad en lenguaje de programacion. " << endl;
        cout << "Ingrese 2 para buscar por especialidad en  Bases de datos. " << endl;
        cout << "Ingrese 3 para buscar por especialidad en  Servidores. " << endl;
        cin >> opcion;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1 || 2 || 3:
            cout << "   ..................LOADING........................." << endl;
            break;
        default:
            cout << "      Opción inválida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    } while (opcion != 1 && opcion != 2 && opcion != 3);

    /*Se compara el valor de opcion guardado anterior mente  para realizar la busqueda en el area
    respectiva.*/
    cout << "Cursos encontrados: " << endl;
    for (int i = 0; i < contador; i++)
    {
        int count = newRegistro[i].newCurso.cantidad;
        if (opcion == 2) // Bases de datos
        {
            if (strlen(newRegistro[i].newEspecialidad.DB) > 0)
            {

                cout << endl
                     << endl
                     << "Maestro " << newRegistro[i].newMaestro.nombre << "." << endl;
                for (int j = 0; j < count; j++)
                {
                    cout << "Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " ";
                    cout << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
                    cout << endl;
                    bandera++;
                }
            }
        }
        else if (opcion == 1) // Lenguajes de programacion
        {

            if (strlen(newRegistro[i].newEspecialidad.programación) > 0)
            {

                cout << "Maestro " << newRegistro[i].newMaestro.nombre << "." << endl;
                for (int j = 0; j < count; j++)
                {

                    cout << "Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " ";
                    cout << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
                    cout << endl
                         << endl;
                    bandera++;
                }
            }
        }
        else if (opcion == 3) // Servidores
        {

            if (strlen(newRegistro[i].newEspecialidad.servidores) > 0)
            {

                cout << "Maestro " << newRegistro[i].newMaestro.nombre << "." << endl;
                for (int j = 0; j < count; j++)
                {

                    cout << "Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " ";
                    cout << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
                    cout << endl
                         << endl;
                    bandera++;
                }
            }
        }
    }

    if (bandera == 0)
    {
        cout << "Not found" << endl;
    }
}

void busquedaFecha(Registro newRegistro[20], int &contador, int bandera, char año[20], int año1, int año2, int opcion)
{

    // int bandera = 0, año1, año2, opcion;
    // char año[20];
    cout << endl
         << endl
         << "  4. Buscar cursos por tiempo brindado por el usuario." << endl;
    cout << "* Ingresa un año: ";
    cin >> año;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Ingresa 1 para ver los cursos mayores al año ingresado. " << endl;
    cout << "Ingresa 2 para ver los cursos menores al año ingresado." << endl;
    cout << " Opcion: ";
    cin >> opcion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion != 1 && opcion != 2)
    {
        cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
    }
    else if (opcion == 1)
    {
        /*Caso de busqueda mayor*/

        for (int i = 0; i < contador; i++)
        {
            int count = newRegistro[i].newCurso.cantidad;
            for (int j = 0; j < count; j++)
            {
                año1 = stoi(newRegistro[i].newFecha.anio[j]);
                año2 = stoi(año);
                if (año1 > año2)
                {
                    bandera++;
                    cout << endl
                         << "Maestro " << newRegistro[i].newMaestro.nombre << "." << endl;
                    cout << "Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " ";
                    cout << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
                }
            }
        }
    }
    else
    {
        /*Caso de busqueda menor*/
        for (int i = 0; i < contador; i++)
        {
            int count = newRegistro[i].newCurso.cantidad;
            for (int j = 0; j < count; j++)
            {
                año1 = stoi(newRegistro[i].newFecha.anio[j]);
                año2 = stoi(año);
                if (año1 < año2)
                {
                    bandera++;
                    cout << "Maestro " << newRegistro[i].newMaestro.nombre << "." << endl
                         << endl;
                    cout << "Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " ";
                    cout << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
                }
            }
        }
    }

    if (bandera == 0)
    {
        cout << "Not found." << endl;
    }
    bandera = 0;
}

void actualizarDatos(Registro newRegistro[20], int &contador, string userName, int password, int password2, char Search[20], int bandera, int opcion, int opcion2)
{

    cout << endl
         << endl
         << "  Actualizar datos" << endl;
    cout << "Ingrese nombre de usuario: ";
    cin >> userName;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Ingrese la contraseña: ";
    cin >> password2;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (password != password2)
    {
        cout << endl
             << "Contraseña incorrecta";
    }
    else
    { /*En caso de ingresar la contraseña correctamente se pedira que ingrese el nombre del usuario al
     que desea actualziar los datos.*/
        cout << endl
             << endl
             << " Bienvenido " << userName << ".";
        cout << endl
             << endl
             << "Ususarios encontrados: " << contador << endl;
        for (int i = 0; i < contador; i++)
        {
            cout << "- Nombre: " << strupr(newRegistro[i].newMaestro.nombre) << endl;
        }

        cout << endl
             << endl
             << "* Ingrese el nombre del usuario que desea actualizar los datos: ";
        cin >> Search;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int i = 0; i < contador; i++)
        {
            if (strcmp(strupr(newRegistro[i].newMaestro.nombre), strupr(Search)) == 0)

            {
                int count = newRegistro[i].newCurso.cantidad;
                bandera++;

                do
                { /*Si se llega a encontrar el nombre del usuario se mostrara un menu para actualizar
                 los datos se maneja con un ciclo do while  caso 1 para datos personales como
                 ejemplo:nombre, edad, pais
                 caso 2 para datos de clases ejemplo: especialidades, cursos, fechas.
                    */
                    opcion = MenuUpdate();
                    switch (opcion)
                    {
                    case 1:
                        cout << "Actualizar datos personales" << endl;
                        cout << "Nombre: " << newRegistro[i].newMaestro.nombre << endl;
                        cout << "pais: " << newRegistro[i].newMaestro.pais << endl;
                        cout << "Edad: " << newRegistro[i].newMaestro.edad << endl;
                        cout << endl
                             << endl
                             << "Ingresa 1 para actualizar el nombre" << endl;
                        cout << "Ingresa 2 para actualizar el pais." << endl;
                        cout << "Ingresa 3 para actualizar la edad." << endl;
                        cout << "Ingresa cualquier otro caracter para continuar." << endl;
                        cout << "Opcion: ";
                        cin >> opcion2;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (opcion2 == 1)
                        {
                            cout << "Actualizar nombre: ";
                            //fflush(stdin);
                            cin.getline(newRegistro[i].newMaestro.nombre, 20);
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        else if (opcion2 == 2)
                        {
                            cout << "Actualizar pais: ";
                            //fflush(stdin);
                            cin.getline(newRegistro[i].newMaestro.pais, 20);
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        else if (opcion2 == 3)
                        {
                            cout << "Actualizar edad: ";
                           // fflush(stdin);
                            cin >> newRegistro[i].newMaestro.edad;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        else
                        {
                            cout << "/--------------------------------------------------/" << endl;
                        }
                        break;

                    case 2:
                        cout << endl
                             << "actualizar datos referente a cursos. " << endl;

                        cout << "Especialidad: " << endl;
                        // Se muestran  las especialidades y cursos que tenga el usuario .
                        if (strlen(newRegistro[i].newEspecialidad.DB) > 0)
                        {
                            cout << "* " << newRegistro[i].newEspecialidad.DB << endl;
                        }
                        if (strlen(newRegistro[i].newEspecialidad.programación) > 0)
                        {
                            cout << "* " << newRegistro[i].newEspecialidad.programación << endl;
                        }
                        if (strlen(newRegistro[i].newEspecialidad.servidores) > 0)
                        {
                            cout << "* " << newRegistro[i].newEspecialidad.servidores << endl;
                        }
                        for (int j = 0; j < count; j++)
                        {
                            cout << "Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " "
                                 << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
                        }

                        /*Se carga un menu con las opciones para actualizar Especialidades, Cursos o Fechas.*/
                        cout << endl
                             << endl
                             << "Ingresa 1 para actualizar Especialidad" << endl;
                        cout << "Ingresa 2 para actualizar cursos." << endl;
                        cout << "Ingresa cualquier otro caracter para continuar." << endl;
                        cout << "Opcion: ";
                        cin >> opcion2;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        if (opcion2 == 1)
                        { // Caso de actualzar Especialidades
                            // Se cargara otro menu para elegir que especialidad actualizar.
                            cout << "actualizar Especialidad: ";

                            cout << endl
                                 << endl
                                 << "Ingresa 1 para actualizar el lenguaje de programacion" << endl;
                            cout << "Ingresa 2 para actualizar el DB." << endl;
                            cout << "Ingresa 3 para actualizar la Servidores." << endl;
                            cout << "Ingresa cualquier otro caracter para continuar." << endl;
                            cout << "Opcion: ";
                            cin >> opcion2;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            if (opcion2 == 1)
                            {
                                cout << "actualizar el lenguaje de programacion: ";
                                //fflush(stdin);
                                // cin >> newRegistro[i].newEspecialidad.programación;
                                cin.getline(newRegistro[i].newEspecialidad.programación, 50);
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                bandera = 7;
                            }
                            else if (opcion2 == 2)
                            {
                                cout << "Actualizar DB: ";
                              //  fflush(stdin);
                                cin.getline(newRegistro[i].newEspecialidad.DB, 50);
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                bandera = 7;
                            }
                            else if (opcion2 == 3)
                            {
                                cout << "Actualizar Servidores: ";
                                //fflush(stdin);
                                cin.getline(newRegistro[i].newEspecialidad.servidores, 50);
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                bandera = 7;
                            }
                            else
                            {
                                cout << "/--------------------------------------------------/" << endl;
                            }
                        }
                        else if (opcion2 == 2)
                        { // Caso de actualzar cursos
                            /*Se cargara otro menu para actulaizar cursos y sus fechas.*/
                            cout << "Actualizar cursos: ";

                            cout << endl
                                 << endl
                                 << "Ingresa 1 para actualizar cursos" << endl;
                            cout << "Ingresa 2 para actualizar fecha de cursos ." << endl;
                            cout << "Ingresa 3 para agregar cursos ." << endl;
                            cout << "Ingresa cualquier otro caracter para continuar." << endl;
                            cout << "Opcion: ";
                            cin >> opcion2;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            //fflush(stdin);
                            if (opcion2 == 1)
                            {
                                cout << "Actualizar cursos: ";
                                cout << "Ingresa el nombre del curso: ";
                                cin >> Search;
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                for (int j = 0; j < count; j++)
                                {
                                    transform(newRegistro[i].newCurso.clases[j].begin(), newRegistro[i].newCurso.clases[j].end(), newRegistro[i].newCurso.clases[j].begin(), ::toupper);

                                    if (newRegistro[i].newCurso.clases[j] == strupr(Search))
                                    {
                                        cout << "Ingrese el nuevo nombre del curso: ";
                                        cin >> newRegistro[i].newCurso.clases[j];
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        bandera = 7;
                                    }
                                    cout << "Registro actualizado. " << endl;
                                    cout << newRegistro[i].newCurso.clases[j] << endl;
                                }
                            }
                            else if (opcion2 == 2)
                            {
                                cout << endl
                                     << "Actualizar fecha de cursos: ";
                                cout << "Ingresa el nombre del curso: ";
                                cin >> Search;
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                for (int j = 0; j < count; j++)
                                {
                                    if (newRegistro[i].newCurso.clases[j] == Search)
                                    {
                                        cout << "Ingrese la nuevo fecha del curso: " << endl;
                                        //fflush(stdin);
                                        cout << "Ingrese el dia del curso: ";
                                        cin >> newRegistro[i].newFecha.dia[j];
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                        //fflush(stdin);
                                        cout << "Ingrese el mes del curso: ";
                                        cin >> newRegistro[i].newFecha.mes[j];
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                        //fflush(stdin);
                                        cout << "Ingrese el anio del curso: ";
                                        cin >> newRegistro[i].newFecha.anio[j];
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        bandera = 7;
                                    }
                                    cout << "Registro actualizado. " << endl;
                                    cout << newRegistro[i].newCurso.clases[j] << endl;
                                }
                            }
                            else if (opcion2 == 3)
                            { // agregar un nuevo curso
                                int add = newRegistro[i].newCurso.cantidad;
                                newRegistro[i].newCurso.cantidad = add + 1;

                               // fflush(stdin);
                                cout << "* Ingrese Nombre del curso: ";
                                cin >> newRegistro[i].newCurso.clases[add];
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                //fflush(stdin);
                                cout << "* Ingrese el dia del curso : ";
                                cin >> newRegistro[i].newFecha.dia[add];
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                               // fflush(stdin);
                                cout << "* Ingrese el mes del curso: ";
                                cin >> newRegistro[i].newFecha.mes[add];
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                //fflush(stdin);
                                cout << "* Ingrese el anio del curso: ";
                                cin >> newRegistro[i].newFecha.anio[add];
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << endl;
                                bandera = 8;
                            }
                            else
                            {
                                cout << "/--------------------------------------------------/" << endl;
                            }
                        }
                        else
                        {
                            cout << "/--------------------------------------------------/" << endl;
                        }

                        if (bandera > 6)
                        {
                            cout << "Datos actualizados...";
                        }
                        else
                        {
                            cout << " Error datos no actulizados....";
                        }

                        break;

                    case 3:
                        cout << "   ...Saliendo del programa..." << endl;
                        // exitLoop = true;
                        break;
                    default:
                        cout << "      Opción inválida. Por favor, seleccione una opción válida." << endl;

                        break;
                    }
                } while (opcion != 3);
            }
        }
        if (bandera = 0)
        {
            cout << endl
                 << "Not found" << endl;
        }
    }
}

void listaEmpleados(Registro newRegistro[20], int &contador)
{

    cout << " * Lista de empleados *" << endl;

    cout << endl
         << endl
         << "Empleados agregados :" << contador << endl;

    for (int i = 0; i < contador; i++)
    {
        strupr(newRegistro[i].newMaestro.nombre);
        strupr(newRegistro[i].newMaestro.pais);
        strupr(newRegistro[i].newMaestro.nombre);
        int count = newRegistro[i].newCurso.cantidad;
        cout << "-- Registro " << i + 1 << " --" << endl;
        cout << endl;
        cout << "Nombres: " << newRegistro[i].newMaestro.nombre << endl;
        cout << "pais: " << newRegistro[i].newMaestro.pais << endl;
        cout << "Edad: " << newRegistro[i].newMaestro.edad << endl;
        cout << "Especialidad: " << endl;
        if (strlen(newRegistro[i].newEspecialidad.DB) > 0)
        {
            cout << "* " << newRegistro[i].newEspecialidad.DB << endl;
        }
        if (strlen(newRegistro[i].newEspecialidad.programación) > 0)
        {
            cout << "* " << newRegistro[i].newEspecialidad.programación << endl;
        }
        if (strlen(newRegistro[i].newEspecialidad.servidores) > 0)
        {
            cout << "* " << newRegistro[i].newEspecialidad.servidores << endl;
        }
        for (int j = 0; j < count; j++)
        {
            cout << "Curso " << j + 1 << " " << newRegistro[i].newCurso.clases[j] << " "
                 << "Fecha del curso: " << newRegistro[i].newFecha.dia[j] << "/" << newRegistro[i].newFecha.mes[j] << "/" << newRegistro[i].newFecha.anio[j] << endl;
            /* code */
        }
        cout << endl
             << endl;
    }
}

int main()
{
    bool exitLoop = false;
    int opcionSeleccionada, bandera = 0, password = 12345, password2, año1, año2, Cantidades = 0, usuarios, opcion, opcion2, contador = 0;
    char Search[20], año[20];
    string userName;

    Registro newRegistro[20];
    do
    {
        opcionSeleccionada = Menu();

        switch (opcionSeleccionada)
        {

        case 1:
            agreagarUsusario(newRegistro, contador, Cantidades, opcion, usuarios);
            break;
        case 2:
            /*Caso 2 busqueda por nombre*/
            busquedaMaestro(newRegistro, contador, bandera, Search);
            break;
        case 3:
            /*Caso 3 busqueda por especialidad se pide al usuario ingresar valores del 1 al 3 para hacer una busqueda
            en el area respectiva se mostrara el menu hasta que se desee salir de el. */
            busquedaEspecialidad(newRegistro, contador, bandera, opcion);
            break;
        case 4:
            /*Caso 4 se buscara de mayor a menor desde la fecha indicada por el usuario.*/
            busquedaFecha(newRegistro, contador, bandera, año, año1, año2, opcion);
            break;
        case 5:
            /*Caso 5 para actualizar datos de usuarios se pedira al usuaro que ingrese un un nombre y la contraseña
            en caso de que la contraseña sea correcta tendra acceso caso contrario se mostrara un mensaje de error.*/
            actualizarDatos(newRegistro, contador, userName, password, password2, Search, bandera, opcion, opcion2);
            break;
            /*En caso 6 se mostrara la lista de empleados. */
        case 6:
            listaEmpleados(newRegistro, contador);
            break;
        case 7:
            cout << "   ...Saliendo del programa..." << endl;
            break;
        default:
            cout << "      Opción inválida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    } while (opcionSeleccionada != 7);
    return 0;
}
