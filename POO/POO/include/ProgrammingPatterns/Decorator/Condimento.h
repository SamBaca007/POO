#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/Decorator/Cafe.h"

class
Condimento : public Cafe {
public:
  Condimento(Cafe* _cafe) : cafe(_cafe) {}
  virtual ~Condimento() override = default;

  virtual void decorar() = 0;

protected:
  Cafe* cafe;
};