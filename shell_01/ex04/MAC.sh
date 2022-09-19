ifconfig -a | grep 'ether ' | sed 's/^.......//' | tr -d ' '
