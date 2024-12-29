grep -o 'mul([0-9][0-9]*,[0-9][0-9]*)\|do()\|don'"'"'t()' 3a.txt | tr "(),mul" ' ' | awk 'BEGIN { use = 1; sum = 0; }
$1 ~ /do$/ { use = 1; } $1 ~ /don/ { use = 0; } { if (use) { sum += $1 * $2; } } END { print sum; } '
