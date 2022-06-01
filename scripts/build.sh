#!/usr/bin/env bash
mkdir ../build
mkdir ../data
cd ../build
cmake ../src
make -j `nproc`
