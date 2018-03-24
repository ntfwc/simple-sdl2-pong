#!/usr/bin/python3
import tarfile

OUT_FILE="/tmp/pong.tar.gz"

def main():
    with tarfile.open(OUT_FILE, 'w:gz') as f:
        f.add("build-release/pong", arcname="pong/pong")
        f.add("res", arcname="pong/res")

if __name__ == "__main__":
    main()
