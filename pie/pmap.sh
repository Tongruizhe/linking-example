# /bin/bash

./test_prog &

# Pay attention to the different position of .text
pmap $!

kill -9 $!
