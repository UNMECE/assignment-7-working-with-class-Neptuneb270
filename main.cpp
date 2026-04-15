#include <iostream>
#include <cmath>

using namespace std;

class Electric_Field {
   private:
      double *E; //array of 3 doubles (x,y,z)
   public:
      //constructors and destructor
      Electric_Field() {
         cout << "Init Default Electric Field..." << endl;
         E = (double*)malloc(3*sizeof(double));
         E[0] = 1e5;
         E[1] = 10.9;
         E[2] = 1.7e2;
      }
      Electric_Field(double x, double y, double z) {
         E = (double*)malloc(3*sizeof(double));
         E[0] = x;
         E[1] = y;
         E[2] = z;
      }
      ~Electric_Field() {
         delete E;
      }

      //getters and setters
      double get_value(char axis) {
         switch (axis) {
            case 'x': return E[0];
            case 'y': return E[1];
            case 'z': return E[2];
            default: cout << "No such axis availible"; return -1;
         }
      }

      void set_value(char axis, double value) {
         switch (axis) {
            case 'x': E[0] = value; return;
            case 'y': E[1] = value; return;
            case 'z': E[2] = value; return;
            default: cout << "No such axis availible"; return;
         }
      }

      //functions
      void print() {
         cout << "This one has (" 
               << E[0] << ","
               << E[1] << ","
               << E[2] << ")" << endl;
      }
      double calc_magn() {
         double sum = 0; 
         for (int i = 0; i < 3; i++) {
            sum += E[i] * E[i];
         }
         return sqrt(sum);
      }
            
};

class Magnetic_Field {
   private:
      double *M; //array of 3 doubles (x,y,z)
   public:
   //constructor and destructor
   Magnetic_Field() {
      M = (double*)malloc(3*sizeof(double));
      M[0] = 1e5;
      M[1] = 10.9;
      M[2] = 1.7e2;
   }
   Magnetic_Field(double x, double y, double z) {
      M = (double*)malloc(3*sizeof(double));
      M[0] = x;
      M[1] = y;
      M[2] = z;
   }
   ~Magnetic_Field() {
      delete M;
   }
   //getters and setters
   double get_value(char axis) {
      switch (axis) {
         case 'x': return M[0];
         case 'y': return M[1];
         case 'z': return M[2];
         default: cout << "No such axis availible"; return -1;
      }
   } 
   void  set_value(char axis, double value) {
      switch (axis) {
         case 'x': M[0] = value; return;
         case 'y': M[1] = value; return;
         case 'z': M[2] = value; return;
         default: cout << "No such axis availible"; return;
      }
   }
   //functions
   void print() {
      cout << "This one has ("
            << M[0] << ","
            << M[1] << ","
            << M[2] << ")" << endl;
   }
   
   void calc_unit_vector() {
      double sum = 0;
      for (int i = 0; i < 3; i++) {
         sum += M[i] * M[i];
      }
      double magnitude = sqrt(sum);
      cout << "Unit Vector: (";
      for (int i = 0; i < 3; i++) {
         cout << M[i]/magnitude << ",";
      }
      cout << ")" << endl;
   }
};
   

int main() {
   cout << "Electrical Field Vectors ------------" << endl;
   Electric_Field my_elec1;
   Electric_Field my_elec2{1,2,3};
   my_elec1.print();
   my_elec2.print();
   cout << "Magnitudes" << endl;
   cout << my_elec1.calc_magn() << endl;
   cout << my_elec2.calc_magn() << endl;

   cout << endl;
   
   cout << "Magnetic Field Vectors ---------------" << endl;
   Magnetic_Field my_magn1;
   Magnetic_Field my_magn2{1,2,3};
   my_magn1.print();
   my_magn2.print();
   cout << "Unit Vectors" << endl;
   my_magn1.calc_unit_vector();
   my_magn2.calc_unit_vector();
}
