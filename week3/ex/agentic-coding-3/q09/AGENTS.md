<!-- week3/ex/agentic-coding-3/q09/AGENTS.md -->
# greetlab 项目约定
- 改完代码必须运行 `PYTHONPATH=src pytest` 并通过。
- 提交前运行 `ruff check .`，不得留下未使用 import。
- 不要修改 `pyproject.toml` 的 name/version。
- 行为约定：`--name` 只含空白字符时必须以退出码 2 结束。