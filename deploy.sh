rm -rf ./dist
mkdir dist
root=$(pwd)

files="*"
for path in $files; do
	if [ -d "./$path" ]; then
		echo $path
		if [ -f "$path/PROBLEM" ]; then
			cd $path
			echo "is problem"
			rime test
			rime pack
			python3 ../pack.py
			mkdir $root/dist/$path
			cp statement.md $root/dist/$path/
			mv "in" $root/dist/$path/in
			mv "out" $root/dist/$path/out
			cd ..
		fi
	fi
done

# cd dist
# rm -rf .git
# git init
# git checkout -b master
# git add -A
# git commit -m 'deploy'
# git push -f git@github.com:tqkoh/qkproblems.git master:dist
# cd ..
