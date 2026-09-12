# Dockerfile（本地 wheel 版）
FROM python:3.12-slim
COPY greetlab_25020007111-0.1.0-py3-none-any.whl .
RUN pip install --no-cache-dir ./greetlab_25020007111-0.1.0-py3-none-any.whl
ENTRYPOINT ["sdt-greet"]
CMD ["--help"]