rm -rf build/*

cd build || exit
cmake ..
make

cd ..

python3 gui/main.py || python gui/main.py