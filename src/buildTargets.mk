# All makefile targets

################################################################################
#Allow exectuables to be placed in another directory:
ALLEXES = $(addprefix $(XD)/, \
 periodicTable \
)

DEFAULTEXES = $(addprefix $(XD)/, \
 periodicTable \
)

#Default make rule:
all: checkObj checkXdir $(DEFAULTEXES) doneMessage

################################################################################

# Dependencies for each object target, broken by sub-directories:
include $(SD)/Physics/Physics.mk
# Dependencies for each 'main' object target
include $(SD)/main.mk

################################################################################
# Just to save typing: Many programs depend on these combos:



################################################################################
# Link + build all final programs

$(XD)/periodicTable: $(OD)/periodicTable.o $(OD)/AtomData.o \
$(OD)/NuclearData.o
	$(LINK)

################################################################################
################################################################################

checkObj:
	@if [ ! -d $(OD) ]; then \
	  echo '\n ERROR: Directory: '$(OD)' doesnt exist - please create it!\n'; \
	  false; \
	fi

checkXdir:
	@if [ ! -d $(XD) ]; then \
		echo '\n ERROR: Directory: '$(XD)' doesnt exist - please create it!\n'; \
		false; \
	fi

doneMessage:
		@echo 'done'

.PHONY: clean  checkObj checkXdir
clean:
	rm -f $(ALLEXES) $(OD)/*.o
