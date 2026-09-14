#!/usr/bin/env bash
set -euo pipefail

curl -fsS http://127.0.0.1:8000/packages.json \
  | jq -r '[.[] | select(.status == "active" and .downloads >= 100)]
           | sort_by([-.downloads, .name])
           | ["# Active Packages", "", "| name | version | downloads |", "| --- | --- | --- |"]
             + map("| \(.name) | \(.version) | \(.downloads) |")
           | .[]' \
  > summary.md