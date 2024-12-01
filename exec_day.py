#!/usr/bin/python3
#
# Copyright (c) 2024 - Kleo
# Authors:
# - Antoine FRANKEL <antoine.frankel@epitech.eu>
# NOTICE: All information contained herein is, and remains
# the property of Kleo © and its suppliers, if any.
# Dissemination of this information or reproduction of this material
# is strictly forbidden unless prior written permission is obtained
# from Kleo ©.
#


import sys
import os
import argparse

languages = ["C", "C++", "Python", "Rust"]

def compile_and_run(day_nb, language, name):
	directory = f"Day{day_nb:02d}/{language}/{name}"
	if not os.path.exists(directory):
		print(f"Error: Directory {directory} does not exist.")
		return

	if language == "C":
		os.system(f"gcc {directory}/*.c -I ./CLibrary -lm -lmy -L./CLibrary -o {directory}/program && {directory}/program")
	elif language == "C++":
		os.system(f"g++ {directory}/*.cpp -I ./C++Library -o {directory}/program && {directory}/program")
	elif language == "Python":
		os.system(f"python3 {directory}/*.py")
	elif language == "Rust":
		os.system(f"rustc {directory}/*.rs && ./main")

	else:
		print(f"Error: Unsupported language {language}")

if __name__ == "__main__":
	parser = argparse.ArgumentParser(description="Compile and run Advent of Code solutions.")
	parser.add_argument("-d", "--day", type=int, required=True, help="Day number")
	parser.add_argument("-l", "--language", type=str, required=True, choices=languages, help="Programming language")
	parser.add_argument("-n", "--name", type=str, required=True, help="Solution name")

	args = parser.parse_args()

	day_nb = args.day
	language = args.language
	name = args.name

	compile_and_run(day_nb, language, name)
