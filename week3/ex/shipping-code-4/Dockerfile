# Dockerfile
FROM python:3.12-slim                 
# 用 slim 轻量镜像，而非完整版
WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt   
# 装依赖（清理缓存减小体积）
COPY app.py .
CMD ["python", "app.py"]              
# 容器启动时跑应用