#pragma once
#include "AtomInfo.hpp"
#include "Nuclear_DataTable.hpp"
#include <cmath>
#include <string>
#include <vector>

namespace Nuclear {

enum class Type { Fermi, spherical, zero };

//******************************************************************************
inline Isotope findIsotopeData(int z, int a) {
  for (const auto &nucleus : NuclearDataTable) {
    if (nucleus.Z == z && nucleus.A == a)
      return nucleus;
  }
  return Isotope{z, a, -1, 0, 0, -1};
}

inline std::vector<Isotope> findIsotopeList(int z) {
  std::vector<Isotope> isotopes;
  for (const auto &nucleus : NuclearDataTable) {
    if (nucleus.Z == z)
      isotopes.push_back(nucleus);
  }
  return isotopes;
}

inline double find_rrms(int z, int a) {
  auto nuc = findIsotopeData(z, a);
  if (!nuc.r_ok())
    return 0;
  return nuc.r_rms;
}

inline double find_mu(int z, int a) {
  auto nuc = findIsotopeData(z, a);
  if (!nuc.mu_ok())
    return 0;
  return nuc.mu;
}

inline int find_parity(int z, int a) {
  auto nuc = findIsotopeData(z, a);
  if (!nuc.parity_ok())
    return 0;
  return nuc.parity;
}

inline double find_spin(int z, int a) {
  auto nuc = findIsotopeData(z, a);
  if (!nuc.I_ok())
    return -1.0;
  return nuc.I_N;
}

//******************************************************************************
inline double approximate_r_rms(int A)
// Returns approximate root-mean-square charge radius in fm [1.e-15 m]
// https://www.sciencedirect.com/science/article/pii/S0092640X12000265
// https://www-nds.iaea.org/radii/
// Few light elements (H, He, Li) are hard-coded for common A
// Also: Cs-133 is hard-coded.
{
  double rN;
  if (A == 1)
    rN = 0.8791; // 1-H
  else if (A == 4)
    rN = 1.6757; // 4-He
  else if (A == 7)
    rN = 2.4312; // 7-Li
  else if (A < 10)
    rN = 1.15 * std::pow(A, 0.333);
  else
    rN = 0.836 * std::pow(A, 0.333) + 0.570;

  return rN;
}

//******************************************************************************
inline double c_hdr_formula_rrms_t(double rrms, double t = 2.3)
// Calculates half-density radius, given rms charge radius, and t.
// Formula from Ginges, Volotka, Fritzsche, Phys. Rev. A 96, 1 (2017).
// 4 ln(3) = 4.39445, pi^2 = 9.8696
{
  double a = t / 4.39445;
  if (rrms < t) {
    // this is little dodgy? but formula prob only works large A
    return std::sqrt((5. / 3) * rrms * rrms);
  }
  return std::sqrt((5. / 3) * rrms * rrms - (7. / 3) * (9.8696 * a * a));
}

//******************************************************************************
inline double rrms_formula_c_t(double c, double t = 2.3)
// Calculates  rms charge radius, given half-density radius (c), and t.
// Formula from Ginges, Volotka, Fritzsche, Phys. Rev. A 96, 1 (2017).
// 4 ln(3) = 4.39445, pi^2 = 9.87
{
  double a = t / 4.39445;
  return std::sqrt(0.2 * (3. * c * c + 7. * a * a * 9.8696));
}

const double default_t = 2.30;
//******************************************************************************
inline double approximate_t_skin(int)
// skin-thickness. Always same?
{
  return default_t;
}

} // namespace Nuclear
