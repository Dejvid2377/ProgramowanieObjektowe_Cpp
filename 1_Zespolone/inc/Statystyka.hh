#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

class Statystyka {
  public:
   Statystyka() { dobre = 0; zle = 0;}
   Statystyka(double dobre, double zle);
   void prawidlowe () { dobre++; }
   void bledne() { zle++; }
   void rezultat (); 
  private:
    double dobre;
    double zle; 
};

#endif