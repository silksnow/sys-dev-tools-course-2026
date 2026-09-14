# src/greetlab/cli.py
import argparse


def main():
    p = argparse.ArgumentParser()  # 解析器
    p.add_argument("--name", required=True)  # 必填 --name 参数
    a = p.parse_args()  # 解析命令行，返回命名空间
    if not a.name.strip():  # 只含空白字符时退出
        raise SystemExit(2)
    print(f"Hello, {a.name}!")  # f-string 插值输出
