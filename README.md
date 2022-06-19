# lush

## *very* WIP examples

very conceptual, everything is up for change

```
local scoped_var = "hello"		# behaves similar to `var=val`. managed by a stack
global_var = "hi"				# behaves similar to `export var=val`. managed by a hash table
```

```
for i = 0, 9 do
	local i = math.random 0 9 # equivelant to `math.random(0, 9)`
	echo $i >> lush_file
end

echo "random numbers file:"
cat lush_file

echo -n "delete lush_file? [Y/n] "

local ans = io.read()
if ans ~= "y" or ans ~= "Y" then
	rm lush_file			# your standard coreutils `rm`
	os.remove lush_file		# processed to os.remove("lush_file") and sent to lua
	os.remove("lush_file")	# valid lua
end
```

```
for filename, cx in lush.star() do			# equivelant to a shell `for filename in *`
	echo $filename '-' $cx
end
```

## SHIT TO WORRY ABOUT
- lua strings allow null bytes inside
- being able to access variables as lua values, and shell string variables
- differentiating between lua, shell script, and mixed inputs
- compatibility with more standard shell scripts
- conflicting keywords
- correctly identifying shell stuff and lua stuff
- customizability: plugins & options

