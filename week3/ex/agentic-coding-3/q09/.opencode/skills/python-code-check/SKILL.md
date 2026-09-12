<!-- week3/ex/agentic-coding-3/q09/.opencode/skills/python-code-check/SKILL.md -->
---
name: python-code-check
description: Use when checking changed Python files in greetlab. 对改动过的 .py 跑 ruff 与 pytest，给出问题清单。
---
1. `git diff --name-only` 找出改动的 .py 文件；
2. 对每个文件跑 `ruff check`；
3. 跑 `PYTHONPATH=src pytest`；
4. 汇总问题（`文件:行号` + 建议），**不改文件**。