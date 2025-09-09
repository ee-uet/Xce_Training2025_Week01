#!/bin/bash
fruits=("apple" "banana" "grapes" "peach")
func() {
	fruits+=("mango")
	echo "${fruits[@]}"
}
func
