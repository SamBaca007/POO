#pragma once
#include "ProgrammingPatterns/Builder/Builder.h"

class 
Director {
public:
  Director(Builder* _builder) : builder(_builder) {}
  ~Director() = default;

  void construct() {
    if (builder) {
      builder->buildParteA();
      builder->buildParteB();
    }
  }

private:
  Builder* builder;
};