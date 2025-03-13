#include "Stock.h"

// Конструктор
Stock::Stock() : timeCounter(0) {}

// Добавить коробку
void Stock::Add(int w, int v) {
    boxes.push_back({timeCounter, w, v, timeCounter});
    timeCounter++;
}

// Получить коробку по грузоподъемности
int Stock::GetByW(int min_w) {
    int selectedId = -1;
    int minWeight = INT_MAX;
    int earliestTime = INT_MAX;

    for (const auto& box : boxes) {
        if (box.weight >= min_w && (box.weight < minWeight || (box.weight == minWeight && box.time < earliestTime))) {
            minWeight = box.weight;
            selectedId = box.id;
            earliestTime = box.time;
        }
    }

    if (selectedId != -1) {
        // Удаляем выданную коробку
        boxes.erase(std::remove_if(boxes.begin(), boxes.end(), [selectedId](const Box& box) {
            return box.id == selectedId;
        }), boxes.end());
    }

    return selectedId;
}

// Получить коробку по объему
int Stock::GetByV(int min_v) {
    int selectedId = -1;
    int minVolume = INT_MAX;
    int earliestTime = INT_MAX;

    for (const auto& box : boxes) {
        if (box.volume >= min_v && (box.volume < minVolume || (box.volume == minVolume && box.time < earliestTime))) {
            minVolume = box.volume;
            selectedId = box.id;
            earliestTime = box.time;
        }
    }

    if (selectedId != -1) {
        // Удаляем выданную коробку
        boxes.erase(std::remove_if(boxes.begin(), boxes.end(), [selectedId](const Box& box) {
            return box.id == selectedId;
        }), boxes.end());
    }

    return selectedId;
}