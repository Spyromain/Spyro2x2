import argparse
import io
import pathlib


class ArgNamespace:
    input_file: io.BufferedReader
    output_folder: pathlib.Path

parser = argparse.ArgumentParser()
parser.add_argument("input_file", type=argparse.FileType("rb"))
parser.add_argument("output_folder", type=pathlib.Path)
args = parser.parse_args(namespace=ArgNamespace())

args.output_folder.mkdir(parents=True, exist_ok=True)

header = []

for i in range(0x100):
    offset = int.from_bytes(args.input_file.read(4), "little")
    if not offset:
        break
    size = int.from_bytes(args.input_file.read(4), "little")
    header.append((offset, size))

for i, (offset, size) in enumerate(header):
    args.input_file.seek(offset, io.SEEK_SET)
    data = args.input_file.read(size)
    with open(args.output_folder / f"WAD_{i:03}.WAD", mode="wb") as output_file:
        output_file.write(data)
