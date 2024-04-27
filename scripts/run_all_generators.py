"""
Run all the generator scripts.
"""
from pathlib import Path
import sys
import subprocess

def main():
    scripts = [
        'imu_integration.py',
        'quat_interpolation.py'
    ]
    for name in scripts:
        subprocess.check_call([
            sys.executable,
            str(Path(__file__).parent.absolute() / name)
        ])


if __name__ == '__main__':
    main()
