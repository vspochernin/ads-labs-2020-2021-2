#include "functions.hpp"

size_t getCharCode(char ch)
{
  int temp = static_cast< int >(ch);
  if (temp >= 0)
  {
    return static_cast< size_t >(temp);
  }
  else
  {
    return static_cast<size_t >(256 + temp);
  }
}

size_t hashByDivision(const std::string& str, size_t size)
{
  unsigned long long k = 0;
  unsigned long long factor = 1;
  for (int i = static_cast< int >(str.size()) - 1; i > 0; i--) // Преобразуем строку в число, умножая каждый символ на соответсвующую степень 4-ки.
  {
    k += getCharCode(str[i]) * factor;
    factor *= 4;
  }
  return k % size; // Берем остаток от деления получившегося числа на размер хеш-таблицы.
}
