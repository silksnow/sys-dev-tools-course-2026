# communication.md

## Issue（重写）
标题：sdt-greet 对空白 --name 仍输出问候并以 0 退出

环境：Linux / Python 3.13（Windows 是否可复现待确认）

复现：
    sdt-greet --name " "

期望结果：以非零退出码结束，不输出问候语。
实际结果：输出 "Hello,  !" 并以退出码 0 结束。

## 提交信息（重写）
标题：Validate --name to reject blank names

正文：--name 只含空白时仍输出问候并以 0 退出，调用方无法判错。
     在 parse_args 后校验 a.name.strip()，为空则 p.error(...) 以退出码 2 结束。

## 评审意见（重写）
[Blocking] 新增校验缺少对应测试，需补空白与空串两个用例。
[Nit] 错误消息建议统一格式，便于断言。
[Suggestion] 可复用 argparse type 校验，逻辑更内聚。