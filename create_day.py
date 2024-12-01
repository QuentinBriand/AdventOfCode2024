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
import os
import sys
languages = ["C", "C++", "Python", "Rust"]

def create_day_folder(day_number, person):
	day_folder = f"Day{day_number:02d}"
	if not os.path.exists(day_folder):
		os.makedirs(day_folder)
	for language in languages:
		if not os.path.exists(os.path.join(day_folder, language)):
			os.makedirs(os.path.join(day_folder, language))
		if not os.path.exists(os.path.join(day_folder, language, person)):
			os.makedirs(os.path.join(day_folder, language, person))
	print(f"Created {day_folder} with subfolders for each language.")


if __name__ == "__main__":
	if len(sys.argv) != 3:
		print("Usage: create_day.py <day_number> <person>")
		sys.exit(1)

	try:
		day_number = int(sys.argv[1])
		create_day_folder(day_number, sys.argv[2])
	except ValueError:
		print("Day number must be an integer.")
		sys.exit(1)
