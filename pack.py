# coding: utf-8

import os
import shutil


def main():
    cd = os.getcwd()
    print(cd)
    if os.path.exists(cd + "/in"):
        shutil.rmtree(cd + "/in")
    if os.path.exists(cd + "/out"):
        shutil.rmtree(cd + "/out")
    shutil.move(cd + "/rime-out/atcoder/in", cd + "/in")
    shutil.move(cd + "/rime-out/atcoder/out", cd + "/out")
    os.chdir("in")
    cd = os.getcwd()
    files = os.listdir(cd)
    for f in files:
        if os.path.isfile(f):
            shutil.move(f, f + ".in")
    os.chdir("../out")
    cd = os.getcwd()
    files = os.listdir(cd)
    for f in files:
        if os.path.isfile(f):
            shutil.move(f, f + ".out")


if __name__ == "__main__":
    main()
