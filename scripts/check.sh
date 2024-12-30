#!/bin/sh

find . -name '*.c' -or -name '*.h' -type f | xargs cppcheck --check-level=exhaustive
