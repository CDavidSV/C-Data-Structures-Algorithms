#pragma once
#include <iostream>
#include <string>

class Ip {
    private:
        long long ipDecimal = 0;
        std::string ip;

        long long convertIpToDecimal(std::string ip) {
            // Factores para convertir cada octeto de la ip a decimal.
            int convertionFactors[4] = {16777216, 65536, 256, 1};  // w * 16777216 + x * 65536 + y * 256 + z * 1
            int counter = 0;
            long long convertedIp = 0;

            std::string x;
            for (char j : ip) {  // Ciclamos por cada caracter de la ip.
                if (j == '.') {
                    convertedIp += std::stoll(x) * convertionFactors[counter];  // Vamos acumulando cada decimal de la ip.
                    counter++;
                    x = "";
                } else {
                    x += j;
                }
            }
            convertedIp += std::stoll(x) * convertionFactors[counter];
            return convertedIp;
        }
    public:
        // Constructores.
        Ip(std::string ipInput) {
            ipDecimal = convertIpToDecimal(ipInput);
            ip = ipInput;
        }
        Ip() {
            ipDecimal = 0;
            ip = "000.000.000:0000";
        }

        // Setters.
        void setIp(std::string ipInput) {
            ipDecimal = convertIpToDecimal(ipInput);
            ip = ipInput;
        }

        // Getters.
        std::string getIp() {
            return ip;
        }

        // Sobrecarga de operadores comparativos.
        bool operator<(Ip ipToCompare) {
            long long ip1 = ipDecimal;
            long long ip2 = ipToCompare.ipDecimal;

            return ip1 < ip2 ? true : false;
        }

        bool operator>(Ip ipToCompare) {
            long long ip1 = ipDecimal;
            long long ip2 = ipToCompare.ipDecimal;

            return ip1 > ip2 ? true : false;
        }

        bool operator==(Ip ipToCompare) {
            long long ip1 = ipDecimal;
            long long ip2 = ipToCompare.ipDecimal;

            return ip1 == ip2 ? true : false;
        }

        bool operator<=(Ip ipToCompare) {
            long long ip1 = ipDecimal;
            long long ip2 = ipToCompare.ipDecimal;

            return ip1 <= ip2 ? true : false;
        }

        bool operator>=(Ip ipToCompare) {
            long long ip1 = ipDecimal;
            long long ip2 = ipToCompare.ipDecimal;

            return ip1 >= ip2 ? true : false;
        }
};