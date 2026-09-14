# ai_log.md
核心提示：修改 greetlab/cli.py，使 --name 只含空白时 main() 以 SystemExit(2) 结束；测试命令 `PYTHONPATH=src pytest`，禁改测试与 pyproject。
智能体改动：parse_args 后新增 `if not a.name.strip(): raise SystemExit(2)` 分支。
人工验证：git diff 确认仅 cli.py 改动；撤销无关修改后 pytest 1 passed。