#!/usr/bin/env bash
# Compile every solution and check it against the sample in tests/.
# Usage: bash run_samples.sh        (run from the coding/ folder)
set -e
cd "$(dirname "$0")"
mkdir -p bin
for src in solutions/*.cpp; do
  name=$(basename "$src" .cpp)
  g++ -std=c++17 -O2 -o "bin/$name" "$src"
  if diff -q <("bin/$name" < "tests/$name.in") "tests/$name.ans" > /dev/null; then
    echo "PASS  $name"
  else
    echo "FAIL  $name"
  fi
done
