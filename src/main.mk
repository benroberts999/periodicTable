# Dependencies for each 'Main'

$(OD)/periodicTable.o: $(SD)/periodicTable.cpp \
$(SD)/Physics/NuclearData.hpp $(SD)/Physics/AtomData.hpp \
$(SD)/Physics/AtomData_PeriodicTable.hpp $(SD)/Physics/PhysConst_constants.hpp
	$(COMP)
