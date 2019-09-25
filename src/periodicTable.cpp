#include "AtomInfo.hpp"
#include "Nuclear.hpp"
#include <iostream>

void instructions() {
  std::cout
      << "Usage:\n"
         "$./periodicTable            Prints periodic table\n"
         "$./periodicTable Cs         Info for Cs with default A\n"
         "$./periodicTable Cs 137     Info for Cs-137\n"
         "$./periodicTable Cs all     Info for all available Cs isotopes\n"
         "(Note: numbers come from online database, and should be checked)\n";
}

void printData(const Nuclear::Isotope &nuc) {

  std::cout << AtomInfo::atomicSymbol(nuc.Z) << "-" << nuc.A << " (Z=" << nuc.Z
            << ", A=" << nuc.A << ")\n";

  std::cout << "r_rms = ";
  nuc.r_ok() ? std::cout << nuc.r_rms : std::cout << "??";
  std::cout << ", c = ";
  nuc.r_ok() ? std::cout << Nuclear::c_hdr_formula_rrms_t(nuc.r_rms)
             : std::cout << "??";
  std::cout << ", mu = ";
  nuc.mu_ok() ? std::cout << nuc.mu : std::cout << "??";

  std::cout << ", I = ";
  nuc.I_ok() ? std::cout << nuc.I_N : std::cout << "??";
  std::cout << ", parity = ";
  nuc.parity_ok() ? std::cout << nuc.parity : std::cout << "??";
  std::cout << "\n";
}

int parse_A(const std::string &A_str, int z = 0) {
  int a = 0;
  try {
    a = std::stoi(A_str);
  } catch (...) {
    std::cout << "Invalid A: " << A_str << "\n";
    instructions();
    std::abort();
  }

  if (a <= 0)
    a = AtomInfo::defaultA(z);
  return a;
}

//******************************************************************************
int main(int num_in, char *argv[]) {

  if (num_in <= 1) {
    instructions();
    AtomInfo::printTable();
    return 1;
  }

  std::string z_str = argv[1];
  const auto z = AtomInfo::get_z(z_str);
  if (z == 0) {
    instructions();
    return 1;
  }
  z_str = AtomInfo::atomicSymbol(z);
  std::string a_str = (num_in > 2) ? argv[2] : "0";

  std::vector<Nuclear::Isotope> isotopes;
  int a_default = parse_A("0", z);
  if (a_str == "all" || a_str == "list") {
    isotopes = Nuclear::findIsotopeList(z);
  } else {
    int a = parse_A(a_str, z);
    isotopes.push_back(Nuclear::findIsotopeData(z, a));
  }

  std::cout << "\n"
            << z_str << ".   Z = " << z << ";  A = " << a_default
            << " (default)\n\n";
  std::cout << "Electron config: " << AtomInfo::guessCoreConfigStr(z)
            << "   (guess)\n";

  std::cout << "\nIsotpe data:";
  if (isotopes.size() == 0)
    std::cout << " none known\n";
  for (const auto &nuc : isotopes) {
    std::cout << "\n";
    printData(nuc);
  }
}
