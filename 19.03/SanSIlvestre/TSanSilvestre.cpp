#include <string>
#include <stdexcept> // Include for std::exception
#include "TSanSilvestre.h"

/** Implementación de las funciones miembros */

TSanSilvestre::TSanSilvestre(std::string pName, std::string pDeport) {
    aName = pName;
    aDeport = pDeport;
    for (int i = 0; i < 5; i++) {
        aRecord[i] = 0.0;
    }
    aBirth.Day = 0;
    aBirth.Mounth = 0;
    aBirth.Year = 0;
}

TSanSilvestre::~TSanSilvestre() {}

TDDate TSanSilvestre::GetBirth() {
    TDDate temporal;
    temporal.Day = aBirth.Day;
    temporal.Mounth = aBirth.Mounth;
    temporal.Year = aBirth.Year;
    return temporal;
}

void TSanSilvestre::SetBirth(TDDate pBirth) {
    if (pBirth.Mounth < 1 || pBirth.Mounth > 12) {
        throw std::invalid_argument("Invalid month value.");
    }
    if (pBirth.Day < 1 || pBirth.Day > 31) {
        throw std::invalid_argument("Invalid day value.");
    }
    aBirth.Day = pBirth.Day;
    aBirth.Mounth = pBirth.Mounth;
    aBirth.Year = pBirth.Year;
}

std::string TSanSilvestre::GetName() {
    return aName;
}

std::string TSanSilvestre::GetDeporte() {
    return aDeport;
}

float TSanSilvestre::GetRecord(int pPos) {
    if (pPos < 0 || pPos >= 5) {
        throw std::out_of_range("Record position out of range.");
    }
    return aRecord[pPos];
}

void TSanSilvestre::SetRecord(int pPos, float pValue) {
    if (pPos < 0 || pPos >= 5) {
        throw std::out_of_range("Record position out of range.");
    }
    aRecord[pPos] = pValue;
}

bool TSanSilvestre::Compare(float pValue) {
    float sum = 0.0;
    int cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aRecord[i] != 0.0) {
            sum += aRecord[i];
            cont++;
        }
    }
    if (cont == 0) {
        throw std::runtime_error("No records available for comparison.");
    }
    float prom = sum / cont;
    return pValue > prom;
}
