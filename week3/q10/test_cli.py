# test_cli.py
import sys
import pytest
from greetlab.cli import main

def test_blank_name_exits_2():
    # 传入只含空白字符的 name，main 应以退出码 2 结束
    with pytest.raises(SystemExit) as excinfo:
        sys.argv = ["sdt-greet", "--name", "   "]
        main()
    assert excinfo.value.code == 2