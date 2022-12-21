#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <sstream>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "cutbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main(){
  Sculptor *s;
  int nx, ny, nz;
  int x0, x1, y0, y1, z0, z1;
  float r, g, b, a;
  std::vector<FiguraGeometrica*> f;
  std::ifstream fin;
  std::string str;
  
  fin.open("toto.txt");
  
  if(!fin.is_open()){
    cout << "não abriu o arquivo\n";
    std::exit(0);
  }
  
  // processa o arquivo enquanto houver linhas
  // para ler
  while(fin.good()){
    fin >> str;
    if(!fin.good()){
      break;
    }
    if(str.compare("dim")==0){
        // li do arquivo a linha dim 10 10 10
        fin >> nx >> ny >> nz;
        std::cout << nx << "x" << ny << "x" << nz;
        std::cout << std::endl;
        s  = new Sculptor(nx, ny, nz);
    }
      
    else if(str.compare("putbox")==0){
        //  putbox 0 9 0 9 0 9 0 0 1.0 1.0
        fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
        fin >> r >> g >>  b >> a;
        f.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
    } 
      
    else if(str.compare("cutbox")==0){
        fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
        f.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
    } 
    
    else if(str.compare("putsphere") == 0) {
        int xcenter, ycenter, zcenter, radius;
        fin >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
        f.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
    } 
    
    else if (str.compare("cutsphere") == 0) {
        int xcenter, ycenter, zcenter, radius;
        fin >> xcenter >> ycenter >> zcenter >> radius;
        f.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
    } 
    
    else if (str.compare("putellipsoid") == 0) {
        int xcenter, ycenter, zcenter, rx, ry, rz;
        fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
        f.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz,r, g, b, a));
    }
       
    else if (str.compare("cutellipsoid") == 0) {
        int xcenter, ycenter, zcenter, rx, ry, rz;
        fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
        f.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
    }
  }


  for(size_t i=0; i<f.size(); i++){
    std::cout << "draw\n";
    f[i]->draw(*s);
  }
  for(size_t i=0; i<f.size(); i++){
    delete f[i];
  }

  s->writeOFF("testetoto.off");


  return 0;
}
