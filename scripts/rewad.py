import argparse
import pathlib
import shutil


class ArgNamespace:
    input_files: list[pathlib.Path]
    output_file: pathlib.Path

parser = argparse.ArgumentParser()
parser.add_argument("input_files", nargs="+", type=pathlib.Path)
parser.add_argument("-o", "--output-file", type=pathlib.Path, default="WAD.WAD")
args = parser.parse_args(namespace=ArgNamespace())

if len(args.input_files) > 0x100:
    raise ValueError("too many input files")

with open(args.output_file, mode="wb") as output_file:
    output_file.seek(0x800)
    for i, input_path in enumerate(args.input_files):
        offset = output_file.tell()
        with open(input_path, mode="rb") as input_file:
            shutil.copyfileobj(input_file, output_file)
            size = input_file.tell()
        padding = (0x800 - size % 0x800) % 0x800
        total_size = size + padding
        output_file.write(b"\x00" * padding)
        output_file.seek(i * 8)
        output_file.write(offset.to_bytes(4, "little"))
        output_file.write(total_size.to_bytes(4, "little"))
        output_file.seek(offset + total_size)
