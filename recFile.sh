foo (){
	
	for i in $1
	do
		if [ -f "$i" ]; then
			echo "$i"
		else
			foo $i
		fi
	done
}

foo $1
