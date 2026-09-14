# test_cli.py
import sys

import pytest

from greetlab.cli import main


def test_normal_name(capsys):
    # 正常姓名：应输出 "Hello, <name>!\n" 且正常返回
    sys.argv = ["sdt-greet", "--name", "Alice"]
    main()
    captured = capsys.readouterr()
    assert captured.out == "Hello, Alice!\n"


def test_blank_name_exits_2():
    # 空白姓名：应以退出码 2 结束（沿袭第3周 Q10 的行为约定）
    with pytest.raises(SystemExit) as excinfo:
        sys.argv = ["sdt-greet", "--name", "   "]
        main()
    assert excinfo.value.code == 2
