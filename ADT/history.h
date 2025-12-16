#ifndef STACK_HISTORY_H
#define STACK_HISTORY_H
#include "lagu.h"
#include <iostream>

struct NodeStack {
    PointerLagu laguPtr;
    NodeStack* next;
};

struct HistoryStack {
    NodeStack* top;
};

void CreateHistory(HistoryStack& H);
bool IsHistoryEmpty(HistoryStack H);
void PushHistory(HistoryStack& H, PointerLagu pLagu);
PointerLagu PopHistory(HistoryStack& H);

#endif