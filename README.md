# periodicTable

Command-line periodic table, with electron configurations and nuclear data

 * Requires c++11 or higher
 * All program compiled using the Makefile (run _$make_)
 * No other dependencies


Gives info regarding particular element, including Z, default A, and electron configuration. Takes input in one line from command line.


Usage: (examples)
 * _$./periodicTable_           =>  Prints periodic table
 * _$./periodicTable Cs_        =>  Info for Cs with default A
 * _$./periodicTable Cs 137_    =>  Info for Cs-137
 * _$./periodicTable Cs all_    =>  Info for all available Cs isotopes
 * Note: numbers come from online database, and have some errors, so should be checked if needed.


Note: ground-state electron configurations are "guessed", and can sometimes be incorrect.


Nuclear radius data mostly comes from:
 * I. Angeli and K. P. Marinova, At. Data Nucl. Data Tables 99, 69 (2013). https://doi.org/10.1016/j.adt.2011.12.006


Units:
 * r_rms: root-mean-square radius, in fm.
 * c: half-density radius (assuming Fermi nuclear distro)
 * mu: magnetic moment (in nuclear magnetons)
