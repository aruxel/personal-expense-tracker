#!/bin/sh
# test_menu.sh - checks menu navigation. Run from the project root after `make`:
#   sh tests/test_menu.sh

fail=0

check() {
    name=$1
    expected=$2
    actual=$3
    if [ "$expected" = "$actual" ]; then
        echo "PASS: $name"
    else
        echo "FAIL: $name (expected $expected, got $actual)"
        fail=1
    fi
}

bad='-1\n\nabc\n5abc\n1.5\n1 2\n99999999999999999999\n4294967297\n8\n0\n'

check "valid selections 1, 5, 2" 3 \
    "$(printf -- '1\n5\n2\n0\n' | ./expense_tracker | grep -c 'not available')"

check "every option 1-7 has a placeholder" 7 \
    "$(printf -- '1\n2\n3\n4\n5\n6\n7\n0\n' | ./expense_tracker | grep -c 'not available')"

check "bad inputs are rejected" 9 \
    "$(printf -- "$bad" | ./expense_tracker | grep -c 'Invalid')"

check "bad inputs run no option" 0 \
    "$(printf -- "$bad" | ./expense_tracker | grep -c 'not available')"

check "over-long line gives one error" 1 \
    "$({ head -c 100 /dev/zero | tr '\0' 'a'; printf -- '\n0\n'; } | ./expense_tracker | grep -c 'Invalid')"

check "last line without newline works" 1 \
    "$(printf -- '1' | ./expense_tracker | grep -c 'not available')"

check "end of input exits" 1 \
    "$(./expense_tracker < /dev/null | grep -c 'Goodbye')"

printf -- '0\n' | ./expense_tracker > /dev/null
check "exit status is 0" 0 "$?"

if [ "$fail" -eq 0 ]; then
    echo "All tests passed."
fi
exit "$fail"