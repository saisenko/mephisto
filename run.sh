rm -rf build/*

cd build
cmake ..
make

cd ..

python3 gui/main.py