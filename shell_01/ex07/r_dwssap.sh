#/bin/sh

cat /etc/passwd | grep -v ^\# | sed -n 'n;p' | sed -E 's/([^:]+):\*.*/\1/' | rev | sort -r | awk -v s="$FT_LINE1" -v e="$FT_LINE2" 'NR>=s&&NR<=e' | tr -s '\n' "," | sed 's/, */, /g' | sed 's/, $/\./' | tr -d '\n'