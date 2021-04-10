./b2008r1a < B-small-attempt0.in | bc -l | fgrep . | awk -F. ' { print $1 } ' |
sed -e 's/^/00000/'  | ./bb2008r1a
