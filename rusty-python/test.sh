#!/bin/sh

test() {
    printf "Testing the sieve of Eratosthenes written in %s...\n" "$1"
    python3 -m timeit -s "from $1sieve import sieve" 'sieve(100000)'
    echo ""
}

test python
test c
test rust
