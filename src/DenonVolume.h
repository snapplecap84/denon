#ifndef DENONVOLUME_H
#define DENONVOLUME_H

/*

Denon Volume in half steps from 0 to 98
MV10
MVMAX 98
MV095
MVMAX 98
MV10
MVMAX 98
MV09
MVMAX 98
MV00
MVMAX 98
MV005
MVMAX 98
MV50
MVMAX 98


*/

#include <functional>

typedef std::function<void(void*, float *vol )> VolumeHandler;

class DenonVolume{
  

public:
  void onVolChange(VolumeHandler callbackFunc, void* arg = 0);
  VolumeHandler _VolCallback = NULL;
  void* _VolCallback_arg = NULL;

  DenonVolume()
    : is(10) {}
  DenonVolume(float i) {
    is = i;
  }
  float min = 00;
  float max = 98;
  float is;

  DenonVolume& operator++();
  DenonVolume& operator--();
  DenonVolume& operator++(int);
  DenonVolume& operator--(int);

  DenonVolume& operator=(const float& i);
  DenonVolume& operator=(const int& i);
  DenonVolume& operator=(const double& i);
  
  operator float() {
    return is;
  }
  operator double() {
    return is;
  }
  bool operator>(const int& i) {
    if ((float)i > is) return false;
    return true;
  }
  bool operator<(const int& i) {
    if ((float)i > is) return true;
    return false;
  }
  bool operator>(const float& i) {
    if (i > is) return false;
    return true;
  }
  bool operator<(const float& i) {
    if (i > is) return true;
    return false;
  }
  bool operator>(const double& i) {
    if ((float)i > is) return false;
    return true;
  }
  bool operator<(const double& i) {
    if ((float)i > is) return true;
    return false;
  }

  friend float operator>(const float& i, const DenonVolume& j) {
    if (i > j.is) return true;
    return false;
  }
  friend float operator<(const float& i, const DenonVolume& j) {
    if (i < j.is) return true;
    return false;
  }

  friend double operator>(const double& i, const DenonVolume& j) {
    if ((float)i > j.is) return true;
    return false;
  }
  friend double operator<(const double& i, const DenonVolume& j) {
    if ((float)i < j.is) return true;
    return false;
  }

  friend int operator>(const int& i, const DenonVolume& j) {
    if ((float)i > j.is) return true;
    return false;
  }
  friend int operator<(const int& i, const DenonVolume& j) {
    if ((float)i < j.is) return true;
    return false;
  }

  friend float operator+(const DenonVolume& j, const float& i) {
    return j.is + i;
  }
  friend float operator+(const DenonVolume& j, const int& i) {
    return j.is + i;
  }
  friend float operator+(const DenonVolume& j, const double& i) {
    return j.is + i;
  }
  friend float operator-(const DenonVolume& j, const double& i) {
    return j.is - i;
  }
  friend float operator-(const DenonVolume& j, const float& i) {
    return j.is - i;
  }
  friend float operator-(const DenonVolume& j, const int& i) {
    return j.is - i;
  }
  DenonVolume& operator+(const int& i);
  DenonVolume& operator-(const int& i);
  DenonVolume& operator+(const float& i);
  DenonVolume& operator-(const float& i);
  DenonVolume& operator+(const double& i);
  DenonVolume& operator-(const double& i);

};

#endif