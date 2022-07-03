"""Mission Maker Framework Python Build Script

Author: Edward McKnight (EM-Creations.co.uk)
Requires: Python 3.8

This script provides a more friendly interface to interact with the hemtt build
tool for this ArmA 3 addon.

At the moment this tool only supports building in a Windows OS and requires that
the hemtt.exe file is located in the project's root directory.
"""

import argparse, subprocess
from pathlib import Path

arg_parser = argparse.ArgumentParser(description="Mission Maker Framework Python Build Script")
arg_parser.add_argument("-v", "--verbose", help="Verbose output", action="store_true")
arg_parser.add_argument("-s", "--silent", help="Silent / faster run", action="store_true")
args = arg_parser.parse_args()

version_file_location = "..\VERSION"
hemtt_file_location = "..\hemtt.exe"

hemtt_build_command = [hemtt_file_location, "build", "--release"]
hemtt_clean_force_command = [hemtt_file_location, "clean", "--force"]

error_release_already_exists = "Release already exists"
output_cleaned = "all releases"

def run_hemtt_build_command():
    process = subprocess.Popen(hemtt_build_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    allOutput = ""
    allErrors = ""

    while True:
        output = process.stdout.readline()
        errors = process.stderr.readline()
        if process.poll() is not None and output == b'':
            break
        if not args.silent:
            if output:
                output = output.decode("utf-8").strip()
                allOutput = allOutput + output
                print(output)
            if errors:
                errors = errors.decode("utf-8").strip()
                allErrors = allErrors + errors
                print(errors)

    return (allOutput, allErrors)

if not args.silent:
    print("""
    _  _ _  _ ____ _ _ _    ___  _  _ _ _    ___     ____ ____ ____ _ ___  ___
    |\/| |\/| |___ | | |    |__] |  | | |    |  \    [__  |    |__/ | |__]  |
    |  | |  | |    |_|_|    |__] |__| | |___ |__/    ___] |___ |  \ | |     |

    """);

if not args.silent:
    if args.verbose:
        print("Fetching version from '" + version_file_location + "'..")

    if Path(version_file_location).is_file():
        with open(version_file_location, 'r') as file:
            versionData = file.read().rstrip()

        print("Version: " + versionData)

if args.verbose:
    print("Checking hemtt exe exists at '" + hemtt_file_location + "'..")

if not Path(hemtt_file_location).is_file():
    print("Hemtt exe not found, exiting..")
    exit()

hemtt_build_output = run_hemtt_build_command()

if error_release_already_exists in hemtt_build_output[1]:
    if args.verbose:
        print("Failed the initial build, cleaning and trying again..")

    hemtt_build_output = subprocess.run(hemtt_clean_force_command, capture_output=True, text=True)

    if output_cleaned in hemtt_build_output.stdout:
        if args.verbose:
            print("Clean succeeded, trying to build again..")

        run_hemtt_build_command()
