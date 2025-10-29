#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Observer/Observer.h"

class
TemperatureSensor {
public:
  TemperatureSensor() = default;
  ~TemperatureSensor() = default;

  void addObserver(Observer* _observer) {
    observers.push_back(_observer);
  }

  void setTemperature(int _temperature) {
    temperature = _temperature;
    notifyObservers();
  }

  void notifyObservers() {
    for (auto& observer : observers) {
      observer->onNotify(temperature);
    }
  }

private:
  std::vector<Observer*> observers;
  int temperature;
};