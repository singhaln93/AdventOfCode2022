# Copyright © 2022  Neeraj Singhal
# All rights reserved

GCC_COMPILER=g++
CLANG_COMPILER=clang++
#CROSS_COMPILER=
OPTIONS=-g -std=c++20 -pedantic -Wall -Wextra -Werror -Wshadow -Wconversion -Wunreachable-code
COMPILE=$(GCC_COMPILER) $(OPTIONS)

PROJECT_NAME=AoC
CMAKE_GENERATOR=Ninja
BUILD=.build
LIBS= lib/*.h 
SRCS=main.cpp

# Compile main by default
all: test_cmake

help:
	@echo Whatever help info you want here, eg
	@echo '  make test_cmake'
	@echo '  make test_meson'
	@echo '  make test_conan'
	@echo '  make cppcheck'
	@echo '  make format'
	@echo '  make documentation'
	@echo '  make clean'
	@echo ''

test_gcc:
	mkdir -p $(BUILD)/bin
	$(GCC_COMPILER) $(OPTIONS) $(SRCS) -o $(BUILD)/bin/$(PROJECT_NAME) \
	&& ./$(BUILD)/bin/$(PROJECT_NAME)

test_clang:
	mkdir -p $(BUILD)/bin
	$(CLANG_COMPILER) $(OPTIONS) $(SRCS) -o $(BUILD)/bin/$(PROJECT_NAME) \
	&& ./$(BUILD)/bin/$(PROJECT_NAME)

test_cmake:
	mkdir -p $(BUILD) && cd $(BUILD) && cmake .. && make -j4 \
	&& ./$(PROJECT_NAME)

#TODO: implement bazel build for the project 
#test_bazel:
#	bazel build //main:hello-world && bazel-bin/main/hello-world

test_meson:
	meson setup $(BUILD) && cd $(BUILD) && meson compile && ./$(PROJECT_NAME)

test_conan:
	mkdir -p $(BUILD) && cd $(BUILD) && conan install .. && cmake .. && make -j4 \
	&& ./$(PROJECT_NAME)

# Static code analysis using clang-tidy, cppcheck..
#TODO: implement clang-tidy support for the project 
#clang-tidy:
#	/usr/bin/clang-tidy --use-color main.cpp

cppcheck:
	./misc/static_check.sh

format:
	/usr/bin/clang-format -i $(SRCS) $(LIBS)

DOXYGEN_RESULTS=docs/Doxygen
documentation:
	doxygen misc/Doxygen/doxyfile.conf && open "${DOXYGEN_RESULTS}/index.html"

#list-submodules:
#	./misc/listSubmodules.sh

CUR_DIR=$(dirname $0)
SRC_DIR=$(CUR_DIR)/.build/
COV_DIR=docs
COVERAGE_RESULTS=${COV_DIR}/gcov-html

#TODO: implement coverage(gcov,lcov) support for the project 
#coverage:
#	mkdir -p ${COVERAGE_RESULTS} && lcov -d "${SRC_DIR}" -c -o "${COV_DIR}/coverage.info" \
#	&& lcov -r "${COV_DIR}/coverage.info" "*.h" "*/tests/*" "*Xcode.app*" "*.moc" "*moc_*.cpp" \
#	"*/test/*" "*/build*/*" "*/c++/*" -o "${COV_DIR}/coverage-filtered.info" \
#	&& genhtml -o "${COVERAGE_RESULTS}" "${COV_DIR}/coverage-filtered.info" -s \
#	&& lcov -d "${COV_DIR}" -z && open "${COVERAGE_RESULTS}/index.html"

clean:
	rm -rf $(BUILD) build build.* build-*

clean-all:
	rm -rf ../Day*/$(BUILD) build build.* build-*

# These rules do not correspond to a specific file
.PHONY: clean clean-all format