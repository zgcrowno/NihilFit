# GNU Make solution makefile autogenerated by Premake
# Type "make help" for usage help

ifndef config
  config=debug64
endif
export config

PROJECTS := NihilFit

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

NihilFit: 
	@echo "==== Building NihilFit ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f NihilFit.make

clean:
	@${MAKE} --no-print-directory -C . -f NihilFit.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug64"
	@echo "   profile64"
	@echo "   release64"
	@echo "   debug32"
	@echo "   profile32"
	@echo "   release32"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   NihilFit"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
