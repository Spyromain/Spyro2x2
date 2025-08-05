import argparse
import pathlib
import shutil


class ArgNamespace:
    file: pathlib.Path
    force: bool
    recursive: bool

parser = argparse.ArgumentParser()
parser.add_argument("file", type=pathlib.Path)
parser.add_argument("-f", "--force", action="store_true")
parser.add_argument("-r", "--recursive", action="store_true")
args = parser.parse_args(namespace=ArgNamespace())

if not args.recursive:
    args.file.unlink(missing_ok=args.force)
else:
    shutil.rmtree(args.file, ignore_errors=args.force)
