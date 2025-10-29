#pragma once

class
Observer {
public:
  Observer() = default;
  ~Observer() = default;

  virtual void onNotify(int _value) = 0;
};