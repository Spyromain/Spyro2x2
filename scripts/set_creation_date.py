import argparse
import ctypes
import ctypes.wintypes
import datetime
import pathlib


class ArgNamespace:
    input_file: pathlib.Path
    creation_date: datetime.datetime

parser = argparse.ArgumentParser()
parser.add_argument("input_file", type=pathlib.Path)
parser.add_argument("creation_date", type=datetime.datetime.fromisoformat)
args = parser.parse_args(namespace=ArgNamespace())

# Convert Unix timestamp to Windows FileTime using some magic numbers
# See documentation: https://support.microsoft.com/en-us/help/167296
epoch = args.creation_date.timestamp()
timestamp = int((epoch * 10000000) + 116444736000000000)
ctime = ctypes.wintypes.FILETIME(timestamp & 0xFFFFFFFF, timestamp >> 32)

# Call Win32 API to modify the file creation date
handle = ctypes.windll.kernel32.CreateFileW(str(args.input_file), 256, 0, None, 4, 128, None)
ctypes.windll.kernel32.SetFileTime(handle, ctypes.byref(ctime), ctypes.byref(ctime), ctypes.byref(ctime))
ctypes.windll.kernel32.CloseHandle(handle)
