file(REMOVE_RECURSE
  "tester-sol"
  "tester-sol.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/tester-sol.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
