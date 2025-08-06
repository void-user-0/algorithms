compiler="gcc"
debug_flags="-ggdb3"
optimize_flags="-O2 -march=native"

files="main.c linked_list.c"
output_name="linked_list"

$compiler $files $debug_flags -o $output_name
