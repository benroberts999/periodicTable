# periodicTable

Command-line periodic table, with electron configurations and nuclear data

 * Compiled using the Makefile (run _$make_, must habe 'make' installed)
 * Alternatively, compile with command:
_$g++ src/Physics/AtomData.cpp src/Physics/NuclearData.cpp src/periodicTable.cpp -o periodicTable -I./src/_
 * No other dependencies
 * (Optional: to install globally, change the XD [executable directory] to "XD=/bin/" in Makefile, and run make with sudo.)

Gives info regarding particular element, including Z, default A, and electron configuration.
Takes input in one line from command line.

Usage: (examples)
 * _$./periodicTable_           Prints periodic table
 * _$./periodicTable Cs_        Info for Cs with default A
 * _$./periodicTable Cs 137_    Info for Cs-137
 * _$./periodicTable Cs all_    Info for all available Cs isotopes
 * Note: numbers come from online database, and have some errors,
so should be checked if needed.

 Or, enter 'c' to print list of physics constants:
  * _$./periodicTable c_        Prints values for some handy physical constants

Note: ground-state electron configurations are "guessed", and can sometimes be incorrect.

Nuclear radius data mostly comes from:
 * I. Angeli and K. P. Marinova, At. Data Nucl. Data Tables 99, 69 (2013).
https://doi.org/10.1016/j.adt.2011.12.006

Units:
 * r_rms: root-mean-square radius, in fm.
 * c: half-density radius (assuming Fermi nuclear distro)
 * mu: magnetic moment (in nuclear magnetons)
