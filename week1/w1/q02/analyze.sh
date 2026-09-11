#!/bin/bash
file="${1:-}"
if [[ -z "$file" ]]; then
 echo "用法: $0 <csv文件>" >&2
 exit 2
fi
if [[ ! -f "$file" ]]; then
 echo "错误: 文件不存在: $file" >&2
 exit 1
fi
echo "HTTP 5xx 最多的前 2 个 path："
awk -F, 'NR>1 && $4 ~ /^5/ {c[$3]++} END {for (p in c) print c[p], p}' "$file" \
| sort -k1,1nr -k2,2 \
| head -n 2 \
| awk '{print $2}'
echo -n "平均 latency_ms："
awk -F, 'NR>1 {sum+=$5; n++} END {printf "%.2f\n", sum/n}' "$file"
