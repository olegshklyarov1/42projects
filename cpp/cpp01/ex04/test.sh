#!/bin/bash

make > /dev/null || exit 1

check()
{
	local name="$1" expected="$2"
	local got
	got=$(cat test.txt.replace 2>/dev/null)
	if [ "$got" == "$expected" ]; then
		echo "[OK]   $name"
	else
		echo "[FAIL] $name (got: '$got')"
	fi
}

printf 'hello world hello' > test.txt
./sed test.txt hello bye
check "simple" "bye world bye"

printf 'aaaa' > test.txt
./sed test.txt aa b
check "chevauchement" "bb"

printf 'abc' > test.txt
./sed test.txt b bb
check "s2 contient s1" "abbc"

printf 'abc' > test.txt
./sed test.txt b ""
check "s2 vide" "ac"

printf 'abc' > test.txt
./sed test.txt xyz 123
check "s1 absent" "abc"

printf '' > test.txt
./sed test.txt a b
check "fichier vide" ""

printf 'line1\nline2\n' > test.txt
./sed test.txt "$(printf 'line1\nline2')" X
check "s1 avec retour ligne" "X"

echo "--- erreurs (doivent afficher un message) ---"
./sed
./sed nofile.txt a b
./sed test.txt "" b

rm -f test.txt test.txt.replace