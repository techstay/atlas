ls | select name size
ls | select name size | sort-by size | first 5 | skip 2
# 选择第一行
ls | select 0
