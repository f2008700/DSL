import sys
from os import walk

mypath=sys.argv[1]
f = []
for (dirpath, dirnames, filenames) in walk(mypath):
        f.extend(filenames)

for file_name in f:
    print file_name
