# memo

## new problem
```
rime add . problem <name>
cd <name>
rime add . solution sol_tqk
```
main.cpp をコメントアウト --std=c++17, -O2
```
rime add . tests
```
generator と validator をコメントアウト cpp
constraints.hpp も作り制約を入れる

## test
```
rime test && rime pack && python3 ../pack.py
```
