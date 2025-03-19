#include "TArrayInt.h"
#include <iostream>
#include <stdexcept> // Include for std::exception

TArrayInt::TArrayInt(int length) {
    if (length > 0 && length <= Max_Length) {
        Flength = length;
        for (int i = 0; i < Flength; i++) {
            FArray[i] = 0;
        }
    } else {
        Flength = 0;
    }
}

TArrayInt::TArrayInt() {}

TArrayInt::~TArrayInt() {
    // Destructor implementation
}

void TArrayInt::SetArray(int Array[]) {
    if (Array == nullptr) {
        throw std::invalid_argument("Array pointer is null.");
    }
    for (int i = 0; i < Flength; i++) {
        FArray[i] = Array[i];
    }
}

int TArrayInt::GetElement(int index) {
    if (index < 0 || index >= Flength) {
        throw std::out_of_range("Index out of range.");
    }
    return FArray[index];
}

void TArrayInt::SetElement(int index, int valor) {
    if (index < 0 || index >= Flength) {
        throw std::out_of_range("Index out of range.");
    }
    FArray[index] = valor;
}

TArrayInt TArrayInt::GetArray() {
    TArrayInt c(Flength);
    for (int i = 0; i < Flength; i++) {
        c.FArray[i] = FArray[i];
    }
    return c;
}

void TArrayInt::SetLength(int length) {
    if (length < 0 || length > Max_Length) {
        throw std::invalid_argument("Invalid length value.");
    }
    Flength = length;
}

int TArrayInt::GetLength() {
    return Flength;
}

int TArrayInt::Sum() {
    int result = 0;
    for (int i = 0; i < Flength; i++) {
        result += FArray[i];
    }
    return result;
}

float TArrayInt::Average() {
    if (Flength == 0) {
        throw std::runtime_error("Cannot calculate average of an empty array.");
    }
    float result = Sum();
    return result / Flength;
}

int TArrayInt::CountZeros() {
    int result = 0;
    for (int i = 0; i < Flength; i++) {
        if (FArray[i] == 0) {
            ++result;
        }
    }
    return result;
}

bool TArrayInt::IsEmpty() {
    return Flength == 0;
}

bool TArrayInt::IsFull() {
    return Flength == Max_Length;
}

bool TArrayInt::InsertLast(int value) {
    if (IsFull()) {
        return false;
    }
    FArray[Flength] = value;
    Flength++;
    return true;
}
