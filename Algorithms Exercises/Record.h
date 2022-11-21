#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <unordered_map>

class Record {
public:
    // Constructores.
    Record();
    Record(std::string monthInput, int dayInput, int hourInput, int minInput, int secInput, std::string ipInput, std::string portInput, std::string reasonInput);

    // Setters.
    void setMonth(std::string monthInput);
    void setDay(int dayInput);
    void setTime(int hourInput, int minInput, int secInput);
    void setIp(std::string ipInput);
    void setPort(std::string portInput);
    void setReason(std::string reasonInput);

    // Getters.
    std::string getMonth();
    int getDay();
    std::string getTime();
    std::string getIp();
    std::string getPort();
    std::string getReason();
    std::string getFullIp();
    int getTimeStamp();
private:
    // Variables.
    std::string month; // Formato de 3 letras
    int day;
    int hour;
    int min;
    int sec;
    std::string ip; // Formato ###.##.###.###
    std::string port;
    std::string reason;

    // Arreglo de meses.
    std::string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dic" };
};

// Constructores.
Record::Record() {
    // Valores predeterminados.
    month = "Na";
    day = 0;
    hour = 0;
    min = 0;
    sec = 0;
    ip = "Na";
    port = "Na";
    reason = "Na";
}
Record::Record(std::string monthInput, int dayInput, int hourInput, int minInput, int secInput, std::string ipInput, std::string portInput, std::string reasonInput) {
    // Validar datos ingresados.

    // Validar mes.
    if (monthInput.size() > 3) {
        throw std::invalid_argument("El mes debe de estar en formato de 3 letras.");
    }
    bool matched;
    for (int i = 0; i < 12; i++) {
        if (monthInput == months[i]) {
            matched = true;
            break;
        }
        else {
            matched = false;
        }
    }
    if (!matched) throw std::invalid_argument("Volor incorrecto de mes.");

    // Validar d�a.
    if (dayInput < 1) {
        throw std::invalid_argument("Volor incorrecto para dia.");
    }

    // Validar tiempo.
    if ((hourInput > 24 || minInput > 59 || secInput > 59) || (hourInput < 0 || minInput < 0 || secInput < 0)) {
        throw std::invalid_argument("Volor incorrecto de tiempo");
    }

    // Asignar datos a sus variables corerespondientes.
    month = monthInput;
    day = dayInput;
    hour = hourInput;
    min = minInput;
    sec = secInput;
    ip = ipInput;
    port = portInput;
    reason = reasonInput;
}

// Setters.
void Record::setDay(int dayInput) {
    if (dayInput < 1) {
        throw std::invalid_argument("Volor incorrecto para dia.");
    }
    day = dayInput;
}
void Record::setIp(std::string ipInput) {
    ip = ipInput;
}
void Record::setPort(std::string portInput) {
    port = portInput;
}
void Record::setMonth(std::string monthInput) {
    if (monthInput.size() > 3) {
        throw std::invalid_argument("El mes debe de estar en formato de 3 letras.");
    }
    bool matched;
    for (int i = 0; i < 12; i++) {
        if (monthInput == months[i]) {
            matched = true;
            break;
        }
        else {
            matched = false;
        }
    }
    if (!matched) throw std::invalid_argument("Volor incorrecto de mes.");
    month = monthInput;
}
void Record::setReason(std::string reasonInput) {
    reason = reasonInput;
}
void Record::setTime(int hourInput, int minInput, int secInput) {
    if ((hourInput > 24 || minInput > 59 || secInput > 59) || (hourInput < 0 || minInput < 0 || secInput < 0)) {
        throw std::invalid_argument("Volor incorrecto de tiempo");
    }
    hour = hourInput;
    min = minInput;
    sec = secInput;
}

// Getters.
std::string Record::getMonth() {
    return month;
}
int Record::getDay() {
    return day;
}
std::string Record::getTime() {
    std::string timeString;

    if (hour < 10) {
        timeString = "0" + std::to_string(hour) + ":";
    }
    else {
        timeString = std::to_string(hour) + ":";
    }

    if (min < 10) {
        timeString += "0" + std::to_string(min) + ":";
    }
    else {
        timeString += std::to_string(min) + ":";
    }

    if (sec < 10) {
        timeString += "0" + std::to_string(sec);
    }
    else {
        timeString += std::to_string(sec);
    }

    return timeString;
}
std::string Record::getIp() {
    return ip;
}
std::string Record::getPort() {
    return port;
}
std::string Record::getReason() {
    return reason;
}
std::string Record::getFullIp() {
    return ip + ":" + port;
}
int Record::getTimeStamp() {
    // Óbtiene el tiempo en segundos según el mes, dia y hora.
    // De esta forma es más facil organizarlos de manera ascendente o descendente.
    std::unordered_map<std::string, int> monthValuesInSeconds({ {"Jan", 2629800}, {"Feb", 5259600}, {"Mar", 7889400}, {"Apr", 10519200}, {"May", 13149000}, {"Jun", 15778800}, {"Jul", 18408600}, {"Aug", 21038400}, {"Sep", 23668200}, {"Oct", 26298000}, {"Nov", 28927800}, {"Dic", 31557600} });

    int timestamp = 0;

    // Suma todos los valores de las fechas para obtener el tiempo en segundos (timestamp).
    timestamp += monthValuesInSeconds[month] + (day * 86400) + (hour * 3600) + (min * 60) + sec;

    return timestamp;
}