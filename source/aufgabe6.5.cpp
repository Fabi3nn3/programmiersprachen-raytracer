// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "material.hpp"
#include <map>
#include <sstream>



int main () {
  using namespace std;
  string line;
  ifstream myfile ("../Material.sdf");

  map<string, Material> materials;
  
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}