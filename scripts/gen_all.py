"""
Run all the generator scripts.
"""
from pathlib import Path
import sys
import subprocess

def main():
    scripts = [
        'gen_imu_integration_sf.py',
        'gen_quat_interpolation_sf.py',
        'gen_quat_interpolation_wf.py',
    ]
    for name in scripts:
        subprocess.check_call([
            sys.executable,
            str(Path(__file__).parent.absolute() / name)
        ])


if __name__ == '__main__':
    main()
