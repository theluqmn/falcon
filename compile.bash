echo "(1/3) Collecting all C++ files..."
cpp_files=( $(find . -name "*.cpp") )
if [ ${#cpp_files[@]} -eq 0 ]; then
    echo "- No C++ files found"
    exit 1
elif [ ${#cpp_files[@]} -eq 1 ]; then
    echo "- Found 1 C++ file"
else
    echo "- Found ${#cpp_files[@]} C++ files"
fi

echo "(2/3) Compiling..."
compile_time_start=$(date +%s.%N)
g++ -o falcon ${cpp_files[@]} -lsqlite3 -lpthread
compile_time_end=$(date +%s.%N)
compile_time=$(echo "$compile_time_end - $compile_time_start" | bc)
echo "- Compilation took $compile_time seconds"

echo "(3/3) Running..."
echo ""
run_time_start=$(date +%s.%N)
./falcon
run_time_end=$(date +%s.%N)
run_time=$(echo "$run_time_end - $run_time_start" | bc)
echo ""
echo "Run time: $run_time seconds"
