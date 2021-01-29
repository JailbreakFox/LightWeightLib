#!/bin/bash

# 单元测试覆盖率生成脚本

build_dir=. # 编译路径
 
result_coverage_dir=$build_dir/coverage
 
lcov -d $build_dir -b $build_dir -c -o $build_dir/coverage.info
lcov --remove  $build_dir/coverage.info  '/usr/include/*' '/usr/lib/*' '*/tests/*' -o $build_dir/coverage_filter.info

# 生成报告 
genhtml -o $result_coverage_dir $build_dir/coverage_filter.info

# 打开报告
nohup x-www-browser $result_coverage_dir/index.html &

exit 0