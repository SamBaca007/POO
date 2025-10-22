#pragma once

class 
Cafe {
public:
  Cafe() = default;
  virtual ~Cafe() = default;

  virtual void servir() = 0;
};