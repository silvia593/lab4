#include "regression.hpp"


int Regression::size() const{
  return points_.size();
}

void Regression::add(double x, double y){
    return points_.push_back({x,y});
}

Result Regression::fit() const{
  int N = points_.size();
  double sum_x{};
  double sum_y{};
  double sum_xy{};
  double sum_x2{};

  for (Point const& p : points_){
    sum_x += p.x;
    sum_y += p.y;
    sum_xy += p.x * p.y;
    sum_x2 += p.x * p.x;
  }

  if (N < 2) {
        throw std::runtime_error {"non abbiamo abbastanza punti"};
         }
         
        double const den{N*sum_x2 - sum_x * sum_x};
        if (den == 0.){
            throw std::runtime_error{"errore:denominatore nullo"};
        }
        double const a = (sum_y * sum_x2 - sum_x * sum_xy)/ den;
        double const b = (N * sum_xy - sum_x * sum_y)/den;
        return {a,b};
}


auto fit(Regression const &reg) {
  return reg.fit();
}