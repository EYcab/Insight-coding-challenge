#! /bin/bash

chmod a+x count.py
chmod a+x median.py

python count.py ./wc_input ./wc_output/wc_result.txt
python median.py ./wc_input ./wc_output/median_result.txt
