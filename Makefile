.PHONY: all docs clean

all: docs
	@rm -rf build/
	@mkdir -p build/linker
	@./scripts/generate_linker_script.py
	@cp -avr include build

docs:
	make -C doc

clean:
	rm -rf build/