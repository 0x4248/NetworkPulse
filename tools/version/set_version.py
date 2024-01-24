file = open("Makefile","r").readlines()
version = ""
patch = ""
sublevel = ""
for line in file:
    if line.startswith("VERSION"):
        version = line.split("=")[1].strip()
    if line.startswith("PATCH"):
        patch = line.split("=")[1].strip()
    if line.startswith("SUBLEVEL"):
        sublevel = line.split("=")[1].strip()

print("Current version: " + version + "." + patch + "." + sublevel)