// Librerias
#include <vector>
#include <string>
#include <fstream>

// Headers
#include "Record.h"

std::vector<Record> readFile(std::string fileDir) {
    // Crear nuestro vector.
    std::vector<Record> records;

    // leemos el archivo de texto.
    std::ifstream bitacora(fileDir);

    // Leemos el archivo y agregamos los datos a un vector.
    std::string text;
    while (std::getline(bitacora, text)) {
        std::vector<std::string> record;

        std::string word = "";
        for (char i : text) {
            if (i == ' ' || i == ':') {
                record.push_back(word);
                word = "";
            }
            else {
                word += i;
            }
        }
        std::string reason = "";
        for (int i = 7; i < record.size(); i++) {
            reason += record[i] + " ";
        }
        records.push_back(Record(record[0], stoi(record[1]), stoi(record[2]), stoi(record[3]), stoi(record[4]), record[5], record[6], reason));
    }

    // Cerrar el archivo.
    bitacora.close();

    // retornar el vector.
    return records;
}

// Intercambia dos elementos de un vector.
void swap(std::vector<Record>& arr, int index1, int index2) {
    Record aux = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = aux;
}

int partition(std::vector<Record>& arr, int start, int end) {
    // Elegir el pivote.
    int pivotElement = arr[end].getTimeStamp();

    // Elegir el apuntador con el elemento de la izquierda.
    int minPointer = start - 1;

    // Ciclar por todo el vector hasta encontrar un elemento que sea menor al pivote.
    for (int i = start; i < end; i++) {
        if (arr[i].getTimeStamp() <= pivotElement) {
            // Intercambiarlos.
            minPointer++;
            swap(arr, i, minPointer);
        }
    }

    swap(arr, minPointer + 1, end);
    return minPointer + 1;
}
void quickSort(std::vector<Record>& arr, int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

struct rangoBusqueda
{
    std::string mes;
    int dia;
};

void busquedaInput(rangoBusqueda &rangoInicio, rangoBusqueda &rangoFinal) {
    std::cout << "Ingresa el Mes de Inicio" << std::endl;
    std::cin >> rangoInicio.mes;
    std::cout << "Ingresa el Dia de Inicio" << std::endl;
    std::cin >> rangoInicio.dia;
    std::cout << "Ingresa el Mes de Fin" << std::endl;
    std::cin >> rangoFinal.mes;
    std::cout << "Ingresa el Dia de Fin" << std::endl;
    std::cin >> rangoFinal.dia;
}
int busquedaBinariaRango(rangoBusqueda rango,std::vector<Record> recordsVector) {
    std::vector<std::string> meses = {"Ene","Feb","Mar","Abr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    std::unordered_map<std::string, int>mapMeses;

    for (int i = 0; i < 12; i++) {
        mapMeses[meses[i]] = i;
    }
    int left = 0;
    int right = recordsVector.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mapMeses[recordsVector[mid].getMonth()] == mapMeses[rango.mes]) {
            left = mid;
            right = mid;
            while (mapMeses[recordsVector[left - 1].getMonth()] == mapMeses[rango.mes]) {
                left--;
            }
            while (mapMeses[recordsVector[right + 1].getMonth()] == mapMeses[rango.mes] && right + 1 < recordsVector.size() - 1) {
                right++;
            }
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (recordsVector[mid].getDay() == rango.dia) {
                    return mid;
                }
                if (recordsVector[mid].getDay() < rango.dia) {
                    left = mid + 1; 
                }
                else {
                    right = mid - 1; 
                }
            }
            return -1;
        }
        if (mapMeses[recordsVector[mid].getMonth()] < mapMeses[rango.mes]) {
          
            left = mid - 1;
        }
        else {
            right = mid - 1; 
        }
    }
    return -2;
}

int main() {
    rangoBusqueda rangoInicio, rangoFinal;
    int indiceInicio, indiceFinal;
    // Leer el archivo y agregarlo a un vector de tipo Record.
    std::vector<Record> recordsVector = readFile("bitacora.txt");

    // Ordenar el vector.
    quickSort(recordsVector, 0, recordsVector.size() - 1);

    //Datos de ingreso del usuario (String MesInicio, int DiaInicio, String MesFinal, int DiaFinal)
    busquedaInput(rangoInicio,rangoFinal);
    std::cout << rangoInicio.dia << rangoInicio.mes << rangoFinal.dia << rangoFinal.mes << std::endl;
    indiceInicio = busquedaBinariaRango(rangoInicio, recordsVector);
    indiceFinal = busquedaBinariaRango(rangoFinal, recordsVector);

    std::cout << indiceInicio << indiceFinal << std::endl; 

    std::ofstream outfile("fechas.txt");

    // Desplegar ids (Prueba).
    for (int i = indiceInicio; i < indiceFinal; i++) {
        std::cout << recordsVector[i].getMonth() << " " << recordsVector[i].getDay() << " " << recordsVector[i].getTime() << std::endl;
        
        outfile << recordsVector[i].getMonth() << " " << recordsVector[i].getDay() << " " << recordsVector[i].getTime() << " " << recordsVector[i].getFullIp() << " " << recordsVector[i].getReason() << std::endl;

    }
    outfile.close();
    return 0;
}