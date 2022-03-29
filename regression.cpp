#include "regression.hpp"


int Regression::size() const{
  return N_;
}

void Regression::add(double x, double y){
    ++N_;
         sum_x_ += x;
         sum_y_ += y;
         sum_x2_ += x*x;
         sum_xy_ += x*y;
}

Result Regression::fit() const{
  if (N_ < 2) {
        throw std::runtime_error {"non abbiamo abbastanza punti"};
         }
         
        double const den{N_*sum_x2_ - sum_x_ * sum_x_};
        if (den == 0.){
            throw std::runtime_error{"errore:denominatore nullo"};
        }
        double const a = (sum_y_ * sum_x2_ - sum_x_ * sum_xy_)/ den;
        double const b = (N_ * sum_xy_ - sum_x_ * sum_y_)/den;
        return {a,b};
}


auto fit(Regression const &reg) {
  return reg.fit();
}