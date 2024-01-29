#!/bin/bash

ARG=("1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1")
for str in "${ARG[@]}"; do
	./push_swap $str | (wc -l)
	./push_swap $str | ./checker_linux $str
done