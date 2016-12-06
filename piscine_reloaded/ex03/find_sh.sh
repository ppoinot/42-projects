find . -name "*.sh" -type f | rev | cut -c 4- | cut -d / -f 1 | rev
