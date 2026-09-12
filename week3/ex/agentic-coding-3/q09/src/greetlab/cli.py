# src/greetlab/cli.py
import argparse
import os

def main():
    p = argparse.ArgumentParser()          # 解析器
    p.add_argument("--name", required=True)  # 必填 --name 参数
    a = p.parse_args()                     # 解析命令行，返回命名空间
    print(f"Hello, {a.name}!")             # f-string 插值输出