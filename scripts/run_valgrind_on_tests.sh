#!/bin/bash
#
# Run `valgrind` on GoogleTest drivers found in the supplied directory.
#
# Assumptions:
# • Test executables are suffixed with 'Test'.
# • Death tests (that reproduce undefined behaviour) are labelled with the
#   substring 'DeathTest', and will be excluded.

if [[ ! $# -eq 1 ]]; then
    echo "usage: $0 TEST_DRIVER_DIR"
    exit -1
fi

TEST_DRIVER_DIR=$1

if [[ ! -d $TEST_DRIVER_DIR ]]; then
    echo "Cannot find test driver directory: $TEST_DRIVER_DIR"
    exit -1
fi

TEST_TARGET_REGEX="*Test"

# Prepend gtest filter with '-' to define a negative pattern, i.e. "*exclude*
# tests matching this regex pattern".
DEATH_TEST_REGEX_TO_EXCLUDE="-*DeathTest*"

EXIT_CODE=0
for testDriver in $( find $1 -name $TEST_TARGET_REGEX ); do
    valgrind --leak-check=full --error-exitcode=1 "$testDriver" --gtest_filter=$DEATH_TEST_REGEX_TO_EXCLUDE
    EXIT_CODE=$(( $EXIT_CODE + $? ))
done

exit $EXIT_CODE