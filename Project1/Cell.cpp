#include "Cell.h"

Cell::Cell() : value(0), isMerged(false) {}

void Cell::setValue(int val) {
    value = val;
}

void Cell::setEmpty() {
    value = 0;
}

void Cell::setMergedCell() {
    isMerged = true;
}

void Cell::resetMerged() {
    isMerged = false;
}

int Cell::getValue() {
    return value;
}

bool Cell::isEmptyCell() {
    return value == 0;
}

bool Cell::isMergedCell() {
    return isMerged;
}
