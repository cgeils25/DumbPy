echo "Building DumbPy binaries..."

cmake . &&

make &&

mkdir -p bin &&

mv *.so bin &&

export PYTHONPATH="${PYTHONPATH}:bin/" &&

echo "
DumbPy binary built and moved to bin directory. DumbPy can now be imported with 

>>>'import dumbpy as dp'

>>> dp.say_hello('Your Name')
"