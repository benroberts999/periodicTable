# Dependencies for Physics

$(OD)/AtomData.o: $(SD)/Physics/AtomData.cpp $(SD)/Physics/AtomData.hpp \
$(SD)/Physics/AtomData_PeriodicTable.hpp
	$(COMP)

$(OD)/NuclearData.o: $(SD)/Physics/NuclearData.cpp \
$(SD)/Physics/NuclearData.hpp
	$(COMP)
