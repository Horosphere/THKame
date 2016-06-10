# Author: Horosphere
# Execute this script each time you add a new source file in src/ to
# update CMakeLists.txt

import os, sys

os.chdir(os.path.dirname(os.path.realpath(__file__)));
fileName = "CMakeLists.txt"
signature_begin = "# Auto-generated. Do not edit. All changes will be undone\n"
signature_end = "# Auto-generated end\n"
autoGen_begin = "set(SOURCE_FILES\n"
autoGen_padding = "    ${PROJECT_SOURCE_DIR}"
autoGen_end = "   )\n"


cMakeFile = [] # Lines of CMakeLists.txt
iBegin = -1 # Indices corresponding to auto-generated sections
iEnd = -1
with open(fileName, "r") as file:
    index = 0
    for line in file:
        cMakeFile.append(line)
        if line == signature_begin:
            iBegin = index
        elif line == signature_end:
            iEnd = index
        index += 1

if iBegin == -1 or iEnd == -1 or iBegin > iEnd:
    print("No auto-generated region found in " + fileName + ".")
    print("Please check that the following lines exist:")
    print(signature_begin[:-1])
    print(signature_end[:-1])
    sys.exit(1)

del cMakeFile[iBegin + 1: iEnd]

autoGen = autoGen_begin
# Scan src/ directory recursively to gather source files
for root, subdirs, files in os.walk("./src"): # The root string has length 5
    for name in files:
        f = str(os.path.join(root, name))[5:]
        if not f.endswith(('.cpp', '.c')): continue
        print(f)
        autoGen += autoGen_padding + f + "\n"

autoGen += autoGen_end
cMakeFile.insert(iBegin + 1, autoGen)

with open(fileName, "w") as file:
    for line in cMakeFile:
        file.write(line)


